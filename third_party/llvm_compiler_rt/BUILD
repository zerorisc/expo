# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

# Copyright lowRISC contributors (OpenTitan project).
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("//rules/opentitan:defs.bzl", "OPENTITAN_CPU")
load("//quality/supply_chain:scancode.bzl", "scancode_test")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "llvm_compiler_rt",
    srcs = ["@llvm_compiler_rt//:srcs"],
    deps = [
        "//sw/device/lib/base:memory",
        "@llvm_compiler_rt//:hdrs",
    ],
)

scancode_test(
    name = "llvm_compiler_rt_license_check",
    srcs = ["@llvm_compiler_rt//:all_srcs"],
)
