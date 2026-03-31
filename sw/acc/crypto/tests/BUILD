# Copyright lowRISC contributors (OpenTitan project).
# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("//rules:acc.bzl", "acc_clobbered_regs_test", "acc_consttime_test", "acc_library", "acc_sim_test", "acc_sim_test_suite")

package(default_visibility = ["//visibility:public"])

# Clobbered-register checks: verify that docstring annotations match
# the actual registers written (determined by information-flow analysis).
# N-dependent RSA/bignum helpers, routines taking a WDR index in a GPR,
# and sha3_shake (no acc_binary) are omitted.
#
# TODO: investigate why these take 30s-200s; tagged "manual" until fixed.
_SLOW_CLOBBERED_REGS_SUBS = [
    ("run_p384", "p384_base_mult"),
    ("run_p384", "p384_base_mult_checked"),
    ("run_p384", "scalar_mult_int_p384"),
    ("run_p384", "p384_scalar_mult"),
    ("run_p384", "p384_sign"),
    ("run_p384", "p384_verify"),
]

[acc_clobbered_regs_test(
    name = elf + "_" + sub + "_clobbered",
    srcs = ["//sw/acc/crypto:" + src],
    subroutine = sub,
    tags = ["manual"] if (elf, sub) in _SLOW_CLOBBERED_REGS_SUBS else [],
    deps = ["//sw/acc/crypto:" + elf],
) for sub, src, elf in [
    # Ed25519
    ("ed25519_verify_var", "ed25519.s", "run_ed25519"),
    ("ed25519_sign_prehashed", "ed25519.s", "run_ed25519"),
    ("sc_clamp", "ed25519.s", "run_ed25519"),
    ("affine_to_ext", "ed25519.s", "run_ed25519"),
    ("ext_to_affine", "ed25519.s", "run_ed25519"),
    ("affine_encode", "ed25519.s", "run_ed25519"),
    ("affine_decode_var", "ed25519.s", "run_ed25519"),
    ("ext_scmul", "ed25519.s", "run_ed25519"),
    ("ext_scmul_var", "ed25519.s", "run_ed25519"),
    ("ext_double", "ed25519.s", "run_ed25519"),
    ("ext_add", "ed25519.s", "run_ed25519"),
    ("ext_equal_var", "ed25519.s", "run_ed25519"),
    ("fe_pow_2252m3", "ed25519.s", "run_ed25519"),
    ("fe_init", "field25519.s", "run_ed25519"),
    ("fe_mul", "field25519.s", "run_ed25519"),
    ("fe_square", "field25519.s", "run_ed25519"),
    ("fe_inv", "field25519.s", "run_ed25519"),
    ("sc_init", "ed25519_scalar.s", "run_ed25519"),
    ("sc_reduce", "ed25519_scalar.s", "run_ed25519"),
    ("sc_mul", "ed25519_scalar.s", "run_ed25519"),
    ("sha512_compact", "sha512_compact.s", "run_ed25519"),
    ("sha512_init", "sha512_interface.s", "run_ed25519"),
    ("sha512_update", "sha512_interface.s", "run_ed25519"),
    ("sha512_final", "sha512_interface.s", "run_ed25519"),
    ("sha512_format_blocks", "sha512_interface.s", "run_ed25519"),
    ("copy", "sha512_interface.s", "run_ed25519"),
    ("reverse_bytes", "sha512_interface.s", "run_ed25519"),
    ("bswap64", "sha512_interface.s", "run_ed25519"),
    ("sha512_pad_message", "sha512_padding.s", "run_ed25519"),
    ("bswap32", "sha512_padding.s", "run_ed25519"),
    # SHA-512 (standalone)
    ("sha512", "sha512.s", "run_sha512"),
    # SHA-256
    ("sha256", "sha256.s", "run_sha256"),
    # P-256
    ("setup_modp", "p256_base.s", "run_p256"),
    ("mul_modp", "p256_base.s", "run_p256"),
    ("mod_inv", "p256_base.s", "run_p256"),
    ("proj_add", "p256_base.s", "run_p256"),
    ("proj_double", "p256_base.s", "run_p256"),
    ("proj_to_affine", "p256_base.s", "run_p256"),
    ("mod_mul_256x256", "p256_base.s", "run_p256"),
    ("mod_mul_320x128", "p256_base.s", "run_p256"),
    ("p256_reduce", "p256_base.s", "run_p256"),
    ("scalar_mult_int", "p256_base.s", "run_p256"),
    ("p256_base_mult", "p256_base.s", "run_p256"),
    ("p256_random_scalar", "p256_base.s", "run_p256"),
    ("p256_generate_random_key", "p256_base.s", "run_p256"),
    ("p256_generate_k", "p256_base.s", "run_p256"),
    ("boolean_to_arithmetic", "p256_base.s", "run_p256"),
    ("p256_key_from_seed", "p256_base.s", "run_p256"),
    ("p256_scalar_remask", "p256_base.s", "run_p256"),
    ("trigger_fault_if_fg0_not_z", "p256_base.s", "run_p256"),
    ("trigger_fault_if_fg0_z", "p256_base.s", "run_p256"),
    ("p256_isoncurve", "p256_isoncurve.s", "run_p256"),
    ("p256_check_public_key", "p256_isoncurve.s", "run_p256"),
    ("p256_isoncurve_proj", "p256_isoncurve_proj.s", "run_p256"),
    ("p256_shared_key", "p256_shared_key.s", "run_p256"),
    ("arithmetic_to_boolean", "p256_shared_key.s", "run_p256"),
    ("arithmetic_to_boolean_mod", "p256_shared_key.s", "run_p256"),
    ("p256_sign", "p256_sign.s", "run_p256"),
    ("p256_verify", "p256_verify.s", "run_p256"),
    ("mod_inv_var", "p256_verify.s", "run_p256"),
    ("copy_share", "run_p256.s", "run_p256"),
    # P-384
    ("p384_mulmod_p", "p384_base.s", "run_p384"),
    ("proj_to_affine_p384", "p384_base.s", "run_p384"),
    ("p384_scalar_remask", "p384_base.s", "run_p384"),
    ("p384_base_mult_checked", "p384_base_mult.s", "run_p384"),
    ("p384_base_mult", "p384_base_mult.s", "run_p384"),
    ("p384_isoncurve", "p384_isoncurve.s", "run_p384"),
    ("p384_isoncurve_check", "p384_isoncurve.s", "run_p384"),
    ("p384_check_public_key", "p384_isoncurve.s", "run_p384"),
    ("trigger_fault_if_fg0_not_z", "p384_isoncurve.s", "run_p384"),
    ("trigger_input_error_if_fg0_not_z", "p384_isoncurve.s", "run_p384"),
    ("p384_isoncurve_proj", "p384_isoncurve_proj.s", "run_p384"),
    ("p384_isoncurve_proj_check", "p384_isoncurve_proj.s", "run_p384"),
    ("scalar_mult_int_p384", "p384_internal_mult.s", "run_p384"),
    ("store_proj_randomize", "p384_internal_mult.s", "run_p384"),
    ("p384_verify", "p384_verify.s", "run_p384"),
    ("p384_sign", "p384_sign.s", "run_p384"),
    ("p384_generate_k", "p384_keygen.s", "run_p384"),
    ("p384_generate_random_key", "p384_keygen.s", "run_p384"),
    ("p384_random_scalar", "p384_keygen.s", "run_p384"),
    ("p384_key_from_seed", "p384_keygen_from_seed.s", "run_p384"),
    ("p384_scalar_mult", "p384_scalar_mult.s", "run_p384"),
    ("mod_inv_p384", "p384_modinv.s", "run_p384"),
    ("p384_arithmetic_to_boolean", "p384_a2b.s", "run_p384"),
    ("p384_arithmetic_to_boolean_mod", "p384_a2b.s", "run_p384"),
    ("p384_boolean_to_arithmetic", "p384_b2a.s", "run_p384"),
    ("copy_share", "run_p384.s", "run_p384"),
    # X25519
    ("X25519", "x25519.s", "x25519_sideload"),
    ("scalar_mult", "x25519.s", "x25519_sideload"),
    ("ladderstep", "x25519.s", "x25519_sideload"),
    # RSA
    ("m0inv", "montmul.s", "rsa"),
    ("mul256_w30xw25", "montmul.s", "rsa"),
    ("mul256_w30xw2", "montmul.s", "rsa"),
    ("mul256_w20xw21", "mul.s", "rsa"),
    ("zero_work_buf", "rsa.s", "rsa"),
    ("cp_work_buf", "rsa.s", "rsa"),
    # RSA keygen
    ("is_zero_mod_small_prime", "rsa_keygen.s", "run_rsa_keygen"),
    # Boot
    ("attestation_secret_key_from_seed", "boot.s", "boot"),
]]

