# Copyright zeroRISC Inc.
# Modified by Authors of "Towards ML-KEM & ML-DSA on OpenTitan" (https://eprint.iacr.org/2024/1192).
# Copyright "Towards ML-KEM & ML-DSA on OpenTitan" Authors.
# Modified by Ruben Niederhagen and Hoang Nguyen Hien Pham - authors of
# "Improving ML-KEM & ML-DSA on OpenTitan - Efficient Multiplication Vector Instructions for OTBN"
# (https://eprint.iacr.org/2025/2028).
# Copyright Ruben Niederhagen and Hoang Nguyen Hien Pham.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("@ot_python_deps//:requirements.bzl", "requirement")
load("//rules:acc.bzl", "acc_autogen_sim_test", "acc_binary", "acc_consttime_test", "acc_library", "acc_sim_test")

package(default_visibility = ["//visibility:public"])

MODE_FOR_PARAMS = {
    "mlkem512": 2,
    "mlkem768": 3,
    "mlkem1024": 4,
}

NTESTS = 3

STATS = True  # makes tests run slower but logs detailed execution stats

# Key generation tests
py_binary(
    name = "mlkem_keypair_testgen",
    srcs = ["mlkem_keypair_testgen.py"],
    imports = [
        "../../../../../hw/ip/acc/util",
    ],
    deps = [
        "//hw/ip/acc/util/shared:testgen",
        requirement("kyber-py"),
    ],
)

[
    acc_autogen_sim_test(
        name = params + "_keypair_test" + str(i),
        srcs = ["mlkem_keypair_test.s"],
        copts = [
            "-DKYBER_K=" + str(MODE_FOR_PARAMS[params]),
        ],
        pqc = True,
        seed = i,
        stats = STATS,
        testgen = ":mlkem_keypair_testgen",
        testgen_args = [params],
        deps = [
            "//sw/acc/crypto/mlkem:basemul",
            "//sw/acc/crypto/mlkem:cbd",
            "//sw/acc/crypto/mlkem:kmac_send_msg",
            "//sw/acc/crypto/mlkem:" + params + "_consts",
            "//sw/acc/crypto/mlkem:" + params + "_keypair",
            "//sw/acc/crypto/mlkem:" + params + "_pack_keys",
            "//sw/acc/crypto/mlkem:" + params + "_poly",
            "//sw/acc/crypto/mlkem:ntt",
            "//sw/acc/crypto/mlkem:poly_gen_matrix",
        ],
    )
    for i in range(NTESTS)
    for params in MODE_FOR_PARAMS
]

# Encapsulation tests
py_binary(
    name = "mlkem_encap_testgen",
    srcs = ["mlkem_encap_testgen.py"],
    imports = [
        "../../../../../hw/ip/acc/util",
    ],
    deps = [
        "//hw/ip/acc/util/shared:testgen",
        requirement("kyber-py"),
    ],
)

[
    acc_autogen_sim_test(
        name = params + "_encap_test" + str(i),
        srcs = ["mlkem_encap_test.s"],
        copts = [
            "-DKYBER_K=" + str(MODE_FOR_PARAMS[params]),
        ],
        pqc = True,
        seed = i,
        stats = STATS,
        testgen = ":mlkem_encap_testgen",
        testgen_args = [params],
        deps = [
            "//sw/acc/crypto/mlkem:basemul",
            "//sw/acc/crypto/mlkem:cbd",
            "//sw/acc/crypto/mlkem:intt",
            "//sw/acc/crypto/mlkem:kmac_send_msg",
            "//sw/acc/crypto/mlkem:" + params + "_consts",
            "//sw/acc/crypto/mlkem:" + params + "_encap",
            "//sw/acc/crypto/mlkem:" + params + "_indcpa_enc",
            "//sw/acc/crypto/mlkem:" + params + "_pack_ciphertext",
            "//sw/acc/crypto/mlkem:" + params + "_pack_keys",
            "//sw/acc/crypto/mlkem:" + params + "_poly",
            "//sw/acc/crypto/mlkem:ntt",
            "//sw/acc/crypto/mlkem:poly_gen_matrix",
        ],
    )
    for i in range(NTESTS)
    for params in MODE_FOR_PARAMS
]

# Encapsulation tests
py_binary(
    name = "mlkem_decap_testgen",
    srcs = ["mlkem_decap_testgen.py"],
    imports = [
        "../../../../../hw/ip/acc/util",
    ],
    deps = [
        "//hw/ip/acc/util/shared:testgen",
        requirement("kyber-py"),
    ],
)

