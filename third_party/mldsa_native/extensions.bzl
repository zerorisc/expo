# Copyright The mldsa-native project authors
# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

mldsa_native = module_extension(
    implementation = lambda _: _mldsa_native_repos(),
)

def _mldsa_native_repos():
    http_archive(
        name = "mldsa_native",
        build_file = Label("//third_party/mldsa_native:BUILD.mldsa_native.bazel"),
        sha256 = "f3bb59d7256fcc20da7e64d20b3678f218cecd24de0b48dfe08112427a48cbb5",
        strip_prefix = "mldsa-native-58b6aa181e0ed8f8b3f7f60c6aef2f0319bfc101",
        urls = [
            "https://github.com/pq-code-package/mldsa-native/archive/58b6aa181e0ed8f8b3f7f60c6aef2f0319bfc101.tar.gz",
        ],
    )