acc_sim_test(
    name = "ed25519_encode_decode_test",
    srcs = [
        "ed25519_encode_decode_test.s",
    ],
    exp = "ed25519_encode_decode_test.exp",
    deps = [
        "//sw/acc/crypto:ed25519",
        "//sw/acc/crypto:ed25519_scalar",
        "//sw/acc/crypto:field25519",
        "//sw/acc/crypto:sha512_compact",
        "//sw/acc/crypto:sha512_interface",
        "//sw/acc/crypto:sha512_padding",
    ],
)

acc_sim_test(
    name = "ed25519_ext_add_test",
    srcs = [
        "ed25519_ext_add_test.s",
    ],
    exp = "ed25519_ext_add_test.exp",
    deps = [
        "//sw/acc/crypto:ed25519",
        "//sw/acc/crypto:ed25519_scalar",
        "//sw/acc/crypto:field25519",
        "//sw/acc/crypto:sha512_compact",
        "//sw/acc/crypto:sha512_interface",
        "//sw/acc/crypto:sha512_padding",
    ],
)

acc_consttime_test(
    name = "ed25519_ext_add_consttime",
    subroutine = "ext_add",
    deps = [
        ":ed25519_ext_add_test",
    ],
)

acc_sim_test(
    name = "ed25519_ext_scmul_test",
    srcs = [
        "ed25519_ext_scmul_test.s",
    ],
    exp = "ed25519_ext_scmul_test.exp",
    deps = [
        "//sw/acc/crypto:ed25519",
        "//sw/acc/crypto:ed25519_scalar",
        "//sw/acc/crypto:field25519",
        "//sw/acc/crypto:sha512_compact",
        "//sw/acc/crypto:sha512_interface",
        "//sw/acc/crypto:sha512_padding",
    ],
)

