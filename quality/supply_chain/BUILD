# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("@rules_python//python/entry_points:py_console_script_binary.bzl", "py_console_script_binary")

package(default_visibility = ["//visibility:public"])

exports_files([
    "policy.yaml",
    "scancode_test.sh",
    "lint.sh",
])

# ScanCode binary
py_console_script_binary(
    name = "scancode",
    pkg = "@ot_python_deps//scancode_toolkit",
    deps = [
        "@ot_python_deps//extractcode_libarchive",
        "@ot_python_deps//typecode_libmagic",
    ],
)
