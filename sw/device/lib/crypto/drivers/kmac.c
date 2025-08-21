// Copyright zeroRISC Inc.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "sw/device/lib/crypto/drivers/kmac.h"

#include "sw/device/lib/base/abs_mmio.h"
#include "sw/device/lib/base/bitfield.h"
#include "sw/device/lib/base/hardened_memory.h"
#include "sw/device/lib/base/memory.h"
#include "sw/device/lib/crypto/drivers/entropy.h"
#include "sw/device/lib/crypto/drivers/rv_core_ibex.h"
#include "sw/device/lib/crypto/impl/status.h"

#include "hw/top/kmac_regs.h"  // Generated.
#include "hw/top_earlgrey/sw/autogen/top_earlgrey.h"

// Module ID for status codes.
#define MODULE_ID MAKE_MODULE_ID('d', 'k', 'c')

/**
 * Security strength values.
 *
 * These values corresponds to the half of the capacity of Keccak permutation.
 *
 * Hardened values generated with:
 * $ ./util/design/sparse-fsm-encode.py -d 6 -m 5 -n 11 \
 *   --avoid-zero -s 4008005493
 */
typedef enum kmac_security_str {
  kKmacSecurityStrength128 = 0x3e5,
  kKmacSecurityStrength224 = 0x639,
  kKmacSecurityStrength256 = 0x5cb,
  kKmacSecurityStrength384 = 0x536,
  kKmacSecurityStrength512 = 0x25e,
} kmac_security_str_t;

/**
 * List of supported KMAC modes.
 *
 * Hardened values generated with:
 * $ ./util/design/sparse-fsm-encode.py -d 6 -m 4 -n 11 \
 *     --avoid-zero -s 3610353144
 */
typedef enum kmac_operation {
  kKmacOperationSha3 = 0x5ca,
  kKmacOperationShake = 0x369,
  kKmacOperationCshake = 0x5b5,
  kKmacOperationKmac = 0x60f,
} kmac_operation_t;

enum {
  kKmacPrefixRegCount = KMAC_PREFIX_MULTIREG_COUNT,
  kKmacBaseAddr = TOP_EARLGREY_KMAC_BASE_ADDR,
  kKmacKeyShare0Addr = kKmacBaseAddr + KMAC_KEY_SHARE0_0_REG_OFFSET,
  kKmacKeyShare1Addr = kKmacBaseAddr + KMAC_KEY_SHARE1_0_REG_OFFSET,
  kKmacStateShareSize = KMAC_STATE_SIZE_BYTES / 2,
  kKmacStateShare0Addr = kKmacBaseAddr + KMAC_STATE_REG_OFFSET,
  kKmacStateShare1Addr =
      kKmacBaseAddr + KMAC_STATE_REG_OFFSET + kKmacStateShareSize,
};

// "KMAC" string in little endian
static const uint8_t kKmacFuncNameKMAC[] = {0x4b, 0x4d, 0x41, 0x43};

// We need 5 bytes at most for encoding the length of cust_str and func_name.
// That leaves 39 bytes for the string. We simply truncate it to 36 bytes.
OT_ASSERT_ENUM_VALUE(kKmacPrefixMaxSize, 4 * KMAC_PREFIX_MULTIREG_COUNT - 8);
OT_ASSERT_ENUM_VALUE(kKmacCustStrMaxSize, kKmacPrefixMaxSize - 4);

// Check that KEY_SHARE registers form a continuous address space
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_1_REG_OFFSET,
                     KMAC_KEY_SHARE0_0_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_2_REG_OFFSET,
                     KMAC_KEY_SHARE0_1_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_3_REG_OFFSET,
                     KMAC_KEY_SHARE0_2_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_4_REG_OFFSET,
                     KMAC_KEY_SHARE0_3_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_5_REG_OFFSET,
                     KMAC_KEY_SHARE0_4_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_6_REG_OFFSET,
                     KMAC_KEY_SHARE0_5_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_7_REG_OFFSET,
                     KMAC_KEY_SHARE0_6_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_8_REG_OFFSET,
                     KMAC_KEY_SHARE0_7_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_9_REG_OFFSET,
                     KMAC_KEY_SHARE0_8_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_10_REG_OFFSET,
                     KMAC_KEY_SHARE0_9_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_11_REG_OFFSET,
                     KMAC_KEY_SHARE0_10_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_12_REG_OFFSET,
                     KMAC_KEY_SHARE0_11_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_13_REG_OFFSET,
                     KMAC_KEY_SHARE0_12_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_14_REG_OFFSET,
                     KMAC_KEY_SHARE0_13_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE0_15_REG_OFFSET,
                     KMAC_KEY_SHARE0_14_REG_OFFSET + 4);

OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_1_REG_OFFSET,
                     KMAC_KEY_SHARE1_0_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_2_REG_OFFSET,
                     KMAC_KEY_SHARE1_1_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_3_REG_OFFSET,
                     KMAC_KEY_SHARE1_2_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_4_REG_OFFSET,
                     KMAC_KEY_SHARE1_3_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_5_REG_OFFSET,
                     KMAC_KEY_SHARE1_4_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_6_REG_OFFSET,
                     KMAC_KEY_SHARE1_5_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_7_REG_OFFSET,
                     KMAC_KEY_SHARE1_6_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_8_REG_OFFSET,
                     KMAC_KEY_SHARE1_7_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_9_REG_OFFSET,
                     KMAC_KEY_SHARE1_8_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_10_REG_OFFSET,
                     KMAC_KEY_SHARE1_9_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_11_REG_OFFSET,
                     KMAC_KEY_SHARE1_10_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_12_REG_OFFSET,
                     KMAC_KEY_SHARE1_11_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_13_REG_OFFSET,
                     KMAC_KEY_SHARE1_12_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_14_REG_OFFSET,
                     KMAC_KEY_SHARE1_13_REG_OFFSET + 4);