acc_sim_test(
    name = "ed25519_scalar_test",
    srcs = [
        "ed25519_scalar_test.s",
    ],
    exp = "ed25519_scalar_test.exp",
    deps = [
        "//sw/acc/crypto:ed25519_scalar",
    ],
)

acc_sim_test(
    name = "ed25519_sign_prehashed_test",
    srcs = [
        "ed25519_sign_prehashed_test.s",
    ],
    dexp = "ed25519_sign_prehashed_test.dexp",
    deps = [
        "//sw/acc/crypto:ed25519",
        "//sw/acc/crypto:ed25519_scalar",
        "//sw/acc/crypto:field25519",
        "//sw/acc/crypto:sha512_compact",
        "//sw/acc/crypto:sha512_interface",
        "//sw/acc/crypto:sha512_padding",
    ],
)

acc_sim_test(
    name = "ed25519_verify_test",
    srcs = [
        "ed25519_verify_test.s",
    ],
    exp = "ed25519_verify_test.exp",
    deps = [
        "//sw/acc/crypto:ed25519",
        "//sw/acc/crypto:ed25519_scalar",
        "//sw/acc/crypto:field25519",
        "//sw/acc/crypto:sha512_compact",
        "//sw/acc/crypto:sha512_interface",
        "//sw/acc/crypto:sha512_padding",
    ],
)

acc_sim_test(
    name = "ed25519_verify_test2",
    srcs = [
        "ed25519_verify_test2.s",
    ],
    exp = "ed25519_verify_test2.exp",
    deps = [
        "//sw/acc/crypto:ed25519",
        "//sw/acc/crypto:ed25519_scalar",
        "//sw/acc/crypto:field25519",
        "//sw/acc/crypto:sha512_compact",
        "//sw/acc/crypto:sha512_interface",
        "//sw/acc/crypto:sha512_padding",
    ],
)

acc_sim_test(
    name = "div_large_test",
    srcs = [
        "div_large_test.s",
    ],
    exp = "div_large_test.exp",
    deps = [
        "//sw/acc/crypto:div",
    ],
)

acc_sim_test(
    name = "div_medium_test",
    srcs = [
        "div_medium_test.s",
    ],
    exp = "div_medium_test.exp",
    deps = [
        "//sw/acc/crypto:div",
    ],
)

acc_sim_test(
    name = "div_small_test",
    srcs = [
        "div_small_test.s",
    ],
    exp = "div_small_test.exp",
    deps = [
        "//sw/acc/crypto:div",
    ],
)

acc_consttime_test(
    name = "div_consttime",
    # All secrets are stored in DMEM; timing is permitted to depend on the
    # number of limbs.
    secrets = ["dmem"],
    subroutine = "div",
    deps = [
        ":div_small_test",
    ],
)

acc_sim_test(
    name = "mod_test",
    srcs = [
        "mod_test.s",
    ],
    exp = "mod_test.exp",
    deps = [
        "//sw/acc/crypto:div",
    ],
)

acc_consttime_test(
    name = "mod_consttime",
    # All secrets are stored in DMEM; timing is permitted to depend on the
    # number of limbs.
    secrets = ["dmem"],
    subroutine = "mod",
    deps = [
        ":mod_test",
    ],
)

acc_sim_test(
    name = "field25519_test",
    srcs = [
        "field25519_test.s",
    ],
    exp = "field25519_test.exp",
    deps = [
        "//sw/acc/crypto:field25519",
    ],
)

acc_consttime_test(
    name = "field25519_fe_inv_consttime",
    subroutine = "fe_inv",
    deps = [
        ":field25519_test",
    ],
)

acc_consttime_test(
    name = "field25519_fe_mul_consttime",
    subroutine = "fe_mul",
    deps = [
        ":field25519_test",
    ],
)

acc_consttime_test(
    name = "field25519_fe_square_consttime",
    subroutine = "fe_square",
    deps = [
        ":field25519_test",
    ],
)

acc_sim_test(
    name = "gcd_small_test",
    srcs = [
        "gcd_small_test.s",
    ],
    exp = "gcd_small_test.exp",
    deps = [
        "//sw/acc/crypto:gcd",
    ],
)

acc_sim_test(
    name = "gcd_large_test",
    srcs = [
        "gcd_large_test.s",
    ],
    exp = "gcd_large_test.exp",
    deps = [
        "//sw/acc/crypto:gcd",
    ],
)

acc_consttime_test(
    name = "gcd_consttime",
    # All inputs are in DMEM; no registers are secret.
    secrets = ["dmem"],
    subroutine = "gcd",
    deps = [
        ":gcd_small_test",
    ],
)

acc_sim_test(
    name = "lcm_test",
    srcs = [
        "lcm_test.s",
    ],
    exp = "lcm_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:mul",
    ],
)

acc_consttime_test(
    name = "lcm_consttime",
    # All inputs are in DMEM; no registers are secret.
    secrets = ["dmem"],
    subroutine = "lcm",
    deps = [
        ":lcm_test",
    ],
)

acc_sim_test(
    name = "mul_test",
    srcs = [
        "mul_test.s",
    ],
    dexp = "mul_test.dexp",
    deps = [
        "//sw/acc/crypto:mul",
    ],
)

acc_consttime_test(
    name = "mul_consttime",
    # All inputs are in DMEM; no registers are secret.
    secrets = ["dmem"],
    subroutine = "bignum_mul",
    deps = [
        ":mul_test",
    ],
)

