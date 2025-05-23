# Copyright lowRISC contributors (OpenTitan project).
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
#
# ------------------- W A R N I N G: A U T O - G E N E R A T E D   C O D E !! -------------------#
# PLEASE DO NOT HAND-EDIT THIS FILE. IT HAS BEEN AUTO-GENERATED WITH THE FOLLOWING COMMAND:
# util/topgen.py -t hw/top_daric2/data/top_daric2.hjson
# -o hw/top_daric2

load("//rules/opentitan:hw.bzl", "opentitan_top")
load("//hw/top_daric2/ip_autogen/ac_range_check:defs.bzl", "AC_RANGE_CHECK")
load("//hw/ip/aes:defs.bzl", "AES")
load("//hw/top_daric2/ip_autogen/alert_handler:defs.bzl", "ALERT_HANDLER")
load("//hw/ip/aon_timer:defs.bzl", "AON_TIMER")
load("//hw/top_daric2/ip_autogen/clkmgr:defs.bzl", "CLKMGR")
load("//hw/ip/csrng:defs.bzl", "CSRNG")
load("//hw/ip/dma:defs.bzl", "DMA")
load("//hw/ip/edn:defs.bzl", "EDN")
load("//hw/top_daric2/ip_autogen/gpio:defs.bzl", "GPIO")
load("//hw/ip/hmac:defs.bzl", "HMAC")
load("//hw/ip/keymgr_dpe:defs.bzl", "KEYMGR_DPE")
load("//hw/ip/kmac:defs.bzl", "KMAC")
load("//hw/ip/lc_ctrl:defs.bzl", "LC_CTRL")
load("//hw/ip/mbx:defs.bzl", "MBX")
load("//hw/ip/otbn:defs.bzl", "OTBN")
load("//hw/top_daric2/ip_autogen/otp_ctrl:defs.bzl", "OTP_CTRL")
load("//hw/ip/otp_macro:defs.bzl", "OTP_MACRO")
load("//hw/top_daric2/ip_autogen/pinmux:defs.bzl", "PINMUX")
load("//hw/top_daric2/ip_autogen/pwrmgr:defs.bzl", "PWRMGR")
load("//hw/top_daric2/ip_autogen/racl_ctrl:defs.bzl", "RACL_CTRL")
load("//hw/ip/rom_ctrl:defs.bzl", "ROM_CTRL")
load("//hw/top_daric2/ip_autogen/rstmgr:defs.bzl", "RSTMGR")
load("//hw/top_daric2/ip_autogen/rv_core_ibex:defs.bzl", "RV_CORE_IBEX")
load("//hw/ip/rv_dm:defs.bzl", "RV_DM")
load("//hw/top_daric2/ip_autogen/rv_plic:defs.bzl", "RV_PLIC")
load("//hw/ip/rv_timer:defs.bzl", "RV_TIMER")
load("//hw/ip/soc_dbg_ctrl:defs.bzl", "SOC_DBG_CTRL")
load("//hw/top_daric2/ip/soc_proxy:defs.bzl", "SOC_PROXY")
load("//hw/ip/sram_ctrl:defs.bzl", "SRAM_CTRL")
load("//hw/ip/uart:defs.bzl", "UART")

DARIC2 = opentitan_top(
    name = "daric2",
    hjson = "//hw/top_daric2/data/autogen:top_daric2.gen.hjson",
    top_lib = "//hw/top_daric2/sw/autogen:top_daric2",
    top_ld = "//hw/top_daric2/sw/autogen:top_daric2_memory",
    ips = [
        AC_RANGE_CHECK,
        AES,
        ALERT_HANDLER,
        AON_TIMER,
        CLKMGR,
        CSRNG,
        DMA,
        EDN,
        GPIO,
        HMAC,
        KEYMGR_DPE,
        KMAC,
        LC_CTRL,
        MBX,
        OTBN,
        OTP_CTRL,
        OTP_MACRO,
        PINMUX,
        PWRMGR,
        RACL_CTRL,
        ROM_CTRL,
        RSTMGR,
        RV_CORE_IBEX,
        RV_DM,
        RV_PLIC,
        RV_TIMER,
        SOC_DBG_CTRL,
        SOC_PROXY,
        SRAM_CTRL,
        UART,
    ],
)