OT_ASSERT_ENUM_VALUE(KMAC_KEY_SHARE1_15_REG_OFFSET,
                     KMAC_KEY_SHARE1_14_REG_OFFSET + 4);

// Ensure each PREFIX register is 4 bytes
OT_ASSERT_ENUM_VALUE(32, KMAC_PREFIX_PREFIX_FIELD_WIDTH);

/**
 * Determine the Keccak rate from the current hardware configuration.
 *
 * Returns 0 if the strength configured in the hardware is invalid, which
 * should not happen; the caller must check this value.
 *
 * @return The keccak rate in 32-bit words.
 */
static size_t kmac_get_keccak_rate_words(void) {
  uint32_t cfg_reg =
      abs_mmio_read32(kKmacBaseAddr + KMAC_CFG_SHADOWED_REG_OFFSET);
  uint32_t kstrength =
      bitfield_field32_read(cfg_reg, KMAC_CFG_SHADOWED_KSTRENGTH_FIELD);
  switch (kstrength) {
    case KMAC_CFG_SHADOWED_KSTRENGTH_VALUE_L128:
      return (1600 - 2 * 128) / 32;
    case KMAC_CFG_SHADOWED_KSTRENGTH_VALUE_L224:
      return (1600 - 2 * 224) / 32;
    case KMAC_CFG_SHADOWED_KSTRENGTH_VALUE_L256:
      return (1600 - 2 * 256) / 32;
    case KMAC_CFG_SHADOWED_KSTRENGTH_VALUE_L384:
      return (1600 - 2 * 384) / 32;
    case KMAC_CFG_SHADOWED_KSTRENGTH_VALUE_L512:
      return (1600 - 2 * 512) / 32;
    default:
      return 0;
  }
}

/**
 * Get the KEY_LEN register value for the given length.
 *
 * Returns an error if the key length is not supported.
 *
 * @param key_len The size of the key in bytes.
 * @param[out] reg KEY_LEN register value (pointer cannot be NULL).
 * @return Error code.
 */
static_assert(KMAC_KEY_LEN_LEN_OFFSET == 0,
              "Code assumes that length field is at offset 0.");
OT_WARN_UNUSED_RESULT
static status_t key_len_reg_get(size_t key_len, uint32_t *key_len_reg) {
  *key_len_reg = 0;
  switch (launder32(key_len)) {
    case 128 / 8:
      HARDENED_CHECK_EQ(key_len * 8, 128);
      *key_len_reg = KMAC_KEY_LEN_LEN_VALUE_KEY128;
      break;
    case 192 / 8:
      HARDENED_CHECK_EQ(key_len * 8, 192);
      *key_len_reg = KMAC_KEY_LEN_LEN_VALUE_KEY192;
      break;
    case 256 / 8:
      HARDENED_CHECK_EQ(key_len * 8, 256);
      *key_len_reg = KMAC_KEY_LEN_LEN_VALUE_KEY256;
      break;
    case 384 / 8:
      HARDENED_CHECK_EQ(key_len * 8, 384);
      *key_len_reg = KMAC_KEY_LEN_LEN_VALUE_KEY384;
      break;
    case 512 / 8:
      HARDENED_CHECK_EQ(key_len * 8, 512);
      *key_len_reg = KMAC_KEY_LEN_LEN_VALUE_KEY512;
      break;
    default:
      return OTCRYPTO_BAD_ARGS;
  }
  HARDENED_CHECK_NE(key_len_reg, 0);
  return OTCRYPTO_OK;
}

status_t kmac_key_length_check(size_t key_len) {
  uint32_t key_len_reg;
  // Run the conversion to the key length register, but we only care about the
  // error code.
  return key_len_reg_get(key_len, &key_len_reg);
}

