# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("//quality/supply_chain:scancode.bzl", "scancode_test")

scancode_test(
    name = "xkcp_license_check",
    srcs = ["@xkcp//:all_srcs"],
    ignore = [
        # The license file mentions some parts of libXKCP are either Public
        # Domain and others are GPL. This repo uses only public domain
        # components.
        "LICENSE",
    ],
)
