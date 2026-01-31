# Copyright lowRISC contributors (OpenTitan project).
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("//hw/top_darjeeling:defs.bzl", "DARJEELING_SLOTS")
load(
    "//rules/opentitan:defs.bzl",
    "DEFAULT_TEST_FAILURE_MSG",
    "DEFAULT_TEST_SUCCESS_MSG",
    "fpga_vcu118",
    "sim_dv",
    "sim_verilator",
)

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "rtl_files",
    srcs = glob(["**"]) + [
        "//hw/top_darjeeling/data:all_files",
        "//hw/top_darjeeling/dv/verilator:all_files",
        "//hw/top_darjeeling/ip:rtl_files",
        "//hw/top_darjeeling/sw:all_files",
    ],
)

filegroup(
    name = "doc_files",
    srcs = glob(["**/*.md"]) + [
        "//hw/top_darjeeling/ip_autogen/ac_range_check:doc_files",
        "//hw/top_darjeeling/ip_autogen/alert_handler:doc_files",
        "//hw/top_darjeeling/ip_autogen/clkmgr:doc_files",
        "//hw/top_darjeeling/ip_autogen/gpio:doc_files",
        "//hw/top_darjeeling/ip_autogen/otp_ctrl:doc_files",
        "//hw/top_darjeeling/ip_autogen/pinmux:doc_files",
        "//hw/top_darjeeling/ip_autogen/pwrmgr:doc_files",
        "//hw/top_darjeeling/ip_autogen/racl_ctrl:doc_files",
        "//hw/top_darjeeling/ip_autogen/rstmgr:doc_files",
        "//hw/top_darjeeling/ip_autogen/rv_core_ibex:doc_files",
        "//hw/top_darjeeling/ip_autogen/rv_plic:doc_files",
    ],
)

###########################################################################
# Sim Verilator Environments
#
# The sim_verilator_base target is only meant to be used for building ROMs
# and other items without `testonly=True`.
###########################################################################
sim_verilator(
    name = "sim_verilator_base",
    design = "darjeeling",
    exec_env = "sim_verilator",
    libs = [
        "//sw/device/lib/arch:boot_stage_rom_ext",
        "//sw/device/lib/arch:sim_verilator",
        "//hw/top_darjeeling/sw/dt:sim_verilator",
    ],
    linker_script = "//sw/device/lib/testing/test_framework:ottf_ld_silicon_creator_slot_a",
    otp = "//hw/top_darjeeling/data/otp:img_rma",
    slot_spec = DARJEELING_SLOTS,
    test_cmd = "testing-not-supported",
)

sim_verilator(
    name = "sim_verilator",
    testonly = True,
    args = [
        "--rcfile=",
        "--logging=info",
        "--interface=verilator",
        "--verilator-bin=$(rootpath //hw:verilator)",
        "--verilator-rom={rom}",
        "--verilator-otp={otp}",
        "--verilator-ctn-ram={firmware}",
    ],
    base = ":sim_verilator_base",
    data = [
        "//hw:fusesoc_ignore",
        "//hw:verilator",
    ],
    exec_env = "sim_verilator",
    param = {
        "exit_success": DEFAULT_TEST_SUCCESS_MSG,
        "exit_failure": DEFAULT_TEST_FAILURE_MSG,
    },
    rom = "//sw/device/lib/testing/test_rom:test_rom",
    test_cmd = """
        --exec="console --non-interactive --exit-success='{exit_success}' --exit-failure='{exit_failure}'"
        no-op
    """,
)

###########################################################################
# FPGA VCU118 Environments
###########################################################################
fpga_vcu118(
    name = "fpga_vcu118",
    design = "darjeeling",
    exec_env = "fpga_vcu118",
    libs = [
        "//sw/device/lib/arch:boot_stage_rom_ext",
        "//sw/device/lib/arch:fpga_vcu118",
        "//hw/top_darjeeling/sw/dt:fpga_vcu118",
    ],
    linker_script = "//sw/device/lib/testing/test_framework:ottf_ld_silicon_creator_slot_a",
    otp_mmap = "//hw/top_darjeeling/data/otp:otp_ctrl_mmap.hjson",
    slot_spec = DARJEELING_SLOTS,
    test_cmd = "testing-not-supported",
)

# VCU118 with the test ROM spliced, no second ROM; firmware is bootstrapped and
# executed in the ROM_EXT stage.
fpga_vcu118(
    name = "fpga_vcu118_test_rom",
    testonly = True,
    base = ":fpga_vcu118",
    base_bitstream = "//hw/bitstream/vcu118:bitstream",
    exec_env = "fpga_vcu118_test_rom",
    mmi = "//hw/bitstream/vcu118:mmi",
    otp = "//hw/top_darjeeling/data/otp:img_prod",
    param = {
        "interface": "vcu118",
        "exit_success": DEFAULT_TEST_SUCCESS_MSG,
        "exit_failure": DEFAULT_TEST_FAILURE_MSG,
        # Place the firmware in the ROM_EXT stage, because this exec_env
        # doesn't run with a real ROM_EXT.
        "assemble": "{firmware}@{rom_ext_ctn}",
    },
    rom = "//sw/device/lib/testing/test_rom:test_rom",
    test_cmd = """
        --exec="transport init"
        --exec="fpga load-bitstream --vivado {vivado} {bitstream}"
        --exec="bootstrap --clear-uart=true {firmware}"
        --exec="console --non-interactive --exit-success='{exit_success}' --exit-failure='{exit_failure}'"
        no-op
    """,
)