status_t kmac_hwip_default_configure(void) {
  // Ensure that the entropy complex is initialized.
  HARDENED_TRY(entropy_complex_check());

  uint32_t status_reg = abs_mmio_read32(kKmacBaseAddr + KMAC_STATUS_REG_OFFSET);

  // Check that core is not in fault state
  if (bitfield_bit32_read(status_reg, KMAC_STATUS_ALERT_FATAL_FAULT_BIT)) {
    return OTCRYPTO_FATAL_ERR;
  }
  if (bitfield_bit32_read(status_reg,
                          KMAC_STATUS_ALERT_RECOV_CTRL_UPDATE_ERR_BIT)) {
    return OTCRYPTO_RECOV_ERR;
  }
  // Check that core is not busy
  if (!bitfield_bit32_read(status_reg, KMAC_STATUS_SHA3_IDLE_BIT)) {
    return OTCRYPTO_RECOV_ERR;
  }

  // Check that there is no err pending in intr state
  uint32_t intr_state =
      abs_mmio_read32(kKmacBaseAddr + KMAC_INTR_STATE_REG_OFFSET);
  if (bitfield_bit32_read(intr_state, KMAC_INTR_STATE_KMAC_ERR_BIT)) {
    return OTCRYPTO_RECOV_ERR;
  }

  // Check CFG.regwen
  uint32_t cfg_regwen =
      abs_mmio_read32(kKmacBaseAddr + KMAC_CFG_REGWEN_REG_OFFSET);
  if (!bitfield_bit32_read(cfg_regwen, KMAC_CFG_REGWEN_EN_BIT)) {
    return OTCRYPTO_RECOV_ERR;
  }

  // Keep err interrupt disabled
  uint32_t intr_reg = KMAC_INTR_ENABLE_REG_RESVAL;
  intr_reg = bitfield_bit32_write(intr_reg, KMAC_INTR_ENABLE_KMAC_ERR_BIT, 0);
  abs_mmio_write32(kKmacBaseAddr + KMAC_INTR_ENABLE_REG_OFFSET, intr_reg);

  // Configure max for entropy period (use UINT32_MAX and let bitfield clamp
  // them to their bitfield)
  uint32_t entropy_period = KMAC_ENTROPY_PERIOD_REG_RESVAL;
  entropy_period = bitfield_field32_write(
      entropy_period, KMAC_ENTROPY_PERIOD_PRESCALER_FIELD, UINT32_MAX);
  entropy_period = bitfield_field32_write(
      entropy_period, KMAC_ENTROPY_PERIOD_WAIT_TIMER_FIELD, UINT32_MAX);
  abs_mmio_write32(kKmacBaseAddr + KMAC_ENTROPY_PERIOD_REG_OFFSET,
                   entropy_period);

  // Configure max for hash threshold (use UINT32_MAX and let bitfield clamp
  // them to their bitfield)
  uint32_t entropy_hash_threshold =
      KMAC_ENTROPY_REFRESH_THRESHOLD_SHADOWED_REG_RESVAL;
  entropy_hash_threshold = bitfield_field32_write(
      entropy_hash_threshold,
      KMAC_ENTROPY_REFRESH_THRESHOLD_SHADOWED_THRESHOLD_FIELD, UINT32_MAX);
  abs_mmio_write32(
      kKmacBaseAddr + KMAC_ENTROPY_REFRESH_THRESHOLD_SHADOWED_REG_OFFSET,
      entropy_hash_threshold);

  // Configure CFG
  uint32_t cfg_reg = KMAC_CFG_SHADOWED_REG_RESVAL;
  // Little_endian
  cfg_reg =
      bitfield_bit32_write(cfg_reg, KMAC_CFG_SHADOWED_MSG_ENDIANNESS_BIT, 0);
  cfg_reg =
      bitfield_bit32_write(cfg_reg, KMAC_CFG_SHADOWED_STATE_ENDIANNESS_BIT, 0);

  // Sideload: off, default key comes from SW
  cfg_reg = bitfield_bit32_write(cfg_reg, KMAC_CFG_SHADOWED_SIDELOAD_BIT, 0);

  // Entropy mode: EDN
  cfg_reg =
      bitfield_field32_write(cfg_reg, KMAC_CFG_SHADOWED_ENTROPY_MODE_FIELD,
                             KMAC_CFG_SHADOWED_ENTROPY_MODE_VALUE_EDN_MODE);

  // Use quality randomness for message blocks too
  cfg_reg = bitfield_bit32_write(cfg_reg,
                                 KMAC_CFG_SHADOWED_ENTROPY_FAST_PROCESS_BIT, 1);
  // Do not remask message blocks
  cfg_reg = bitfield_bit32_write(cfg_reg, KMAC_CFG_SHADOWED_MSG_MASK_BIT, 0);

  // Mark entropy source as ready
  cfg_reg =
      bitfield_bit32_write(cfg_reg, KMAC_CFG_SHADOWED_ENTROPY_READY_BIT, 1);
  // Unsupported modes: disabled
  cfg_reg = bitfield_bit32_write(
      cfg_reg, KMAC_CFG_SHADOWED_EN_UNSUPPORTED_MODESTRENGTH_BIT, 0);

  abs_mmio_write32_shadowed(kKmacBaseAddr + KMAC_CFG_SHADOWED_REG_OFFSET,
                            cfg_reg);

  return OTCRYPTO_OK;
}

/**
 * Wait until given status bit is set.
 *
 * Loops until the `bit_position` of status register reaches the value
 * `bit_value`.
 * @param bit_position The bit position in the status register.
 * @param bit_value Whether it should wait for 0 or 1.
 * @return Error status.
 */
OT_WARN_UNUSED_RESULT
static status_t wait_status_bit(uint32_t bit_position, bool bit_value) {
  if (bit_position > 31) {
    return OTCRYPTO_BAD_ARGS;
  }

  while (true) {
    uint32_t reg = abs_mmio_read32(kKmacBaseAddr + KMAC_STATUS_REG_OFFSET);
    if (bitfield_bit32_read(reg, KMAC_STATUS_ALERT_FATAL_FAULT_BIT)) {
      return OTCRYPTO_FATAL_ERR;
    }
    if (bitfield_bit32_read(reg, KMAC_STATUS_ALERT_RECOV_CTRL_UPDATE_ERR_BIT)) {
      return OTCRYPTO_RECOV_ERR;
    }
    if (bitfield_bit32_read(reg, bit_position) == bit_value) {
      return OTCRYPTO_OK;
    }
  }
}

