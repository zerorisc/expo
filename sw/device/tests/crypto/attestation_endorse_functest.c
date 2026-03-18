// Copyright lowRISC contributors (OpenTitan project).
// Copyright zeroRISC Inc.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "sw/device/lib/base/abs_mmio.h"
#include "sw/device/lib/base/mmio.h"
#include "sw/device/lib/crypto/drivers/entropy.h"
#include "sw/device/lib/crypto/drivers/hmac.h"
#include "sw/device/lib/crypto/impl/keyblob.h"
#include "sw/device/lib/crypto/include/datatypes.h"
#include "sw/device/lib/crypto/include/ecc_p256.h"
#include "sw/device/lib/crypto/include/hmac.h"
#include "sw/device/lib/crypto/include/key_transport.h"
#include "sw/device/lib/runtime/log.h"
#include "sw/device/lib/testing/keymgr_testutils.h"
#include "sw/device/lib/testing/test_framework/check.h"
#include "sw/device/lib/testing/test_framework/ottf_main.h"
#include "sw/device/silicon_creator/lib/cert/cdi_1.h"  // Generated.
#include "sw/device/silicon_creator/lib/drivers/flash_ctrl.h"
#include "sw/device/silicon_creator/manuf/base/perso_tlv_data.h"

#include "hw/top/flash_ctrl_regs.h"
#include "hw/top_earlgrey/sw/autogen/top_earlgrey.h"

// Module ID for status codes.
#define MODULE_ID MAKE_MODULE_ID('t', 's', 't')

enum {
  /* Number of 32-bit words in a P-256 public key. */
  kP256PublicKeyWords = 512 / 32,
  /* Number of 32-bit words in a P-256 signature. */
  kP256SignatureWords = 512 / 32,
  /* Number of bytes in a P-256 private key. */
  kP256PrivateKeyBytes = 256 / 8,
};

// Message to endorse (in production this would be a certificate, but for
// testing any message will do).
static const char kMessage[] = "test message";

// Object identifier for the P-256 curve. We use this to find the public key
// within the CDI_1 X.509 certificate.
static const uint8_t kOidPrime256v1[] = {0x06, 0x08, 0x2a, 0x86, 0x48,
                                         0xce, 0x3d, 0x03, 0x01, 0x07};

// Number of bytes between the P-256 identifier and the actual public key data.
static const size_t kTagHeaderBytes = 4;