# VCU118 with `rom_with_fake_keys` and second ROM spliced; firmware is
# bootstrapped to CTN SRAM and executed in the ROM_EXT stage.
fpga_vcu118(
    name = "fpga_vcu118_rom_with_fake_keys",
    testonly = True,
    base = ":fpga_vcu118",
    base_bitstream = "//hw/bitstream/vcu118:bitstream",
    ecdsa_key = {"//sw/device/silicon_creator/rom/keys/fake/ecdsa:test_key_0_ecdsa_p256": "test_key_0"},
    exec_env = "fpga_vcu118_rom_with_fake_keys",
    manifest = "//sw/device/silicon_creator/rom_ext:manifest",
    mmi = "//hw/bitstream/vcu118:mmi",
    otp = "//hw/top_darjeeling/data/otp:img_rma",
    param = {
        "interface": "vcu118",
        "exit_success": DEFAULT_TEST_SUCCESS_MSG,
        "exit_failure": DEFAULT_TEST_FAILURE_MSG,
        # Place the firmware in the ROM_EXT stage, because this exec_env
        # doesn't run with a real ROM_EXT.
        "assemble": "{firmware}@{rom_ext_ctn}",
    },
    rom = "//sw/device/silicon_creator/rom:base_rom",
    second_rom = "//sw/device/silicon_creator/rom:second_rom",
    test_cmd = """
        --exec="transport init"
        --exec="fpga load-bitstream --vivado {vivado} {bitstream}"
        --exec="bootstrap --clear-uart=true {firmware}"
        --exec="console --non-interactive --exit-success='{exit_success}' --exit-failure='{exit_failure}'"
        no-op
    """,
)

# VCU118 with base ROM and second ROM spliced; firmware is bootstrapped to CTN
# SRAM and executed in the ROM_EXT stage.
fpga_vcu118(
    name = "fpga_vcu118_base_rom",
    testonly = True,
    base = ":fpga_vcu118_rom_with_fake_keys",
    ecdsa_key = {"//sw/device/silicon_creator/rom/keys/fake/ecdsa:prod_key_0_ecdsa_p256": "prod_key_0"},
    exec_env = "fpga_vcu118_base_rom",
    libs = [
        "//sw/device/lib/arch:boot_stage_owner",
        "//sw/device/lib/arch:fpga_vcu118",
        "//hw/top_darjeeling/sw/dt:fpga_vcu118",
    ],
    manifest = "//sw/device/silicon_owner:manifest",
)

# VCU118 with base ROM and second ROM spliced; ROM_EXT and firmware are
# bootstrapped. Firmware executes in the `owner` stage.
fpga_vcu118(
    name = "fpga_vcu118_rom_ext",
    testonly = True,
    base = ":fpga_vcu118_rom_with_base_rom",
    exec_env = "fpga_vcu118_rom_ext",
    manifest = "//sw/device/silicon_owner:manifest",
    param = {
        "interface": "vcu118",
        "exit_success": DEFAULT_TEST_SUCCESS_MSG,
        "exit_failure": DEFAULT_TEST_FAILURE_MSG,
        "assemble": "{rom_ext}@{rom_ext_ctn} {firmware}@{owner_ctn}",
    },
    rom_ext = "//sw/device/silicon_creator/rom_ext:rom_ext_dice_x509",
)

###########################################################################
# Sim DV Environments
#
# The sim_dv_base target is only meant to be used for building ROMs and
# other items without `testonly=True`.
###########################################################################
# Remark: we must use a different name from earlgrey because the test point
# names are derived from the exec_env's target named
sim_dv(
    name = "sim_dv_base",
    design = "darjeeling",
    exec_env = "sim_dv",
    extract_sw_logs = "//util/device_sw_utils:extract_sw_logs_db",
    flash_scramble_tool = "//util/design:gen-flash-img",
    libs = [
        "//sw/device/lib/arch:boot_stage_rom_ext",
        "//sw/device/lib/arch:sim_dv",
        "//hw/top_darjeeling/sw/dt:sim_dv",
    ],
    linker_script = "//sw/device/lib/testing/test_framework:ottf_ld_silicon_creator_slot_a",
    otp_mmap = "//hw/top_darjeeling/data/otp:otp_ctrl_mmap.hjson",
    slot_spec = DARJEELING_SLOTS,
)

sim_dv(
    name = "sim_dv",
    testonly = True,
    base = ":sim_dv_base",
    exec_env = "sim_dv",
    rom = "//sw/device/lib/testing/test_rom:test_rom",
)
