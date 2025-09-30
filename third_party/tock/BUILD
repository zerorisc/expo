# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

# Copyright lowRISC contributors (OpenTitan project).
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("@rules_python//python/entry_points:py_console_script_binary.bzl", "py_console_script_binary")
load("//quality/supply_chain:scancode.bzl", "scancode_test")

package(default_visibility = ["//visibility:public"])

scancode_test(
    name = "tock_license_check",
    srcs = [
        "@elf2tab//:all_srcs",
        "@libtock//:all_srcs",
        "@tock//:all_srcs",
    ],
    ignore = [
        # Tock Core WG meeting notes documents that _mention_ GPL/AGPL-licensed
        # libraries, but the documentation itself is not licensed as such.
        "doc/wg/core/notes/core-notes-2022-11-18.md",
        "doc/wg/core/notes/core-notes-2023-09-22.md",
        # Library for the NRF52 board that is GPLv3-licened upstream, but was
        # re-licenced by the orignal author to Apache-2.0 at the request of the
        # upstream Tock community. This particular library dependency of the Tock
        # kernel is regardless unused by OpenTitan.
        #
        # See:
        # https://github.com/tock/tock/blob/master/chips/nrf52/src/crt1.rs#L10
        # for details.
        "chips/nrf52/src/crt1.rs",
        # Documentation files that ScanCode cannot parse:
        "doc/courses/2018-11-SenSys/presentation/architecture.pdf",
        "doc/courses/2018-11-SenSys/presentation/execution.pdf",
        "doc/courses/rustconf/presentation/architecture.pdf",
        "doc/courses/rustconf/presentation/execution.pdf",
        "doc/courses/rustconf/presentation/ipc.pdf",
        "doc/courses/rustconf/presentation/presentation.pdf",
        "doc/courses/rustconf/presentation/rng.pdf",
        "doc/wg/network/notes/2023-08-24/2023-08-24_thread_stack_branden.drawio.pdf",
        "doc/wg/network/notes/2023-08-24/2023-08-24_thread_stack_tyler.drawio.pdf",
        "doc/wg/network/notes/2023-09-07/leon_tock_buffers_presentation.pdf",
        "doc/wg/opentitan/notes/2020-05-21_Ti50_on_Tock.pdf",
    ],
)

py_console_script_binary(
    name = "tockloader",
    pkg = "@ot_python_deps//tockloader",
)
