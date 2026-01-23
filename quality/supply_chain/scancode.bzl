# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("@rules_pkg//pkg/private/tar:tar.bzl", "pkg_tar")

def scancode_test(
        name = "",
        srcs = [],
        policy_file = "//quality/supply_chain:policy.yaml",
        ignore = [],
        extra_scancode_args = [],
        **kwargs):
    # Using a TAR archive prevents an "Argument list too long" error if we
    # passed large `filegroup`s into the test rule directly using
    # `$(execpaths)`.
    pkg_tar(
        name = name + "_tar",
        srcs = srcs,
        strip_prefix = ".",
    )

    native.sh_test(
        name = name,
        timeout = "long",
        srcs = ["//quality/supply_chain:scancode_test.sh"],
        args = [
            "$(location //quality/supply_chain:scancode)",
            "$(location {})".format(policy_file),
            "$(location :{}_tar)".format(name),
        ] + [
            "--ignore=_srcs/*/" + item
            for item in ignore
        ] + extra_scancode_args,
        data = [
            "//quality/supply_chain:scancode",
            policy_file,
            ":{}_tar".format(name),
        ],
        tags = ["scancode", "supply_chain", "quality"],
        **kwargs
    )
