# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("//quality/supply_chain:scancode.bzl", "scancode_test")

scancode_test(
    name = "lychee_license_check",
    srcs = ["@lychee//:all_srcs"],
    ignore = [
        # Binary file that ScanCode cannot scan. Manually checked to be
        # Apache-2.0/MIT licensed:
        #
        # https://github.com/lycheeverse/lychee/blob/master/LICENSE-MIT
        # https://github.com/lycheeverse/lychee/blob/master/LICENSE-APACHE
        "lychee",
    ],
)