acc_sim_test(
    name = "mul256_test",
    srcs = [
        "mul256_test.s",
    ],
    dexp = "mul256_test.dexp",
    deps = [
        "//sw/acc/crypto:mul",
    ],
)

acc_consttime_test(
    name = "mul256_consttime",
    # All inputs are in DMEM; no registers are secret.
    secrets = ["dmem"],
    subroutine = "bignum_mul256",
    deps = [
        ":mul_test",
    ],
)

acc_sim_test(
    name = "p256_base_mult_test",
    srcs = [
        "p256_base_mult_test.s",
    ],
    exp = "p256_base_mult_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
    ],
)

acc_sim_test(
    name = "p256_scalar_remask_test",
    srcs = [
        "p256_scalar_remask_test.s",
    ],
    exp = "p256_scalar_remask_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
    ],
)

acc_consttime_test(
    name = "p256_base_mult_consttime",
    subroutine = "p256_base_mult",
    deps = [
        "//sw/acc/crypto:run_p256",
    ],
)

acc_consttime_test(
    name = "p256_isoncurve_consttime",
    subroutine = "p256_isoncurve",
    deps = [
        "//sw/acc/crypto:run_p256",
    ],
)

acc_consttime_test(
    name = "p256_key_from_seed_consttime",
    subroutine = "p256_key_from_seed",
    deps = [
        "//sw/acc/crypto:run_p256",
    ],
)

acc_sim_test(
    name = "p256_key_from_seed_test",
    srcs = [
        "p256_key_from_seed_test.s",
    ],
    exp = "p256_key_from_seed_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
    ],
)

acc_sim_test(
    name = "p256_mul_modp_test",
    srcs = [
        "p256_mul_modp_test.s",
    ],
    exp = "p256_mul_modp_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
    ],
)

acc_consttime_test(
    name = "p256_proj_add_consttime",
    subroutine = "proj_add",
    deps = [
        "//sw/acc/crypto:run_p256",
    ],
)

acc_consttime_test(
    name = "p256_shared_key_consttime",
    subroutine = "p256_shared_key",
    deps = [
        "//sw/acc/crypto:run_p256",
    ],
)

# TODO: Add more fine-grained DMEM tracing to the constant-time checker. This
# test fails because p256_sign branches based on some non-secret values from
# DMEM. However, since there are also secret values in DMEM, it's not safe to
# mark DMEM non-secret, and the constant-time checker doesn't currently have
# the ability to track different DMEM regions separately.
#
# acc_consttime_test(
#   name = "p256_sign_consttime",
#   deps = [
#       "//sw/acc/crypto:run_p256"
#   ],
#   subroutine = "p256_sign",
# )

acc_sim_test(
    name = "p256_ecdsa_sign_test",
    srcs = [
        "p256_ecdsa_sign_test.s",
    ],
    exp = "p256_ecdsa_sign_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
        "//sw/acc/crypto:p256_sign",
    ],
)

acc_sim_test(
    name = "p256_ecdsa_verify_test",
    srcs = [
        "p256_ecdsa_verify_test.s",
    ],
    exp = "p256_ecdsa_verify_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
        "//sw/acc/crypto:p256_verify",
    ],
)

acc_sim_test(
    name = "p256_isoncurve_test",
    srcs = [
        "p256_isoncurve_test.s",
    ],
    exp = "p256_isoncurve_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
    ],
)

acc_sim_test(
    name = "p256_isoncurve_proj_test",
    srcs = [
        "p256_isoncurve_proj_test.s",
    ],
    exp = "p256_isoncurve_proj_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
        "//sw/acc/crypto:p256_isoncurve_proj",
    ],
)

acc_sim_test(
    name = "p256_proj_add_test",
    srcs = [
        "p256_proj_add_test.s",
    ],
    exp = "p256_proj_add_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
    ],
)

acc_sim_test(
    name = "p256_proj_double_test",
    srcs = [
        "p256_proj_double_test.s",
    ],
    exp = "p256_proj_double_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
    ],
)

acc_sim_test(
    name = "p256_scalar_mult_test",
    srcs = [
        "p256_scalar_mult_test.s",
    ],
    exp = "p256_scalar_mult_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
    ],
)

acc_sim_test(
    name = "p256_ecdh_shared_key_test",
    srcs = [
        "p256_ecdh_shared_key_test.s",
    ],
    exp = "p256_ecdh_shared_key_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
        "//sw/acc/crypto:p256_isoncurve_proj",
        "//sw/acc/crypto:p256_shared_key",
    ],
)

acc_sim_test(
    name = "p256_arithmetic_to_boolean_test",
    srcs = [
        "p256_arithmetic_to_boolean_test.s",
    ],
    exp = "p256_arithmetic_to_boolean_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
        "//sw/acc/crypto:p256_isoncurve_proj",
        "//sw/acc/crypto:p256_shared_key",
    ],
)

acc_sim_test(
    name = "p256_arithmetic_to_boolean_mod_test",
    srcs = [
        "p256_arithmetic_to_boolean_mod_test.s",
    ],
    exp = "p256_arithmetic_to_boolean_mod_test.exp",
    deps = [
        "//sw/acc/crypto:p256_base",
        "//sw/acc/crypto:p256_isoncurve",
        "//sw/acc/crypto:p256_isoncurve_proj",
        "//sw/acc/crypto:p256_shared_key",
    ],
)