/**
 * Encode a given integer as byte array and return its size along with it.
 *
 * This is a common procedure that can be used to implement both `left_encode`
 * and `right_encode` functions defined in NIST SP 800-185. Given an integer
 * `value` it returns its encoding as a byte array in `encoding_buf`. Meanwhile,
 * `encoding_header` keeps the size of `encoding_buf`. Later the two can be
 * combined as below:
 *
 * left_encode(`value`) = `encoding_header` || `encoding_buf`
 * right_encode(`value`) = `encoding_buf` || `encoding_header`
 *
 * The caller must ensure that `encoding_buf` and `encoding_header` are not
 * NULL pointers. This is not checked within this function.
 *
 * The maximum `value` that can be encoded is restricted to the maximum value
 * that can be stored with `size_t` type.
 *
 * @param value Integer to be encoded.
 * @param[out] encoding_buf The output byte array representing `value`.
 * @param[out] encoding_header The number of bytes written to `encoded_value`.
 * @return Error code.
 */
OT_WARN_UNUSED_RESULT
static status_t little_endian_encode(size_t value, uint8_t *encoding_buf,
                                     uint8_t *encoding_header) {
  uint8_t len = 0;
  uint8_t reverse_buf[sizeof(size_t)];
  do {
    reverse_buf[len] = value & UINT8_MAX;
    value >>= 8;
    len++;
  } while (value > 0);
  *encoding_header = len;

  for (size_t idx = 0; idx < len; idx++) {
    encoding_buf[idx] = reverse_buf[len - 1 - idx];
  }

  return OTCRYPTO_OK;
}

/**
 * Set prefix registers.
 *
 * This function directly writes to PREFIX registers of KMAC HWIP.
 * The combined size of customization string and the function name
 * must not exceed `kKmacPrefixMaxSize`.
 *
 * @param func_name Function name input in cSHAKE.
 * @param cust_str Customization string input in cSHAKE.
 * @return Error code.
 */
OT_WARN_UNUSED_RESULT
static status_t kmac_set_prefix_regs(const unsigned char *func_name,
                                     size_t func_name_len,
                                     const unsigned char *cust_str,
                                     size_t cust_str_len) {
  // Initialize with 0 so that the last untouched bytes are set as 0x0
  uint32_t prefix_words[kKmacPrefixRegCount];
  memset(prefix_words, 0, sizeof(prefix_words));
  unsigned char *prefix_bytes = (unsigned char *)prefix_words;

  if (func_name_len + cust_str_len > kKmacPrefixMaxSize) {
    return OTCRYPTO_BAD_ARGS;
  }

  // left_encode(`func_name_len_bits`) below
  uint8_t bytes_written = 0;
  HARDENED_TRY(little_endian_encode(func_name_len << 3, prefix_bytes + 1,
                                    &bytes_written));
  prefix_bytes[0] = bytes_written;
  prefix_bytes += bytes_written + 1;

  // copy `func_name`
  memcpy(prefix_bytes, func_name, func_name_len);
  prefix_bytes += func_name_len;

  // left_encode(`cust_str_len_bits`) below
  HARDENED_TRY(little_endian_encode(cust_str_len << 3, prefix_bytes + 1,
                                    &bytes_written));
  prefix_bytes[0] = bytes_written;
  prefix_bytes += bytes_written + 1;

  // copy `cust_str`
  memcpy(prefix_bytes, cust_str, cust_str_len);

  // Copy from `prefix_words` to PREFIX_REGS
  hardened_mmio_write(kKmacBaseAddr + KMAC_PREFIX_0_REG_OFFSET, prefix_words,
                      kKmacPrefixRegCount);

  return OTCRYPTO_OK;
}

/**
 * Initializes the KMAC configuration.
 *
 * In particular, this function sets the CFG register of KMAC for given
 * operation, including security strength and operation type.
 *
 * `hw_backed` must be either `kHardenedBoolFalse` or `kHardenedBoolTrue`. For
 * other values, this function returns an error.
 * For KMAC operations, if `hw_backed = kHardenedBoolTrue` the sideloaded key
 * coming from Keymgr is used. If `hw_backed = kHardenedBoolFalse`, the key
 * configured by SW is used.
 *
 * For non-KMAC operations, the value of `hw_backed` can be either of
 * `kHardenedBoolFalse` or `kHardenedBoolTrue`. It is recommended to set it to
 * `kHardenedBoolFalse` for consistency.
 *
 * @param operation The chosen operation, see kmac_operation_t struct.
 * @param security_str Security strength for KMAC (128 or 256).
 * @param hw_backed Whether the key comes from the sideload port.
 * @return Error code.
 */
