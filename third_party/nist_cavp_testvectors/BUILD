# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("//quality/supply_chain:scancode.bzl", "scancode_test")

scancode_test(
    name = "nist_cavp_testvectors_license_check",
    srcs = [
        "@{}//:all_srcs".format(repo)
        for repo in [
            "nist_cavp_drbg_sp_800_90a_root",
            "nist_cavp_ecdsa_fips_186_4",
            "nist_cavp_sha2_fips_180_4",
            "nist_cavp_sha3_fips_202",
            "nist_cavp_shake_fips_202",
            "nist_cavp_aes_kw_sp_800_38f",
            "nist_cavp_aes_gcm",
            "nist_cavp_ecdh_sp_800_56a",
            "nist_cavp_rsa_fips_186_3",
            "nist_cavp_hmac_fips_198_1",
        ]
    ],
)

scancode_test(
    name = "aes_kat_license_check",
    srcs = [
        "@nist_cavp_aes_kat//:all_srcs",
    ],
    # Mentions a transitive library dependency this repository does not use,
    # which is multi-licensed under GPL, LGPL, and MPL.
    ignore = [
        "aesval.html",
    ],
)
