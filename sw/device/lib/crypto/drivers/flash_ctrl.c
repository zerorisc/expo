// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "sw/device/lib/crypto/drivers/flash_ctrl.h"

#include "sw/device/lib/base/abs_mmio.h"
#include "sw/device/lib/base/bitfield.h"
#include "sw/device/lib/base/hardened.h"
#include "sw/device/lib/base/macros.h"
#include "sw/device/lib/base/memory.h"
#include "sw/device/lib/base/multibits.h"
#include "sw/device/lib/crypto/impl/status.h"
#include "sw/device/lib/runtime/log.h"

#include "hw/top/flash_ctrl_regs.h"
#include "hw/top_earlgrey/sw/autogen/top_earlgrey.h"

// Module ID for status codes.
#define MODULE_ID MAKE_MODULE_ID('d', 'f', 'c')

enum {
  /**
   * Base address of the flash_ctrl registers.
   */
  kBase = TOP_EARLGREY_FLASH_CTRL_CORE_BASE_ADDR,
  /**
   * Page offset for attestation key seeds.
   */
  kAttestationKeySeedsPageOffset = 4,
};

status_t flash_ctrl_cdi1_seed_read(uint32_t *dst) {
  // Set the address. Assumes that the page is in info bank 0, so bank offset is
  // 0.
  abs_mmio_write32(
      kBase + FLASH_CTRL_ADDR_REG_OFFSET,
      kAttestationKeySeedsPageOffset * FLASH_CTRL_PARAM_BYTES_PER_PAGE);

  // Set the control register (bank 0, read operation)
  uint32_t ctrl = bitfield_bit32_write(0, FLASH_CTRL_CONTROL_START_BIT, true);
  ctrl = bitfield_field32_write(ctrl, FLASH_CTRL_CONTROL_OP_FIELD,
                                FLASH_CTRL_CONTROL_OP_VALUE_READ);
  ctrl = bitfield_bit32_write(ctrl, FLASH_CTRL_CONTROL_PARTITION_SEL_BIT, true);
  ctrl = bitfield_field32_write(ctrl, FLASH_CTRL_CONTROL_INFO_SEL_FIELD, 0);
  ctrl = bitfield_bit32_write(ctrl, FLASH_CTRL_CONTROL_ERASE_SEL_BIT, false);
  ctrl = bitfield_field32_write(ctrl, FLASH_CTRL_CONTROL_NUM_FIELD,
                                kFlashCtrlAttestationKeySeedWords - 1),
  abs_mmio_write32(kBase + FLASH_CTRL_CONTROL_REG_OFFSET, ctrl);

  // Read the result from the FIFO.
  size_t word_count = kFlashCtrlAttestationKeySeedWords;
  size_t i = 0, r = word_count - 1;
  for (; launder32(i) < word_count && launder32(r) < word_count; ++i, --r) {
    write_32(abs_mmio_read32(kBase + FLASH_CTRL_RD_FIFO_REG_OFFSET), dst);
    dst++;
  }
  HARDENED_CHECK_EQ(i, word_count);
  HARDENED_CHECK_EQ(r, SIZE_MAX);

  // Wait for the operation to complete.
  uint32_t op_status;
  do {
    op_status = abs_mmio_read32(kBase + FLASH_CTRL_OP_STATUS_REG_OFFSET);
  } while (!bitfield_bit32_read(op_status, FLASH_CTRL_OP_STATUS_DONE_BIT));
  abs_mmio_write32(kBase + FLASH_CTRL_OP_STATUS_REG_OFFSET, 0u);

  if (bitfield_bit32_read(op_status, FLASH_CTRL_OP_STATUS_ERR_BIT)) {
    return OTCRYPTO_RECOV_ERR;
  }
  return OTCRYPTO_OK;
}