OT_WARN_UNUSED_RESULT
static status_t kmac_init(kmac_operation_t operation,
                          kmac_security_str_t security_str,
                          hardened_bool_t hw_backed) {
  HARDENED_TRY(wait_status_bit(KMAC_STATUS_SHA3_IDLE_BIT, 1));

  // If the operation is KMAC, ensure that the entropy complex has been
  // initialized for masking.
  if (operation == kKmacOperationKmac) {
    HARDENED_TRY(entropy_complex_check());
  }

  // We need to preserve some bits of CFG register, such as:
  // entropy_mode, entropy_ready etc. On the other hand, some bits
  // need to be reset for each invocation.
  uint32_t cfg_reg =
      abs_mmio_read32(kKmacBaseAddr + KMAC_CFG_SHADOWED_REG_OFFSET);

  if (launder32(hw_backed) == kHardenedBoolTrue) {
    HARDENED_CHECK_EQ(hw_backed, kHardenedBoolTrue);
    cfg_reg = bitfield_bit32_write(cfg_reg, KMAC_CFG_SHADOWED_SIDELOAD_BIT, 1);
  } else if (launder32(hw_backed) == kHardenedBoolFalse) {
    HARDENED_CHECK_EQ(hw_backed, kHardenedBoolFalse);
    cfg_reg = bitfield_bit32_write(cfg_reg, KMAC_CFG_SHADOWED_SIDELOAD_BIT, 0);
  } else {
    return OTCRYPTO_BAD_ARGS;
  };

  // Set the KMAC enable bit to zero by default.
  cfg_reg = bitfield_bit32_write(cfg_reg, KMAC_CFG_SHADOWED_KMAC_EN_BIT, 0);

  // Set the operation type.
  switch (launder32(operation)) {
    case kKmacOperationSha3: {
      HARDENED_CHECK_EQ(operation, kKmacOperationSha3);
      cfg_reg = bitfield_field32_write(cfg_reg, KMAC_CFG_SHADOWED_MODE_FIELD,
                                       KMAC_CFG_SHADOWED_MODE_VALUE_SHA3);
      break;
    }
    case kKmacOperationShake: {
      HARDENED_CHECK_EQ(operation, kKmacOperationShake);
      cfg_reg = bitfield_field32_write(cfg_reg, KMAC_CFG_SHADOWED_MODE_FIELD,
                                       KMAC_CFG_SHADOWED_MODE_VALUE_SHAKE);
      break;
    }
    case kKmacOperationCshake: {
      HARDENED_CHECK_EQ(operation, kKmacOperationCshake);
      cfg_reg = bitfield_field32_write(cfg_reg, KMAC_CFG_SHADOWED_MODE_FIELD,
                                       KMAC_CFG_SHADOWED_MODE_VALUE_CSHAKE);
      break;
    }
    case kKmacOperationKmac: {
      HARDENED_CHECK_EQ(operation, kKmacOperationKmac);
      cfg_reg = bitfield_field32_write(cfg_reg, KMAC_CFG_SHADOWED_MODE_FIELD,
                                       KMAC_CFG_SHADOWED_MODE_VALUE_CSHAKE);
      cfg_reg = bitfield_bit32_write(cfg_reg, KMAC_CFG_SHADOWED_KMAC_EN_BIT, 1);
      break;
    }
    default:
      return OTCRYPTO_BAD_ARGS;
  }

  switch (launder32(security_str)) {
    case kKmacSecurityStrength128:
      HARDENED_CHECK_EQ(security_str, kKmacSecurityStrength128);
      cfg_reg =
          bitfield_field32_write(cfg_reg, KMAC_CFG_SHADOWED_KSTRENGTH_FIELD,
                                 KMAC_CFG_SHADOWED_KSTRENGTH_VALUE_L128);
      break;
    case kKmacSecurityStrength224:
      HARDENED_CHECK_EQ(security_str, kKmacSecurityStrength224);
      cfg_reg =
          bitfield_field32_write(cfg_reg, KMAC_CFG_SHADOWED_KSTRENGTH_FIELD,
                                 KMAC_CFG_SHADOWED_KSTRENGTH_VALUE_L224);
      break;
    case kKmacSecurityStrength256:
      HARDENED_CHECK_EQ(security_str, kKmacSecurityStrength256);
      cfg_reg =
          bitfield_field32_write(cfg_reg, KMAC_CFG_SHADOWED_KSTRENGTH_FIELD,
                                 KMAC_CFG_SHADOWED_KSTRENGTH_VALUE_L256);
      break;
    case kKmacSecurityStrength384:
      HARDENED_CHECK_EQ(security_str, kKmacSecurityStrength384);
      cfg_reg =
          bitfield_field32_write(cfg_reg, KMAC_CFG_SHADOWED_KSTRENGTH_FIELD,
                                 KMAC_CFG_SHADOWED_KSTRENGTH_VALUE_L384);
      break;
    case kKmacSecurityStrength512:
      HARDENED_CHECK_EQ(security_str, kKmacSecurityStrength512);
      cfg_reg =
          bitfield_field32_write(cfg_reg, KMAC_CFG_SHADOWED_KSTRENGTH_FIELD,
                                 KMAC_CFG_SHADOWED_KSTRENGTH_VALUE_L512);
      break;
    default:
      return OTCRYPTO_BAD_ARGS;
  }

  abs_mmio_write32_shadowed(kKmacBaseAddr + KMAC_CFG_SHADOWED_REG_OFFSET,
                            cfg_reg);

  return OTCRYPTO_OK;
}

/**
 * Update the key registers with given key shares.
 *
 * The accepted `key->len` values are {128 / 8, 192 / 8, 256 / 8, 384 / 8,
 * 512 / 8}, otherwise an error will be returned.
 *
 * If the key is hardware-backed, this is a no-op.
 *
 * Uses hardening primitives internally that consume entropy; the caller must
 * ensure the entropy complex is up before calling.
 *
 * @param key The input key passed as a struct.
 * @return Error code.
 */