acc_sim_test_suite(
    name = "p256_test",
    binary = "//sw/acc/crypto:run_p256",
    tests = [
        "p256_check_public_key_not_on_curve.hjson",
        "p256_check_public_key_valid.hjson",
        "p256_check_public_key_x_too_large.hjson",
        "p256_check_public_key_y_too_large.hjson",
        "p256_isoncurve_valid.hjson",
        "p256_keygen_valid.hjson",
    ],
)

acc_sim_test(
    name = "p384_scalar_remask_test",
    srcs = [
        "p384_scalar_remask_test.s",
    ],
    exp = "p384_scalar_remask_test.exp",
    deps = [
        "//sw/acc/crypto:p384_base",
    ],
)

acc_sim_test(
    name = "p384_base_mult_test",
    srcs = [
        "p384_base_mult_test.s",
    ],
    testcase = "p384_base_mult_test.hjson",
    deps = [
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_base_mult",
        "//sw/acc/crypto:p384_internal_mult",
        "//sw/acc/crypto:p384_isoncurve",
    ],
)

acc_sim_test(
    name = "p384_base_mult_checked_test",
    srcs = [
        "p384_base_mult_checked_test.s",
    ],
    exp = "p384_base_mult_checked_test.exp",
    deps = [
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_base_mult",
        "//sw/acc/crypto:p384_internal_mult",
        "//sw/acc/crypto:p384_isoncurve",
    ],
)

acc_sim_test(
    name = "p384_boolean_to_arithmetic_test",
    srcs = [
        "p384_boolean_to_arithmetic_test.s",
    ],
    exp = "p384_boolean_to_arithmetic_test.exp",
    deps = [
        "//sw/acc/crypto:p384_b2a",
    ],
)

acc_sim_test(
    name = "p384_arithmetic_to_boolean_test",
    srcs = [
        "p384_arithmetic_to_boolean_test.s",
    ],
    exp = "p384_arithmetic_to_boolean_test.exp",
    deps = [
        "//sw/acc/crypto:p384_a2b",
        "//sw/acc/crypto:p384_base",
    ],
)

acc_sim_test(
    name = "p384_arithmetic_to_boolean_mod_test",
    srcs = [
        "p384_arithmetic_to_boolean_mod_test.s",
    ],
    exp = "p384_arithmetic_to_boolean_mod_test.exp",
    deps = [
        "//sw/acc/crypto:p384_a2b",
        "//sw/acc/crypto:p384_base",
    ],
)

acc_sim_test(
    name = "p384_ecdh_shared_key_test",
    srcs = [
        "p384_ecdh_shared_key_test.s",
    ],
    exp = "p384_ecdh_shared_key_test.exp",
    deps = [
        "//sw/acc/crypto:p384_a2b",
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_internal_mult",
        "//sw/acc/crypto:p384_isoncurve",
        "//sw/acc/crypto:p384_isoncurve_proj",
        "//sw/acc/crypto:p384_scalar_mult",
    ],
)

acc_sim_test(
    name = "p384_ecdsa_sign_test",
    srcs = [
        "p384_ecdsa_sign_test.s",
    ],
    testcase = "p384_ecdsa_sign_test.hjson",
    deps = [
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_internal_mult",
        "//sw/acc/crypto:p384_isoncurve",
        "//sw/acc/crypto:p384_modinv",
        "//sw/acc/crypto:p384_sign",
    ],
)

acc_sim_test(
    name = "p384_ecdsa_verify_test",
    srcs = [
        "p384_ecdsa_verify_test.s",
    ],
    testcase = "p384_ecdsa_verify_test.hjson",
    deps = [
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_isoncurve",
        "//sw/acc/crypto:p384_modinv",
        "//sw/acc/crypto:p384_verify",
    ],
)

acc_sim_test(
    name = "p384_isoncurve_test",
    srcs = [
        "p384_isoncurve_test.s",
    ],
    testcase = "p384_isoncurve_test.hjson",
    deps = [
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_isoncurve",
    ],
)

acc_sim_test(
    name = "p384_isoncurve_proj_test",
    srcs = [
        "p384_isoncurve_proj_test.s",
    ],
    testcase = "p384_isoncurve_proj_test.hjson",
    deps = [
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_isoncurve",
        "//sw/acc/crypto:p384_isoncurve_proj",
    ],
)

acc_sim_test(
    name = "p384_curve_point_valid_test",
    srcs = [
        "p384_curve_point_valid_test.s",
    ],
    testcase = "p384_curve_point_valid_test.hjson",
    deps = [
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_isoncurve",
    ],
)

acc_sim_test(
    name = "p384_keygen_test",
    srcs = [
        "p384_keygen_test.s",
    ],
    exp = "p384_keygen_test.exp",
    deps = [
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_keygen",
    ],
)

acc_sim_test(
    name = "p384_keygen_from_seed_test",
    srcs = [
        "p384_keygen_from_seed_test.s",
    ],
    exp = "p384_keygen_from_seed_test.exp",
    deps = [
        "//sw/acc/crypto:p384_b2a",
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_keygen_from_seed",
    ],
)

acc_sim_test(
    name = "p384_proj_add_test",
    srcs = [
        "p384_proj_add_test.s",
    ],
    exp = "p384_proj_add_test.exp",
    deps = [
        "//sw/acc/crypto:p384_base",
    ],
)

