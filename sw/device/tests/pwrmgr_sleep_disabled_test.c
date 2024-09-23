// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "sw/device/lib/testing/test_framework/check.h"
#include "sw/device/lib/testing/test_framework/ottf_main.h"
#include "sw/ip/aon_timer/dif/dif_aon_timer.h"
#include "sw/ip/aon_timer/test/utils/aon_timer_testutils.h"
#include "sw/ip/pwrmgr/dif/dif_pwrmgr.h"
#include "sw/ip/pwrmgr/test/utils/pwrmgr_testutils.h"
#include "sw/ip/rv_plic/dif/dif_rv_plic.h"
#include "sw/lib/sw/device/base/mmio.h"
#include "sw/lib/sw/device/runtime/irq.h"
#include "sw/lib/sw/device/runtime/log.h"

#include "hw/top_darjeeling/sw/autogen/top_darjeeling.h"

OTTF_DEFINE_TEST_CONFIG();

static const uint32_t kPlicTarget = kTopDarjeelingPlicTargetIbex0;
static dif_aon_timer_t aon_timer;
static dif_rv_plic_t plic;

// Volatile globals accessed from the ISR.
static volatile dif_aon_timer_irq_t irq;
static volatile top_darjeeling_plic_peripheral_t peripheral;
static volatile bool interrupt_serviced;
static volatile bool interrupt_failed;

bool is_pwrmgr_irq_pending(void) {
  bool status;
  CHECK_DIF_OK(dif_rv_plic_irq_is_pending(
      &plic, kTopDarjeelingPlicIrqIdPwrmgrAonWakeup, &status));
  return status;
}

/**
 * External interrupt handler.
 */
void ottf_external_isr(void) {
  dif_rv_plic_irq_id_t irq_id;
  if (is_pwrmgr_irq_pending()) {
    interrupt_failed = true;
    return;
  }

  CHECK_DIF_OK(dif_rv_plic_irq_claim(&plic, kPlicTarget, &irq_id));
  if (irq_id != kTopDarjeelingPlicIrqIdAonTimerAonWkupTimerExpired) {
    interrupt_failed = true;
    return;
  }

  peripheral = (top_darjeeling_plic_peripheral_t)
      top_darjeeling_plic_interrupt_for_peripheral[irq_id];

  if (peripheral == kTopDarjeelingPlicPeripheralAonTimerAon) {
    irq =
        (dif_aon_timer_irq_t)(irq_id -
                              (dif_rv_plic_irq_id_t)
                                  kTopDarjeelingPlicIrqIdAonTimerAonWkupTimerExpired);

    CHECK_DIF_OK(dif_aon_timer_wakeup_stop(&aon_timer));
    CHECK_DIF_OK(dif_aon_timer_irq_acknowledge(&aon_timer, irq));
  } else {
    interrupt_failed = true;
    return;
  }

  // Complete the IRQ by writing the IRQ source to the Ibex specific CC.
  // register
  CHECK_DIF_OK(dif_rv_plic_irq_complete(&plic, kPlicTarget, irq_id));
  interrupt_serviced = true;
  interrupt_failed = false;
}

bool test_main(void) {
  dif_pwrmgr_t pwrmgr;

  // Issue a wakeup signal in 200us through the AON timer.
  //
  // At 62.5MHz, threshold of 12500 is equal to 200us.
  //
  // Adjust the threshold for Verilator since it runs on different clock
  // frequencies.
  uint32_t wakeup_threshold = 12500;
  if (kDeviceType == kDeviceSimVerilator) {
    wakeup_threshold *= 10;
  }

  interrupt_serviced = false;
  interrupt_failed = true;

  // Initialize unit difs.
  CHECK_DIF_OK(dif_pwrmgr_init(
      mmio_region_from_addr(TOP_DARJEELING_PWRMGR_AON_BASE_ADDR), &pwrmgr));
  CHECK_DIF_OK(dif_aon_timer_init(
      mmio_region_from_addr(TOP_DARJEELING_AON_TIMER_AON_BASE_ADDR),
      &aon_timer));
  CHECK_DIF_OK(dif_rv_plic_init(
      mmio_region_from_addr(TOP_DARJEELING_RV_PLIC_BASE_ADDR), &plic));

  // Notice we are clearing rstmgr's RESET_INFO, so after the aon wakeup there
  // is only one bit set.
  if (UNWRAP(pwrmgr_testutils_is_wakeup_reason(&pwrmgr, 0)) == true) {
    LOG_INFO("POR reset");

    CHECK_STATUS_OK(
        aon_timer_testutils_wakeup_config(&aon_timer, wakeup_threshold));
    // Enable aon wakeup.
    CHECK_DIF_OK(dif_pwrmgr_set_request_sources(
        &pwrmgr, kDifPwrmgrReqTypeWakeup, kDifPwrmgrWakeupRequestSourceThree,
        kDifToggleEnabled));
    LOG_INFO("Enabled aon wakeup");

    // Enable the AON wakeup interrupt.
    CHECK_DIF_OK(dif_rv_plic_irq_set_enabled(
        &plic, kTopDarjeelingPlicIrqIdAonTimerAonWkupTimerExpired, kPlicTarget,
        kDifToggleEnabled));
    LOG_INFO("Enabled aon wakeup interrupt");
    CHECK_DIF_OK(dif_rv_plic_irq_set_priority(
        &plic, kTopDarjeelingPlicIrqIdAonTimerAonWkupTimerExpired, 3));
    LOG_INFO("Set aon wakeup interrupt priority");

    // Enable pwrmgr wakeup interrupt, so it triggers an interrupt even though
    // it should not.
    CHECK_DIF_OK(dif_pwrmgr_irq_set_enabled(&pwrmgr, kDifPwrmgrIrqWakeup,
                                            kDifToggleEnabled));
    CHECK_DIF_OK(dif_rv_plic_irq_set_enabled(
        &plic, kTopDarjeelingPlicIrqIdPwrmgrAonWakeup, kPlicTarget,
        kDifToggleEnabled));
    LOG_INFO("Enabled pwrmgr wakeup interrupt");
    CHECK_DIF_OK(dif_rv_plic_irq_set_priority(
        &plic, kTopDarjeelingPlicIrqIdPwrmgrAonWakeup, 3));
    LOG_INFO("Set pwrmgr wakeup interrupt priority");

    // Prepare for interrupt.
    LOG_INFO("Issue WFI without sleep");
    irq_global_ctrl(true);
    irq_external_ctrl(true);
    wait_for_interrupt();

    // Check that interrupt was serviced correctly.
    CHECK(interrupt_serviced);
    CHECK(!interrupt_failed);
    LOG_INFO("The interrupt was processed");
    // And to be extra safe, check there is no pwrmgr interrupt pending.
    CHECK(!is_pwrmgr_irq_pending());

    return true;

  } else if (UNWRAP(pwrmgr_testutils_is_wakeup_reason(
                 &pwrmgr, kDifPwrmgrWakeupRequestSourceThree)) == true) {
    LOG_ERROR("Unexpected wakeup reset");
    return false;
  }

  return false;
}