OT_WARN_UNUSED_RESULT
static status_t kmac_write_key_block(kmac_blinded_key_t *key) {
  if (launder32(key->hw_backed) == kHardenedBoolTrue) {
    // Nothing to do.
    return OTCRYPTO_OK;
  } else if (launder32(key->hw_backed) != kHardenedBoolFalse) {
    // Invalid value.
    return OTCRYPTO_BAD_ARGS;
  }
  HARDENED_CHECK_EQ(key->hw_backed, kHardenedBoolFalse);

  uint32_t key_len_reg;
  HARDENED_TRY(key_len_reg_get(key->len, &key_len_reg));
  abs_mmio_write32(kKmacBaseAddr + KMAC_KEY_LEN_REG_OFFSET, key_len_reg);

  // Write random words to the key registers first for SCA defense.
  for (size_t i = 0; i * sizeof(uint32_t) < key->len; i++) {
    abs_mmio_write32(kKmacKeyShare0Addr + i * sizeof(uint32_t),
                     ibex_rnd32_read());
  }
  hardened_mmio_write(kKmacKeyShare0Addr, key->share0,
                      key->len / sizeof(uint32_t));
  for (size_t i = 0; i * sizeof(uint32_t) < key->len; i++) {
    abs_mmio_write32(kKmacKeyShare1Addr + i * sizeof(uint32_t),
                     ibex_rnd32_read());
  }
  hardened_mmio_write(kKmacKeyShare1Addr, key->share1,
                      key->len / sizeof(uint32_t));
  return OTCRYPTO_OK;
}

/**
 * Common routine for feeding message blocks during SHA/SHAKE/cSHAKE/KMAC.
 *
 * Before running this, the operation type must be configured with kmac_init.
 * Then, we can use this function to feed various bytes of data to the KMAC
 * core. Note that this is a one-shot implementation, and it does not support
 * streaming mode.
 *
 * This routine does not check input parameters for consistency. For instance,
 * one can invoke SHA-3_224 with digest_len=32, which will produce 256 bits of
 * digest. The caller is responsible for ensuring that the digest length and
 * mode are consistent.
 *
 * The caller must ensure that `message_len` bytes (rounded up to the next 32b
 * word) are allocated at the location pointed to by `message`, and similarly
 * that `digest_len_words` 32-bit words are allocated at the location pointed
 * to by `digest`. If `masked_digest` is set, then `digest` must contain 2x
 * `digest_len_words` to fit both shares.
 *
 * @param operation The operation type.
 * @param message Input message string.
 * @param message_len Message length in bytes.
 * @param digest The struct to which the result will be written.
 * @param digest_len_words Requested digest length in 32-bit words.
 * @param masked_digest Whether to return the digest in two shares.
 * @return Error code.
 */
