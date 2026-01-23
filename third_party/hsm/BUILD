# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

# Copyright lowRISC contributors (OpenTitan project).
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

package(default_visibility = ["//visibility:public"])

load("//quality/supply_chain:scancode.bzl", "scancode_test")

scancode_test(
    name = "sc_hsm_license_check",
    srcs = ["@sc_hsm//:all_srcs"],
)

scancode_test(
    name = "cloud_kms_hsm_license_check",
    srcs = ["@cloud_kms_hsm//:all_srcs"],
)

scancode_test(
    name = "softhsm2_license_check",
    srcs = ["@softhsm2//:all_srcs"],
    ignore = [
        # GPL-licensed build-time files that do not impact the library
        # (autoconf).
        "m4/pkg.m4",
    ],
)

scancode_test(
    name = "opensc_license_check",
    srcs = ["@opensc//:all_srcs"],
    ignore = [
        # GPL-licensed tools that generate build-time files, but do not impact
        # the library (autoconf).
        "m4/ax_check_compile_flag.m4",
        "m4/ax_pthread.m4",
        "m4/m4_ax_func_getopt_long.m4",
        # BSD-licensed documentation that mentions GPL in its header, but does
        # not use it.
        "src/common/README.compat_getopt",
        # LGPL-licensed test code that mentions GPL in its header, but does not
        # use it.
        "src/tests/unittests/hextobin.c",
    ],
)
