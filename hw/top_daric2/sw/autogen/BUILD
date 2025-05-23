# Copyright lowRISC contributors (OpenTitan project).
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
#
# ------------------- W A R N I N G: A U T O - G E N E R A T E D   C O D E !! -------------------#
# PLEASE DO NOT HAND-EDIT THIS FILE. IT HAS BEEN AUTO-GENERATED WITH THE FOLLOWING COMMAND:
# util/topgen.py -t hw/top_daric2/data/top_daric2.hjson
# -o hw/top_daric2

load("//rules:linker.bzl", "ld_library")
load("//hw/top:defs.bzl", "opentitan_require_top")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "top_daric2",
    srcs = [
        "top_daric2.c",
    ],
    hdrs = [
        "top_daric2.h",
        "top_daric2_memory.h",
    ],
    defines = ["OPENTITAN_IS_DARIC2"],
    target_compatible_with = opentitan_require_top("daric2"),
)

ld_library(
    name = "top_daric2_memory",
    defines = [
        "OPENTITAN_TOP_MEMORY_LD=top_daric2_memory.ld",
        "OPENTITAN_IS_DARIC2",
    ],
    includes = ["top_daric2_memory.ld"],
    target_compatible_with = opentitan_require_top("daric2"),
)
