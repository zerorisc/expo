# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

# Copyright lowRISC contributors (OpenTitan project).
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

package(default_visibility = ["//visibility:private"])

load("//quality/supply_chain:scancode.bzl", "scancode_test")

scancode_test(
    name = "shellcheck_license_check",
    srcs = ["@shellcheck//:all_srcs"],
    policy_file = "//quality/supply_chain:dev_policy.yaml",
)

# This runnable alias points to the shellcheck executable.
alias(
    name = "shellcheck",
    actual = "@shellcheck//:shellcheck",
    visibility = ["//quality:__pkg__"],
)
