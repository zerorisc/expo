// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
#ifndef OPENTITAN_SW_DEVICE_LIB_CRYPTO_DRIVERS_FLASH_CTRL_H_
#define OPENTITAN_SW_DEVICE_LIB_CRYPTO_DRIVERS_FLASH_CTRL_H_

#include "sw/device/lib/base/bitfield.h"
#include "sw/device/lib/base/hardened.h"
#include "sw/device/lib/base/multibits.h"
#include "sw/device/lib/crypto/impl/status.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
  /**
   * Size of the attestation seed in words.
   */
  kFlashCtrlAttestationKeySeedWords = 320 / 32,
};

/**
 * Reads the CDI1 attestation key seed from flash.
 *
 * The buffer for the seed data must be at least
 * `kFlashCtrlAttestationKeySeedWords` words long.
 *
 * @param[out] dst Buffer to store the read data.
 * @return Result of the operation.
 */
OT_WARN_UNUSED_RESULT
status_t flash_ctrl_cdi1_seed_read(uint32_t *dst);

#ifdef __cplusplus
}
#endif

#endif  // OPENTITAN_SW_DEVICE_LIB_CRYPTO_DRIVERS_FLASH_CTRL_H_
