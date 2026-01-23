# Copyright lowRISC contributors (OpenTitan project).
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("//rules/opentitan:defs.bzl", "OPENTITAN_CPU")
load("//quality/supply_chain:scancode.bzl", "scancode_test")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "freertos",
    srcs = ["@freertos//:srcs"],
    deps = [
        "//sw/device/lib/testing/test_framework:freertos_config",
        "@freertos//:hdrs",
    ],
)

scancode_test(
    name = "freertos_license_check",
    srcs = ["@freertos//:all_srcs"],
    ignore = [
        # Changelog that mentions FreeRTOS was formerly GPL licensed, but is not
        # MIT-licensed.
        "History.txt",
        # Files that are incorrectly flagged by ScanCode as GPL, but have an
        # explicity MIT license header at the top.
        "portable/CCS/ARM_CM3/port.c",
        "portable/CCS/ARM_CM4F/port.c",
        "portable/GCC/ARM_CR5/port.c",
        "portable/IAR/ARM_CM3/port.c",
        "portable/IAR/ARM_CM4F/port.c",
        "portable/IAR/ARM_CM4F_MPU/port.c",
        "portable/IAR/ARM_CM7/r0p1/port.c",
        "portable/RVDS/ARM_CM3/port.c",
        "portable/RVDS/ARM_CM4F/port.c",
        "portable/RVDS/ARM_CM7/r0p1/port.c",
        # Files licensed under *both* MIT and GPL with a "FreeRTOS exception"
        # that opts out of the sharealike condition.
        "portable/ThirdParty/GCC/Xtensa_ESP32/port.c",
        "portable/ThirdParty/GCC/Xtensa_ESP32/portmux_impl.h",
        "portable/ThirdParty/GCC/Xtensa_ESP32/portmux_impl.inc.h",
        "portable/ThirdParty/GCC/Xtensa_ESP32/include/portmacro.h",
    ],
)