OT_WARN_UNUSED_RESULT
static status_t kmac_process_msg_blocks(kmac_operation_t operation,
                                        const uint8_t *message,
                                        size_t message_len, uint32_t *digest,
                                        size_t digest_len_words,
                                        hardened_bool_t masked_digest) {
  // Block until KMAC is idle.
  HARDENED_TRY(wait_status_bit(KMAC_STATUS_SHA3_IDLE_BIT, 1));

  // Issue the start command, so that messages written to MSG_FIFO are forwarded
  // to Keccak
  uint32_t cmd_reg = KMAC_CMD_REG_RESVAL;
  cmd_reg = bitfield_field32_write(cmd_reg, KMAC_CMD_CMD_FIELD,
                                   KMAC_CMD_CMD_VALUE_START);
  abs_mmio_write32(kKmacBaseAddr + KMAC_CMD_REG_OFFSET, cmd_reg);
  HARDENED_TRY(wait_status_bit(KMAC_STATUS_SHA3_ABSORB_BIT, 1));

  // Begin by writing a one byte at a time until the data is aligned.
  size_t i = 0;
  for (; misalignment32_of((uintptr_t)(&message[i])) > 0 && i < message_len;
       i++) {
    HARDENED_TRY(wait_status_bit(KMAC_STATUS_FIFO_FULL_BIT, 0));
    abs_mmio_write8(kKmacBaseAddr + KMAC_MSG_FIFO_REG_OFFSET, message[i]);
  }

  // Write one word at a time as long as there is a full word available.
  for (; i + sizeof(uint32_t) <= message_len; i += sizeof(uint32_t)) {
    HARDENED_TRY(wait_status_bit(KMAC_STATUS_FIFO_FULL_BIT, 0));
    uint32_t next_word = read_32(&message[i]);
    abs_mmio_write32(kKmacBaseAddr + KMAC_MSG_FIFO_REG_OFFSET, next_word);
  }

  // For the last few bytes, we need to write one byte at a time again.
  for (; i < message_len; i++) {
    HARDENED_TRY(wait_status_bit(KMAC_STATUS_FIFO_FULL_BIT, 0));
    abs_mmio_write8(kKmacBaseAddr + KMAC_MSG_FIFO_REG_OFFSET, message[i]);
  }

  // If operation=KMAC, then we need to write `right_encode(digest->len)`
  if (operation == kKmacOperationKmac) {
    uint32_t digest_len_bits = 8 * sizeof(uint32_t) * digest_len_words;
    if (digest_len_bits / (8 * sizeof(uint32_t)) != digest_len_words) {
      return OTCRYPTO_BAD_ARGS;
    }

    // right_encode(`digest_len_bit`) below
    // According to NIST SP 800-185, the maximum integer that can be encoded
    // with `right_encode` is the value represented with 255 bytes. However,
    // this driver supports only up to `digest_len_bits` that can be represented
    // with `size_t`.
    uint8_t buf[sizeof(size_t) + 1] = {0};
    uint8_t bytes_written;
    HARDENED_TRY(little_endian_encode(digest_len_bits, buf, &bytes_written));
    buf[bytes_written] = bytes_written;
    uint8_t *fifo_dst = (uint8_t *)(kKmacBaseAddr + KMAC_MSG_FIFO_REG_OFFSET);
    memcpy(fifo_dst, buf, bytes_written + 1);
  }

  // Issue the process command, so that squeezing phase can start
  cmd_reg = KMAC_CMD_REG_RESVAL;
  cmd_reg = bitfield_field32_write(cmd_reg, KMAC_CMD_CMD_FIELD,
                                   KMAC_CMD_CMD_VALUE_PROCESS);
  abs_mmio_write32(kKmacBaseAddr + KMAC_CMD_REG_OFFSET, cmd_reg);

  // Wait until squeezing is done
  HARDENED_TRY(wait_status_bit(KMAC_STATUS_SHA3_SQUEEZE_BIT, 1));

  // Determine the rate based on the hardware configuration.
  size_t keccak_rate_words = kmac_get_keccak_rate_words();
  HARDENED_CHECK_NE(keccak_rate_words, 0);
  HARDENED_CHECK_LT(keccak_rate_words, kKmacStateShareSize / sizeof(uint32_t));

  // Finally, we can read the two shares of digest and XOR them.
  size_t idx = 0;

  while (launder32(idx) < digest_len_words) {
    // Since we always read in increments of the Keccak rate, the index at
    // start should always be a multiple of the rate.
    HARDENED_CHECK_EQ(idx % keccak_rate_words, 0);

    // Poll the status register until in the 'squeeze' state.
    HARDENED_TRY(wait_status_bit(KMAC_STATUS_SHA3_SQUEEZE_BIT, 1));

    // Read words from the state registers (either `digest_len_words` or the
    // maximum number of words available).
    size_t offset = 0;
    if (launder32(masked_digest) == kHardenedBoolTrue) {
      HARDENED_CHECK_EQ(masked_digest, kHardenedBoolTrue);
      // Read the digest into each share in turn.
      size_t nwords = keccak_rate_words;
      if (digest_len_words - idx < nwords) {
        nwords = digest_len_words - idx;
      }
      HARDENED_CHECK_LE(nwords, digest_len_words - idx);
      HARDENED_CHECK_LE(nwords, keccak_rate_words);
      hardened_mmio_read(&digest[idx], kKmacStateShare0Addr, nwords);
      hardened_mmio_read(&digest[idx + digest_len_words], kKmacStateShare1Addr,
                         nwords);
      idx += nwords;
    } else {
      // Skip right to the hardened check here instead of returning
      // `OTCRYPTO_BAD_ARGS` if the value is not `kHardenedBoolFalse`; this
      // value always comes from within the cryptolib, so we expect it to be
      // valid and should be suspicious if it's not.
      HARDENED_CHECK_EQ(masked_digest, kHardenedBoolFalse);
      // Unmask the digest as we read it.
      for (; launder32(idx) < digest_len_words && offset < keccak_rate_words;
           offset++) {
        digest[idx] =
            abs_mmio_read32(kKmacStateShare0Addr + offset * sizeof(uint32_t));
        digest[idx] ^=
            abs_mmio_read32(kKmacStateShare1Addr + offset * sizeof(uint32_t));
        idx++;
      }
    }

    // If we read all the remaining words and still need more digest, issue
    // `CMD.RUN` to generate more state.
    if (launder32(offset) == keccak_rate_words && idx < digest_len_words) {
      HARDENED_CHECK_EQ(offset, keccak_rate_words);
      cmd_reg = KMAC_CMD_REG_RESVAL;
      cmd_reg = bitfield_field32_write(cmd_reg, KMAC_CMD_CMD_FIELD,
                                       KMAC_CMD_CMD_VALUE_RUN);
      abs_mmio_write32(kKmacBaseAddr + KMAC_CMD_REG_OFFSET, cmd_reg);
    }
  }
  HARDENED_CHECK_EQ(idx, digest_len_words);

  // Poll the status register until in the 'squeeze' state.
  HARDENED_TRY(wait_status_bit(KMAC_STATUS_SHA3_SQUEEZE_BIT, 1));

  // Release the KMAC core, so that it goes back to idle mode
  cmd_reg = KMAC_CMD_REG_RESVAL;
  cmd_reg = bitfield_field32_write(cmd_reg, KMAC_CMD_CMD_FIELD,
                                   KMAC_CMD_CMD_VALUE_DONE);
  abs_mmio_write32(kKmacBaseAddr + KMAC_CMD_REG_OFFSET, cmd_reg);

  return OTCRYPTO_OK;
}

