# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("//quality/supply_chain:scancode.bzl", "scancode_test")

scancode_test(
    name = "coremark_license_check",
    srcs = ["@coremark//:all_srcs"],
    ignore = [
        # Documentation files that mention a GPL-licensed docgen tool; not part
        # of the software dependency.
        "docs/html/javascript/main.js",
        "docs/html/styles/1.css",
    ],
)
