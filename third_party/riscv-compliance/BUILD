# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

# Copyright lowRISC contributors (OpenTitan project).
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load(":defs.bzl", "TESTS", "rv_compliance_test")
load("//quality/supply_chain:scancode.bzl", "scancode_test")

package(default_visibility = ["//visibility:public"])

scancode_test(
    name = "riscv_compliance_license_check",
    srcs = ["@riscv-compliance//:all_srcs"],
    ignore = [
        # Documentation file ScanCode cannot parse.
        "spec/TestFormatSpec.pdf",
    ],
)

[[rv_compliance_test(test, arch) for test in tests] for arch, tests in TESTS.items()]