acc_sim_test(
    name = "p384_proj_double_test",
    srcs = [
        "p384_proj_double_test.s",
    ],
    exp = "p384_proj_double_test.exp",
    deps = [
        "//sw/acc/crypto:p384_base",
    ],
)

acc_sim_test(
    name = "p384_scalar_mult_test",
    srcs = [
        "p384_scalar_mult_test.s",
    ],
    exp = "p384_scalar_mult_test.exp",
    deps = [
        "//sw/acc/crypto:p384_base",
        "//sw/acc/crypto:p384_internal_mult",
        "//sw/acc/crypto:p384_isoncurve",
        "//sw/acc/crypto:p384_isoncurve_proj",
        "//sw/acc/crypto:p384_scalar_mult",
    ],
)

acc_sim_test(
    name = "p384_mulmod448x128_test",
    srcs = [
        "p384_mulmod448x128_test.s",
    ],
    exp = "p384_mulmod448x128_test.exp",
    deps = [
        "//sw/acc/crypto:p384_base",
    ],
)

acc_consttime_test(
    name = "p384_base_mult_consttime",
    subroutine = "p384_base_mult",
    deps = [
        ":p384_base_mult_test",
    ],
)

acc_consttime_test(
    name = "p384_scalar_mult_consttime",
    ignore = [
        "trigger_fault_if_fg0_not_z",
    ],
    subroutine = "p384_scalar_mult",
    deps = [
        ":p384_scalar_mult_test",
    ],
)

acc_consttime_test(
    name = "p384_mulmod_p_consttime",
    subroutine = "p384_mulmod_p",
    deps = [
        ":p384_ecdsa_sign_test",
    ],
)

acc_consttime_test(
    name = "p384_mulmod_n_consttime",
    subroutine = "p384_mulmod_n",
    deps = [
        ":p384_ecdsa_sign_test",
    ],
)

# TODO: Add more fine-grained DMEM tracing to the constant-time checker. This
# test fails because p384_sign branches based on some non-secret values from
# DMEM. However, since there are also secret values in DMEM, it's not safe to
# mark DMEM non-secret, and the constant-time checker doesn't currently have
# the ability to track different DMEM regions separately.
#
# acc_consttime_test(
#   name = "p384_sign_consttime",
#   deps = [
#       ":p384_ecdsa_sign_test"
#   ],
#   subroutine = "p384_sign",
# )

acc_consttime_test(
    name = "proj_add_p384_consttime",
    initial_constants = [
        "x22:10",
        "x23:11",
        "x24:16",
        "x25:17",
    ],
    subroutine = "proj_add_p384",
    deps = [
        ":p384_ecdsa_sign_test",
    ],
)

acc_library(
    name = "fake_primality",
    srcs = [
        "fake_primality.s",
    ],
)

acc_sim_test(
    name = "primality_test",
    timeout = "long",
    srcs = [
        "primality_test.s",
    ],
    exp = "primality_test.exp",
    deps = [
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:primality",
    ],
)

acc_sim_test(
    name = "primality_test_witness_test",
    timeout = "long",
    srcs = [
        "primality_test_witness_test.s",
    ],
    exp = "primality_test_witness_test.exp",
    deps = [
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:primality",
    ],
)

acc_sim_test(
    name = "primality_test_witness_negative_test",
    timeout = "long",
    srcs = [
        "primality_test_witness_negative_test.s",
    ],
    exp = "primality_test_witness_negative_test.exp",
    deps = [
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:primality",
    ],
)

acc_sim_test(
    name = "primality_negative_test",
    timeout = "long",
    srcs = [
        "primality_negative_test.s",
    ],
    exp = "primality_negative_test.exp",
    tags = ["nightly"],  # slow, do not run in CI
    deps = [
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:primality",
    ],
)

# Miller-Rabin with 1024-bit primes (as in RSA-2048).
acc_consttime_test(
    name = "miller_rabin_consttime_1024",
    # 4 limbs, x30 = n and x31 = n -1
    initial_constants = [
        "x30:4",
        "x31:3",
    ],
    # All secrets are stored in DMEM; timing is permitted to depend on the
    # number of limbs.
    secrets = ["dmem"],
    subroutine = "miller_rabin",
    deps = [
        ":primality_test",
    ],
)

# Miller-Rabin with 1536-bit primes (as in RSA-3072).
acc_consttime_test(
    name = "miller_rabin_consttime_1536",
    # 6 limbs, x30 = n and x31 = n -1
    initial_constants = [
        "x30:6",
        "x31:5",
    ],
    # All secrets are stored in DMEM; timing is permitted to depend on the
    # number of limbs.
    secrets = ["dmem"],
    subroutine = "miller_rabin",
    deps = [
        ":primality_test",
    ],
)

# Miller-Rabin with 2048-bit primes (as in RSA-4096).
acc_consttime_test(
    name = "miller_rabin_consttime_2048",
    # 8 limbs, x30 = n and x31 = n -1
    initial_constants = [
        "x30:8",
        "x31:7",
    ],
    # All secrets are stored in DMEM; timing is permitted to depend on the
    # number of limbs.
    secrets = ["dmem"],
    subroutine = "miller_rabin",
    deps = [
        ":primality_test",
    ],
)