[
    acc_autogen_sim_test(
        name = params + "_decap_test" + str(i),
        srcs = ["mlkem_decap_test.s"],
        copts = [
            "-DKYBER_K=" + str(MODE_FOR_PARAMS[params]),
        ],
        pqc = True,
        seed = i,
        stats = STATS,
        testgen = ":mlkem_decap_testgen",
        testgen_args = [params],
        deps = [
            "//sw/acc/crypto/mlkem:basemul",
            "//sw/acc/crypto/mlkem:cbd",
            "//sw/acc/crypto/mlkem:intt",
            "//sw/acc/crypto/mlkem:kmac_send_msg",
            "//sw/acc/crypto/mlkem:" + params + "_consts",
            "//sw/acc/crypto/mlkem:" + params + "_decap",
            "//sw/acc/crypto/mlkem:" + params + "_indcpa_enc",
            "//sw/acc/crypto/mlkem:" + params + "_pack_ciphertext",
            "//sw/acc/crypto/mlkem:" + params + "_pack_keys",
            "//sw/acc/crypto/mlkem:" + params + "_poly",
            "//sw/acc/crypto/mlkem:ntt",
            "//sw/acc/crypto/mlkem:poly_gen_matrix",
        ],
    )
    for i in range(NTESTS)
    for params in MODE_FOR_PARAMS
]

[
    acc_autogen_sim_test(
        name = params + "_false_decap_test" + str(i),
        srcs = ["mlkem_decap_test.s"],
        copts = [
            "-DKYBER_K=" + str(MODE_FOR_PARAMS[params]),
        ],
        pqc = True,
        seed = i,
        stats = STATS,
        testgen = ":mlkem_decap_testgen",
        testgen_args = [
            "-i",
            params,
        ],
        deps = [
            "//sw/acc/crypto/mlkem:basemul",
            "//sw/acc/crypto/mlkem:cbd",
            "//sw/acc/crypto/mlkem:intt",
            "//sw/acc/crypto/mlkem:kmac_send_msg",
            "//sw/acc/crypto/mlkem:" + params + "_consts",
            "//sw/acc/crypto/mlkem:" + params + "_decap",
            "//sw/acc/crypto/mlkem:" + params + "_indcpa_enc",
            "//sw/acc/crypto/mlkem:" + params + "_pack_ciphertext",
            "//sw/acc/crypto/mlkem:" + params + "_pack_keys",
            "//sw/acc/crypto/mlkem:" + params + "_poly",
            "//sw/acc/crypto/mlkem:ntt",
            "//sw/acc/crypto/mlkem:poly_gen_matrix",
        ],
    )
    for i in range(NTESTS)
    for params in MODE_FOR_PARAMS
]

ENCAP_CONSTTIME_SUBROUTINES = [
    "basemul",
    "basemul_acc",
    "intt",
    "ntt",
    "pack_ciphertext",
    "poly_add",
    "poly_frommsg",
    "poly_gen_matrix_init",
    "poly_getnoise_eta_init",
    "poly_getnoise_eta_1",
    "poly_getnoise_eta_2",
    "unpack_pk",

    # The constant-time checker cannot handle the logic-dependent memory accesses
    # of the following routines -- even though the logic does not depend on
    # secret data, the information flow through DMEM cannot be constructed
    # without knowing where the loads and stores are going.
    #
    # TODO: adding a capability to the information-flow analysis backend that can
    # store the possible *range* of a GPR in a certain control-flow path, so that
    # memory loads/stores can be conservatively mapped to the the whole range,
    # would likely solve this.

    # "poly_gen_matrix",
]

# keccak_send_message is special because the length argument affects control
# flow, so we need to explicitly say the secrets are in dmem
acc_consttime_test(
    name = "keccak_send_message_consttime",
    secret = ["dmem"],
    subroutine = "keccak_send_message",
    deps = [
        ":mlkem512_encap_test0",
    ],
)

[
    acc_consttime_test(
        name = params + "_" + subroutine + "_consttime",
        subroutine = subroutine,
        deps = [
            ":" + params + "_encap_test0",
        ],
    )
    for subroutine in ENCAP_CONSTTIME_SUBROUTINES
    for params in MODE_FOR_PARAMS
]

# Includes only subroutines not shared with encap.
DECAP_CONSTTIME_SUBROUTINES = [
    "indcpa_dec",
    "poly_sub",
    "poly_tomsg",
    "unpack_ciphertext",
    "unpack_sk",
]

[
    acc_consttime_test(
        name = params + "_" + subroutine + "_consttime",
        subroutine = subroutine,
        deps = [
            ":" + params + "_decap_test0",
        ],
    )
    for subroutine in DECAP_CONSTTIME_SUBROUTINES
    for params in MODE_FOR_PARAMS
]

# Special check to ensure the ciphertext comparison is constant-time.
acc_consttime_test(
    name = "decap_ciphertext_compare_consttime",
    subroutine = "_decap_ciphertext_compare_label_for_consttime_check",
    deps = [
        ":mlkem512_decap_test0",
    ],
)

# Includes only subroutines not shared with encap or decap.
KEYPAIR_CONSTTIME_SUBROUTINES = [
    "pack_sk",
    "pack_pk",
    "poly_tomont",
]

[
    acc_consttime_test(
        name = params + "_" + subroutine + "_consttime",
        subroutine = subroutine,
        deps = [
            ":" + params + "_keypair_test0",
        ],
    )
    for subroutine in KEYPAIR_CONSTTIME_SUBROUTINES
    for params in MODE_FOR_PARAMS
]