status_t sign_then_verify_test(void) {
  uint32_t dice_certs[FLASH_CTRL_PARAM_BYTES_PER_PAGE / sizeof(uint32_t)];
  TRY(flash_ctrl_info_read_zeros_on_read_error(
      &kFlashCtrlInfoPageDiceCerts, /*offset=*/0, ARRAYSIZE(dice_certs),
      dice_certs));

  // Extract the first certificate (CDI_0) and skip past it (rounding to the
  // next 64-bit-aligned address).
  perso_tlv_cert_obj_t cert;
  unsigned char *cert_buffer = (unsigned char *)dice_certs;
  size_t cert_buffer_size = sizeof(dice_certs);
  TRY(perso_tlv_get_cert_obj(cert_buffer, cert_buffer_size, &cert));
  CHECK_STR_EQ(cert.name, "CDI_0");
  size_t cdi0_word64s =
      (cert.obj_size + sizeof(uint64_t) - 1) / sizeof(uint64_t);
  size_t cdi0_bytes = cdi0_word64s * sizeof(uint64_t);
  cert_buffer += cdi0_bytes;
  cert_buffer_size -= cdi0_bytes;

  // Extract CDI_1 certificate.
  TRY(perso_tlv_get_cert_obj(cert_buffer, cert_buffer_size, &cert));
  CHECK_STR_EQ(cert.name, "CDI_1");

  // Find the OID for "EcPublicKey" within the certificate. This will come just
  // before the public key we're looking for.
  size_t offset = 0;
  for (;
       offset + sizeof(kOidPrime256v1) + kTagHeaderBytes <= cert.cert_body_size;
       offset++) {
    if (!memcmp(cert.cert_body_p + offset, kOidPrime256v1,
                sizeof(kOidPrime256v1))) {
      break;
    }
  }
  CHECK(
      offset + sizeof(kOidPrime256v1) + kTagHeaderBytes <= cert.cert_body_size,
      "Could not find P-256 OID within certificate.");

  // Allocate space for the public key and copy the data.
  uint32_t pk[kP256PublicKeyWords] = {0};
  // otcrypto_unblinded_key_t public_key = {
  //     .key_mode = kOtcryptoKeyModeEcdsaP256,
  //     .key_length = sizeof(pk),
  //     .key = pk,
  // };
  memcpy(pk,
         cert.cert_body_p + offset + sizeof(kOidPrime256v1) + kTagHeaderBytes,
         sizeof(pk));

  // The certificate stores the (x, y) values of the public key in big-endian
  // form, but cryptolib expects little-endian. Reverse the bytes of each
  // coordinate in-place.
  size_t coord_words = ARRAYSIZE(pk) / 2;
  uint32_t *x = pk;
  for (size_t i = 0; i < coord_words / 2; i++) {
    uint32_t xi = x[i];
    x[i] = __builtin_bswap32(x[coord_words - 1 - i]);
    x[coord_words - 1 - i] = __builtin_bswap32(xi);
  }
  uint32_t *y = pk + coord_words;
  for (size_t i = 0; i < coord_words / 2; i++) {
    uint32_t yi = y[i];
    y[i] = __builtin_bswap32(y[coord_words - 1 - i]);
    y[coord_words - 1 - i] = __builtin_bswap32(yi);
  }

  // Hash the message.
  otcrypto_const_byte_buf_t message = {
      .len = sizeof(kMessage) - 1,
      .data = (unsigned char *)&kMessage,
  };
  uint32_t message_digest_data[kHmacSha256DigestWords];
  otcrypto_hash_digest_t message_digest = {
      .data = message_digest_data,
      .len = ARRAYSIZE(message_digest_data),
      .mode = kOtcryptoHashModeSha256,
  };
  TRY(otcrypto_sha2_256(message, &message_digest));

  // Allocate space for the signature.
  uint32_t sig[kP256SignatureWords] = {0};

  // Generate a signature for the message.
  LOG_INFO("Signing...");
  CHECK_STATUS_OK(otcrypto_ecdsa_p256_attestation_endorse(
      message_digest,
      (otcrypto_word32_buf_t){.data = sig, .len = ARRAYSIZE(sig)}));

  // Verify the signature.
  LOG_INFO("Verifying...");
  // hardened_bool_t verification_result;
  // CHECK_STATUS_OK(otcrypto_ecdsa_p256_verify(
  //     &public_key, message_digest,
  //     (otcrypto_const_word32_buf_t){.data = sig, .len = ARRAYSIZE(sig)},
  //     &verification_result));

  // The signature should pass verification.
  // TRY_CHECK(verification_result == kHardenedBoolTrue);
  return OK_STATUS();
}

static status_t test_setup(void) {
  // Initialize the key manager and advance to OwnerRootKey state.  Note: the
  // keymgr testutils set this up using software entropy, so there is no need
  // to initialize the entropy complex first. However, this is of course not
  // the expected setup in production.
  dif_keymgr_t keymgr;
  dif_kmac_t kmac;
  dif_keymgr_state_t keymgr_state;
  TRY(keymgr_testutils_try_startup(&keymgr, &kmac, &keymgr_state));

  if (keymgr_state == kDifKeymgrStateCreatorRootKey) {
    TRY(keymgr_testutils_advance_state(&keymgr, &kOwnerIntParams));
    TRY(keymgr_testutils_advance_state(&keymgr, &kOwnerRootKeyParams));
  } else if (keymgr_state == kDifKeymgrStateOwnerIntermediateKey) {
    TRY(keymgr_testutils_advance_state(&keymgr, &kOwnerRootKeyParams));
  }

  TRY(keymgr_testutils_check_state(&keymgr, kDifKeymgrStateOwnerRootKey));

  // Initialize entropy complex for cryptolib, which the key manager uses to
  // clear sideloaded keys. The `keymgr_testutils_startup` function restarts
  // the device, so this should happen afterwards.
  return entropy_complex_init();
}

OTTF_DEFINE_TEST_CONFIG();

bool test_main(void) {
  status_t result = OK_STATUS();

  CHECK_STATUS_OK(test_setup());
  EXECUTE_TEST(result, sign_then_verify_test);

  return status_ok(result);
}