acc_sim_test(
    name = "modinv_f4_test",
    srcs = [
        "modinv_f4_test.s",
    ],
    exp = "modinv_f4_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "modinv_test",
    srcs = [
        "modinv_test.s",
    ],
    exp = "modinv_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_consttime_test(
    name = "modinv_f4_consttime_test",
    initial_constants = [
        "x20:20",
        "x21:21",
    ],
    # All secrets are stored in DMEM; timing is permitted to depend on the
    # number of limbs.
    secrets = ["dmem"],
    subroutine = "modinv_f4",
    deps = [
        ":modinv_f4_test",
    ],
)

acc_sim_test(
    name = "relprime_f4_test",
    srcs = [
        "relprime_f4_test.s",
    ],
    exp = "relprime_f4_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_consttime_test(
    name = "relprime_f4_consttime_test",
    # All secrets are stored in DMEM; timing is permitted to depend on the
    # number of limbs.
    secrets = ["dmem"],
    subroutine = "relprime_f4",
    deps = [
        ":relprime_f4_test",
    ],
)

acc_sim_test(
    name = "relprime_small_primes_multiple_of_3_test",
    srcs = [
        "relprime_small_primes_multiple_of_3_test.s",
    ],
    exp = "relprime_small_primes_multiple_of_3_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "relprime_small_primes_multiple_of_5_test",
    srcs = [
        "relprime_small_primes_multiple_of_5_test.s",
    ],
    exp = "relprime_small_primes_multiple_of_5_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "relprime_small_primes_multiple_of_7_test",
    srcs = [
        "relprime_small_primes_multiple_of_7_test.s",
    ],
    exp = "relprime_small_primes_multiple_of_7_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "relprime_small_primes_multiple_of_11_test",
    srcs = [
        "relprime_small_primes_multiple_of_11_test.s",
    ],
    exp = "relprime_small_primes_multiple_of_11_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "relprime_small_primes_multiple_of_17_test",
    srcs = [
        "relprime_small_primes_multiple_of_17_test.s",
    ],
    exp = "relprime_small_primes_multiple_of_17_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "relprime_small_primes_multiple_of_31_test",
    srcs = [
        "relprime_small_primes_multiple_of_31_test.s",
    ],
    exp = "relprime_small_primes_multiple_of_31_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "relprime_small_primes_negative_test",
    srcs = [
        "relprime_small_primes_negative_test.s",
    ],
    exp = "relprime_small_primes_negative_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_library(
    name = "rsa_keygen_checkpq_test_data",
    srcs = [
        "rsa_keygen_checkpq_test_data.s",
    ],
)