/**
 * Perform a one-shot SHA3, SHAKE, or cSHAKE operation.
 *
 * Do not use this routine for KMAC operations.
 *
 * @param operation Hash function to perform.
 * @param strength Security strength parameter.
 * @param message Message data to hash.
 * @param message_len Length of message data in bytes.
 * @param digest_wordlen Length of digest in words.
 * @param[out] digest Computed digest.
 * @return OK or error.
 */
OT_WARN_UNUSED_RESULT
static status_t hash(kmac_operation_t operation, kmac_security_str_t strength,
                     const uint8_t *message, size_t message_len,
                     size_t digest_wordlen, uint32_t *digest) {
  // Note: to save code size, we check for null pointers here instead of
  // separately for every different Keccak hash operation.
  if (digest == NULL || (message == NULL && message_len != 0)) {
    return OTCRYPTO_BAD_ARGS;
  }

  HARDENED_TRY(kmac_init(operation, strength,
                         /*hw_backed=*/kHardenedBoolFalse));

  return kmac_process_msg_blocks(operation, message, message_len, digest,
                                 digest_wordlen,
                                 /*masked_digest=*/kHardenedBoolFalse);
}

inline status_t kmac_sha3_224(const uint8_t *message, size_t message_len,
                              uint32_t *digest) {
  return hash(kKmacOperationSha3, kKmacSecurityStrength224, message,
              message_len, kKmacSha3224DigestWords, digest);
}

inline status_t kmac_sha3_256(const uint8_t *message, size_t message_len,
                              uint32_t *digest) {
  return hash(kKmacOperationSha3, kKmacSecurityStrength256, message,
              message_len, kKmacSha3256DigestWords, digest);
}

inline status_t kmac_sha3_384(const uint8_t *message, size_t message_len,
                              uint32_t *digest) {
  return hash(kKmacOperationSha3, kKmacSecurityStrength384, message,
              message_len, kKmacSha3384DigestWords, digest);
}

inline status_t kmac_sha3_512(const uint8_t *message, size_t message_len,
                              uint32_t *digest) {
  return hash(kKmacOperationSha3, kKmacSecurityStrength512, message,
              message_len, kKmacSha3512DigestWords, digest);
}

inline status_t kmac_shake_128(const uint8_t *message, size_t message_len,
                               uint32_t *digest, size_t digest_len) {
  return hash(kKmacOperationShake, kKmacSecurityStrength128, message,
              message_len, digest_len, digest);
}

inline status_t kmac_shake_256(const uint8_t *message, size_t message_len,
                               uint32_t *digest, size_t digest_len) {
  return hash(kKmacOperationShake, kKmacSecurityStrength256, message,
              message_len, digest_len, digest);
}

status_t kmac_cshake_128(const uint8_t *message, size_t message_len,
                         const unsigned char *func_name, size_t func_name_len,
                         const unsigned char *cust_str, size_t cust_str_len,
                         uint32_t *digest, size_t digest_len) {
  HARDENED_TRY(wait_status_bit(KMAC_STATUS_SHA3_IDLE_BIT, 1));
  HARDENED_TRY(
      kmac_set_prefix_regs(func_name, func_name_len, cust_str, cust_str_len));
  return hash(kKmacOperationCshake, kKmacSecurityStrength128, message,
              message_len, digest_len, digest);
}

status_t kmac_cshake_256(const uint8_t *message, size_t message_len,
                         const unsigned char *func_name, size_t func_name_len,
                         const unsigned char *cust_str, size_t cust_str_len,
                         uint32_t *digest, size_t digest_len) {
  HARDENED_TRY(wait_status_bit(KMAC_STATUS_SHA3_IDLE_BIT, 1));
  HARDENED_TRY(
      kmac_set_prefix_regs(func_name, func_name_len, cust_str, cust_str_len));
  return hash(kKmacOperationCshake, kKmacSecurityStrength256, message,
              message_len, digest_len, digest);
}

status_t kmac_kmac_128(kmac_blinded_key_t *key, hardened_bool_t masked_digest,
                       const uint8_t *message, size_t message_len,
                       const unsigned char *cust_str, size_t cust_str_len,
                       uint32_t *digest, size_t digest_len) {
  HARDENED_TRY(
      kmac_init(kKmacOperationKmac, kKmacSecurityStrength128, key->hw_backed));

  HARDENED_TRY(kmac_write_key_block(key));
  HARDENED_TRY(kmac_set_prefix_regs(
      kKmacFuncNameKMAC, sizeof(kKmacFuncNameKMAC), cust_str, cust_str_len));

  return kmac_process_msg_blocks(kKmacOperationKmac, message, message_len,
                                 digest, digest_len, masked_digest);
}

status_t kmac_kmac_256(kmac_blinded_key_t *key, hardened_bool_t masked_digest,
                       const uint8_t *message, size_t message_len,
                       const unsigned char *cust_str, size_t cust_str_len,
                       uint32_t *digest, size_t digest_len) {
  HARDENED_TRY(
      kmac_init(kKmacOperationKmac, kKmacSecurityStrength256, key->hw_backed));

  HARDENED_TRY(kmac_write_key_block(key));
  HARDENED_TRY(kmac_set_prefix_regs(
      kKmacFuncNameKMAC, sizeof(kKmacFuncNameKMAC), cust_str, cust_str_len));

  return kmac_process_msg_blocks(kKmacOperationKmac, message, message_len,
                                 digest, digest_len, masked_digest);
}
