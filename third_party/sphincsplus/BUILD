# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("//quality/supply_chain:scancode.bzl", "scancode_test")

scancode_test(
    name = "sphincsplus_license_check",
    srcs = [
        "@sphincsplus_fips205_ipd//:all_srcs",
        "@sphincsplus_sha256_kat//:all_srcs",
        "@sphincsplus_shake256_kat//:all_srcs",
    ],
)