acc_sim_test(
    name = "rsa_keygen_checkp_good_test",
    timeout = "long",  # runs a primality test
    srcs = [
        "rsa_keygen_checkp_good_test.s",
    ],
    exp = "rsa_keygen_checkp_good_test.exp",
    tags = ["nightly"],  # slow, do not run in CI
    deps = [
        ":rsa_keygen_checkpq_test_data",
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "rsa_keygen_checkp_not_relprime_test",
    srcs = [
        "rsa_keygen_checkp_not_relprime_test.s",
    ],
    exp = "rsa_keygen_checkp_not_relprime_test.exp",
    deps = [
        ":fake_primality",
        ":rsa_keygen_checkpq_test_data",
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "rsa_keygen_checkp_not_prime_test",
    timeout = "long",  # runs a primality test
    srcs = [
        "rsa_keygen_checkp_not_prime_test.s",
    ],
    exp = "rsa_keygen_checkp_not_prime_test.exp",
    deps = [
        ":rsa_keygen_checkpq_test_data",
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "rsa_keygen_checkq_good_test",
    timeout = "long",  # runs a primality test
    srcs = [
        "rsa_keygen_checkq_good_test.s",
    ],
    exp = "rsa_keygen_checkq_good_test.exp",
    tags = ["nightly"],  # slow, do not run in CI
    deps = [
        ":rsa_keygen_checkpq_test_data",
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "rsa_keygen_checkq_not_prime_test",
    timeout = "long",  # runs a primality test
    srcs = [
        "rsa_keygen_checkq_not_prime_test.s",
    ],
    exp = "rsa_keygen_checkq_not_prime_test.exp",
    deps = [
        ":rsa_keygen_checkpq_test_data",
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "rsa_keygen_checkq_not_relprime_test",
    srcs = [
        "rsa_keygen_checkq_not_relprime_test.s",
    ],
    exp = "rsa_keygen_checkq_not_relprime_test.exp",
    deps = [
        ":fake_primality",
        ":rsa_keygen_checkpq_test_data",
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "rsa_keygen_checkq_too_close_test",
    srcs = [
        "rsa_keygen_checkq_too_close_test.s",
    ],
    exp = "rsa_keygen_checkq_too_close_test.exp",
    deps = [
        ":fake_primality",
        ":rsa_keygen_checkpq_test_data",
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "rsa_check_key_recover_d_from_crt_test",
    timeout = "long",
    srcs = [
        "rsa_check_key_recover_d_from_crt_test.s",
    ],
    dexp = "rsa_check_key_recover_d_from_crt_test.dexp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:gcd",
        "//sw/acc/crypto:lcm",
        "//sw/acc/crypto:modinv",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
        "//sw/acc/crypto:primality",
        "//sw/acc/crypto:rsa_keygen",
    ],
)

acc_sim_test(
    name = "rsa_1024_dec_test",
    timeout = "long",
    srcs = [
        "rsa_1024_dec_test.s",
    ],
    exp = "rsa_1024_dec_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_1024_dec_crt_test",
    timeout = "long",
    srcs = [
        "rsa_1024_dec_crt_test.s",
    ],
    exp = "rsa_1024_dec_crt_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_1024_enc_test",
    srcs = [
        "rsa_1024_enc_test.s",
    ],
    exp = "rsa_1024_enc_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_2048_dec_test",
    timeout = "eternal",
    srcs = [
        "rsa_2048_dec_test.s",
    ],
    exp = "rsa_2048_dec_test.exp",
    tags = ["nightly"],  # slow, do not run in CI
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_2048_dec_crt_test",
    timeout = "eternal",
    srcs = [
        "rsa_2048_dec_crt_test.s",
    ],
    exp = "rsa_2048_dec_crt_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_2048_enc_test",
    srcs = [
        "rsa_2048_enc_test.s",
    ],
    exp = "rsa_2048_enc_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_3072_dec_test",
    timeout = "eternal",
    srcs = [
        "rsa_3072_dec_test.s",
    ],
    exp = "rsa_3072_dec_test.exp",
    tags = ["nightly"],  # slow, do not run in CI
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_3072_dec_crt_test",
    timeout = "eternal",
    srcs = [
        "rsa_3072_dec_crt_test.s",
    ],
    exp = "rsa_3072_dec_crt_test.exp",
    tags = ["nightly"],  # slow, do not run in CI
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_3072_enc_test",
    srcs = [
        "rsa_3072_enc_test.s",
    ],
    exp = "rsa_3072_enc_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_4096_enc_test",
    srcs = [
        "rsa_4096_enc_test.s",
    ],
    exp = "rsa_4096_enc_test.exp",
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_4096_dec_test",
    timeout = "eternal",
    srcs = [
        "rsa_4096_dec_test.s",
    ],
    exp = "rsa_4096_dec_test.exp",
    tags = ["nightly"],  # slow, do not run in CI
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "rsa_4096_dec_crt_test",
    timeout = "eternal",
    srcs = [
        "rsa_4096_dec_crt_test.s",
    ],
    exp = "rsa_4096_dec_crt_test.exp",
    tags = ["nightly"],  # slow, do not run in CI
    deps = [
        "//sw/acc/crypto:div",
        "//sw/acc/crypto:modexp",
        "//sw/acc/crypto:montmul",
        "//sw/acc/crypto:mul",
    ],
)

acc_sim_test(
    name = "sha256_test",
    srcs = [
        "sha256_test.s",
    ],
    exp = "sha256_test.exp",
    deps = [
        "//sw/acc/crypto:sha256",
    ],
)

acc_consttime_test(
    name = "sha256_consttime",
    # All secrets are stored in DMEM; timing is permitted to depend on the
    # number of message chunks.
    secrets = ["dmem"],
    subroutine = "sha256",
    deps = [
        ":sha256_test",
    ],
)

acc_sim_test(
    name = "sha512_test",
    srcs = [
        "sha512_test.s",
    ],
    exp = "sha512_test.exp",
    deps = [
        "//sw/acc/crypto:sha512",
    ],
)

acc_sim_test(
    name = "sha512_compact_test",
    srcs = [
        "sha512_compact_test.s",
    ],
    exp = "sha512_compact_test.exp",
    deps = [
        "//sw/acc/crypto:sha512_compact",
    ],
)

acc_sim_test(
    name = "sha512_padding_test",
    srcs = [
        "sha512_padding_test.s",
    ],
    exp = "sha512_padding_test.exp",
    deps = [
        "//sw/acc/crypto:sha512_padding",
    ],
)

acc_sim_test(
    name = "sha512_interface_test",
    srcs = [
        "sha512_interface_test.s",
    ],
    exp = "sha512_interface_test.exp",
    deps = [
        "//sw/acc/crypto:sha512_compact",
        "//sw/acc/crypto:sha512_interface",
        "//sw/acc/crypto:sha512_padding",
    ],
)

acc_sim_test(
    name = "sha384_test",
    srcs = [
        "sha384_test.s",
    ],
    exp = "sha384_test.exp",
    deps = [
        "//sw/acc/crypto:sha512",
    ],
)

acc_sim_test(
    name = "sha3_shake_test",
    srcs = [
        "sha3_shake_test.s",
    ],
    exp = "sha3_shake_test.exp",
    deps = [
        "//sw/acc/crypto:sha3_shake",
    ],
)

acc_sim_test(
    name = "x25519_test1",
    srcs = [
        "x25519_test1.s",
    ],
    exp = "x25519_test1.exp",
    deps = [
        "//sw/acc/crypto:field25519",
        "//sw/acc/crypto:x25519",
    ],
)

acc_sim_test(
    name = "x25519_test2",
    srcs = [
        "x25519_test2.s",
    ],
    exp = "x25519_test2.exp",
    deps = [
        "//sw/acc/crypto:field25519",
        "//sw/acc/crypto:x25519",
    ],
)

acc_consttime_test(
    name = "x25519_consttime",
    subroutine = "X25519",
    deps = [
        ":x25519_test1",
    ],
)

acc_sim_test_suite(
    name = "boot_test",
    binary = "//sw/acc/crypto:boot",
    tests = [
        "boot_key_endorse_valid.hjson",
        "boot_key_save_valid.hjson",
        "boot_keygen_valid.hjson",
        "boot_mode_invalid.hjson",
        "boot_sigverify_valid.hjson",
    ],
)
