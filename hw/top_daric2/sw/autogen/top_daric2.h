// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// ------------------- W A R N I N G: A U T O - G E N E R A T E D   C O D E !! -------------------//
// PLEASE DO NOT HAND-EDIT THIS FILE. IT HAS BEEN AUTO-GENERATED WITH THE FOLLOWING COMMAND:
// util/topgen.py -t hw/top_daric2/data/top_daric2.hjson
// -o hw/top_daric2

#ifndef OPENTITAN_HW_TOP_DARIC2_SW_AUTOGEN_TOP_DARIC2_H_
#define OPENTITAN_HW_TOP_DARIC2_SW_AUTOGEN_TOP_DARIC2_H_

/**
 * @file
 * @brief Top-specific Definitions
 *
 * This file contains preprocessor and type definitions for use within the
 * device C/C++ codebase.
 *
 * These definitions are for information that depends on the top-specific chip
 * configuration, which includes:
 * - Device Memory Information (for Peripherals and Memory)
 * - PLIC Interrupt ID Names and Source Mappings
 * - Alert ID Names and Source Mappings
 * - Pinmux Pin/Select Names
 * - Power Manager Wakeups
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Peripheral base address for uart0 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_UART0_BASE_ADDR 0x30010000u

/**
 * Peripheral size for uart0 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_UART0_BASE_ADDR and
 * `TOP_DARIC2_UART0_BASE_ADDR + TOP_DARIC2_UART0_SIZE_BYTES`.
 */
#define TOP_DARIC2_UART0_SIZE_BYTES 0x40u

/**
 * Peripheral base address for gpio in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_GPIO_BASE_ADDR 0x30000000u

/**
 * Peripheral size for gpio in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_GPIO_BASE_ADDR and
 * `TOP_DARIC2_GPIO_BASE_ADDR + TOP_DARIC2_GPIO_SIZE_BYTES`.
 */
#define TOP_DARIC2_GPIO_SIZE_BYTES 0x100u

/**
 * Peripheral base address for rv_timer in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_RV_TIMER_BASE_ADDR 0x30100000u

/**
 * Peripheral size for rv_timer in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_RV_TIMER_BASE_ADDR and
 * `TOP_DARIC2_RV_TIMER_BASE_ADDR + TOP_DARIC2_RV_TIMER_SIZE_BYTES`.
 */
#define TOP_DARIC2_RV_TIMER_SIZE_BYTES 0x200u

/**
 * Peripheral base address for core device on otp_ctrl in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_OTP_CTRL_CORE_BASE_ADDR 0x30130000u

/**
 * Peripheral size for core device on otp_ctrl in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_OTP_CTRL_CORE_BASE_ADDR and
 * `TOP_DARIC2_OTP_CTRL_CORE_BASE_ADDR + TOP_DARIC2_OTP_CTRL_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_OTP_CTRL_CORE_SIZE_BYTES 0x8000u

/**
 * Peripheral base address for otp_macro in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_OTP_MACRO_BASE_ADDR 0x30140000u

/**
 * Peripheral size for otp_macro in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_OTP_MACRO_BASE_ADDR and
 * `TOP_DARIC2_OTP_MACRO_BASE_ADDR + TOP_DARIC2_OTP_MACRO_SIZE_BYTES`.
 */
#define TOP_DARIC2_OTP_MACRO_SIZE_BYTES 0x20u

/**
 * Peripheral base address for regs device on lc_ctrl in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_LC_CTRL_REGS_BASE_ADDR 0x30150000u

/**
 * Peripheral size for regs device on lc_ctrl in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_LC_CTRL_REGS_BASE_ADDR and
 * `TOP_DARIC2_LC_CTRL_REGS_BASE_ADDR + TOP_DARIC2_LC_CTRL_REGS_SIZE_BYTES`.
 */
#define TOP_DARIC2_LC_CTRL_REGS_SIZE_BYTES 0x100u

/**
 * Peripheral base address for alert_handler in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_ALERT_HANDLER_BASE_ADDR 0x30160000u

/**
 * Peripheral size for alert_handler in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_ALERT_HANDLER_BASE_ADDR and
 * `TOP_DARIC2_ALERT_HANDLER_BASE_ADDR + TOP_DARIC2_ALERT_HANDLER_SIZE_BYTES`.
 */
#define TOP_DARIC2_ALERT_HANDLER_SIZE_BYTES 0x800u

/**
 * Peripheral base address for pwrmgr_aon in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_PWRMGR_AON_BASE_ADDR 0x30400000u

/**
 * Peripheral size for pwrmgr_aon in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_PWRMGR_AON_BASE_ADDR and
 * `TOP_DARIC2_PWRMGR_AON_BASE_ADDR + TOP_DARIC2_PWRMGR_AON_SIZE_BYTES`.
 */
#define TOP_DARIC2_PWRMGR_AON_SIZE_BYTES 0x80u

/**
 * Peripheral base address for rstmgr_aon in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_RSTMGR_AON_BASE_ADDR 0x30410000u

/**
 * Peripheral size for rstmgr_aon in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_RSTMGR_AON_BASE_ADDR and
 * `TOP_DARIC2_RSTMGR_AON_BASE_ADDR + TOP_DARIC2_RSTMGR_AON_SIZE_BYTES`.
 */
#define TOP_DARIC2_RSTMGR_AON_SIZE_BYTES 0x40u

/**
 * Peripheral base address for clkmgr_aon in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_CLKMGR_AON_BASE_ADDR 0x30420000u

/**
 * Peripheral size for clkmgr_aon in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_CLKMGR_AON_BASE_ADDR and
 * `TOP_DARIC2_CLKMGR_AON_BASE_ADDR + TOP_DARIC2_CLKMGR_AON_SIZE_BYTES`.
 */
#define TOP_DARIC2_CLKMGR_AON_SIZE_BYTES 0x40u

/**
 * Peripheral base address for pinmux_aon in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_PINMUX_AON_BASE_ADDR 0x30460000u

/**
 * Peripheral size for pinmux_aon in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_PINMUX_AON_BASE_ADDR and
 * `TOP_DARIC2_PINMUX_AON_BASE_ADDR + TOP_DARIC2_PINMUX_AON_SIZE_BYTES`.
 */
#define TOP_DARIC2_PINMUX_AON_SIZE_BYTES 0x800u

/**
 * Peripheral base address for aon_timer_aon in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_AON_TIMER_AON_BASE_ADDR 0x30470000u

/**
 * Peripheral size for aon_timer_aon in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_AON_TIMER_AON_BASE_ADDR and
 * `TOP_DARIC2_AON_TIMER_AON_BASE_ADDR + TOP_DARIC2_AON_TIMER_AON_SIZE_BYTES`.
 */
#define TOP_DARIC2_AON_TIMER_AON_SIZE_BYTES 0x40u

/**
 * Peripheral base address for core device on soc_proxy in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_SOC_PROXY_CORE_BASE_ADDR 0x22030000u

/**
 * Peripheral size for core device on soc_proxy in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_SOC_PROXY_CORE_BASE_ADDR and
 * `TOP_DARIC2_SOC_PROXY_CORE_BASE_ADDR + TOP_DARIC2_SOC_PROXY_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_SOC_PROXY_CORE_SIZE_BYTES 0x10u

/**
 * Peripheral base address for ctn device on soc_proxy in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_SOC_PROXY_CTN_BASE_ADDR 0x40000000u

/**
 * Peripheral size for ctn device on soc_proxy in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_SOC_PROXY_CTN_BASE_ADDR and
 * `TOP_DARIC2_SOC_PROXY_CTN_BASE_ADDR + TOP_DARIC2_SOC_PROXY_CTN_SIZE_BYTES`.
 */
#define TOP_DARIC2_SOC_PROXY_CTN_SIZE_BYTES 0x40000000u

/**
 * Peripheral base address for regs device on sram_ctrl_ret_aon in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_SRAM_CTRL_RET_AON_REGS_BASE_ADDR 0x30500000u

/**
 * Peripheral size for regs device on sram_ctrl_ret_aon in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_SRAM_CTRL_RET_AON_REGS_BASE_ADDR and
 * `TOP_DARIC2_SRAM_CTRL_RET_AON_REGS_BASE_ADDR + TOP_DARIC2_SRAM_CTRL_RET_AON_REGS_SIZE_BYTES`.
 */
#define TOP_DARIC2_SRAM_CTRL_RET_AON_REGS_SIZE_BYTES 0x40u

/**
 * Peripheral base address for ram device on sram_ctrl_ret_aon in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_SRAM_CTRL_RET_AON_RAM_BASE_ADDR 0x30600000u

/**
 * Peripheral size for ram device on sram_ctrl_ret_aon in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_SRAM_CTRL_RET_AON_RAM_BASE_ADDR and
 * `TOP_DARIC2_SRAM_CTRL_RET_AON_RAM_BASE_ADDR + TOP_DARIC2_SRAM_CTRL_RET_AON_RAM_SIZE_BYTES`.
 */
#define TOP_DARIC2_SRAM_CTRL_RET_AON_RAM_SIZE_BYTES 0x1000u

/**
 * Peripheral base address for regs device on rv_dm in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_RV_DM_REGS_BASE_ADDR 0x21200000u

/**
 * Peripheral size for regs device on rv_dm in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_RV_DM_REGS_BASE_ADDR and
 * `TOP_DARIC2_RV_DM_REGS_BASE_ADDR + TOP_DARIC2_RV_DM_REGS_SIZE_BYTES`.
 */
#define TOP_DARIC2_RV_DM_REGS_SIZE_BYTES 0x10u

/**
 * Peripheral base address for mem device on rv_dm in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_RV_DM_MEM_BASE_ADDR 0x40000u

/**
 * Peripheral size for mem device on rv_dm in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_RV_DM_MEM_BASE_ADDR and
 * `TOP_DARIC2_RV_DM_MEM_BASE_ADDR + TOP_DARIC2_RV_DM_MEM_SIZE_BYTES`.
 */
#define TOP_DARIC2_RV_DM_MEM_SIZE_BYTES 0x1000u

/**
 * Peripheral base address for rv_plic in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_RV_PLIC_BASE_ADDR 0x28000000u

/**
 * Peripheral size for rv_plic in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_RV_PLIC_BASE_ADDR and
 * `TOP_DARIC2_RV_PLIC_BASE_ADDR + TOP_DARIC2_RV_PLIC_SIZE_BYTES`.
 */
#define TOP_DARIC2_RV_PLIC_SIZE_BYTES 0x8000000u

/**
 * Peripheral base address for aes in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_AES_BASE_ADDR 0x21100000u

/**
 * Peripheral size for aes in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_AES_BASE_ADDR and
 * `TOP_DARIC2_AES_BASE_ADDR + TOP_DARIC2_AES_SIZE_BYTES`.
 */
#define TOP_DARIC2_AES_SIZE_BYTES 0x100u

/**
 * Peripheral base address for hmac in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_HMAC_BASE_ADDR 0x21110000u

/**
 * Peripheral size for hmac in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_HMAC_BASE_ADDR and
 * `TOP_DARIC2_HMAC_BASE_ADDR + TOP_DARIC2_HMAC_SIZE_BYTES`.
 */
#define TOP_DARIC2_HMAC_SIZE_BYTES 0x2000u

/**
 * Peripheral base address for kmac in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_KMAC_BASE_ADDR 0x21120000u

/**
 * Peripheral size for kmac in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_KMAC_BASE_ADDR and
 * `TOP_DARIC2_KMAC_BASE_ADDR + TOP_DARIC2_KMAC_SIZE_BYTES`.
 */
#define TOP_DARIC2_KMAC_SIZE_BYTES 0x1000u

/**
 * Peripheral base address for otbn in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_OTBN_BASE_ADDR 0x21130000u

/**
 * Peripheral size for otbn in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_OTBN_BASE_ADDR and
 * `TOP_DARIC2_OTBN_BASE_ADDR + TOP_DARIC2_OTBN_SIZE_BYTES`.
 */
#define TOP_DARIC2_OTBN_SIZE_BYTES 0x10000u

/**
 * Peripheral base address for keymgr_dpe in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_KEYMGR_DPE_BASE_ADDR 0x21140000u

/**
 * Peripheral size for keymgr_dpe in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_KEYMGR_DPE_BASE_ADDR and
 * `TOP_DARIC2_KEYMGR_DPE_BASE_ADDR + TOP_DARIC2_KEYMGR_DPE_SIZE_BYTES`.
 */
#define TOP_DARIC2_KEYMGR_DPE_SIZE_BYTES 0x100u

/**
 * Peripheral base address for csrng in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_CSRNG_BASE_ADDR 0x21150000u

/**
 * Peripheral size for csrng in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_CSRNG_BASE_ADDR and
 * `TOP_DARIC2_CSRNG_BASE_ADDR + TOP_DARIC2_CSRNG_SIZE_BYTES`.
 */
#define TOP_DARIC2_CSRNG_SIZE_BYTES 0x80u

/**
 * Peripheral base address for edn0 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_EDN0_BASE_ADDR 0x21170000u

/**
 * Peripheral size for edn0 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_EDN0_BASE_ADDR and
 * `TOP_DARIC2_EDN0_BASE_ADDR + TOP_DARIC2_EDN0_SIZE_BYTES`.
 */
#define TOP_DARIC2_EDN0_SIZE_BYTES 0x80u

/**
 * Peripheral base address for edn1 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_EDN1_BASE_ADDR 0x21180000u

/**
 * Peripheral size for edn1 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_EDN1_BASE_ADDR and
 * `TOP_DARIC2_EDN1_BASE_ADDR + TOP_DARIC2_EDN1_SIZE_BYTES`.
 */
#define TOP_DARIC2_EDN1_SIZE_BYTES 0x80u

/**
 * Peripheral base address for regs device on sram_ctrl_main in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_SRAM_CTRL_MAIN_REGS_BASE_ADDR 0x211C0000u

/**
 * Peripheral size for regs device on sram_ctrl_main in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_SRAM_CTRL_MAIN_REGS_BASE_ADDR and
 * `TOP_DARIC2_SRAM_CTRL_MAIN_REGS_BASE_ADDR + TOP_DARIC2_SRAM_CTRL_MAIN_REGS_SIZE_BYTES`.
 */
#define TOP_DARIC2_SRAM_CTRL_MAIN_REGS_SIZE_BYTES 0x40u

/**
 * Peripheral base address for ram device on sram_ctrl_main in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_SRAM_CTRL_MAIN_RAM_BASE_ADDR 0x10000000u

/**
 * Peripheral size for ram device on sram_ctrl_main in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_SRAM_CTRL_MAIN_RAM_BASE_ADDR and
 * `TOP_DARIC2_SRAM_CTRL_MAIN_RAM_BASE_ADDR + TOP_DARIC2_SRAM_CTRL_MAIN_RAM_SIZE_BYTES`.
 */
#define TOP_DARIC2_SRAM_CTRL_MAIN_RAM_SIZE_BYTES 0x10000u

/**
 * Peripheral base address for regs device on sram_ctrl_mbox in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_SRAM_CTRL_MBOX_REGS_BASE_ADDR 0x211D0000u

/**
 * Peripheral size for regs device on sram_ctrl_mbox in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_SRAM_CTRL_MBOX_REGS_BASE_ADDR and
 * `TOP_DARIC2_SRAM_CTRL_MBOX_REGS_BASE_ADDR + TOP_DARIC2_SRAM_CTRL_MBOX_REGS_SIZE_BYTES`.
 */
#define TOP_DARIC2_SRAM_CTRL_MBOX_REGS_SIZE_BYTES 0x40u

/**
 * Peripheral base address for ram device on sram_ctrl_mbox in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_SRAM_CTRL_MBOX_RAM_BASE_ADDR 0x11000000u

/**
 * Peripheral size for ram device on sram_ctrl_mbox in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_SRAM_CTRL_MBOX_RAM_BASE_ADDR and
 * `TOP_DARIC2_SRAM_CTRL_MBOX_RAM_BASE_ADDR + TOP_DARIC2_SRAM_CTRL_MBOX_RAM_SIZE_BYTES`.
 */
#define TOP_DARIC2_SRAM_CTRL_MBOX_RAM_SIZE_BYTES 0x1000u

/**
 * Peripheral base address for regs device on rom_ctrl0 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_ROM_CTRL0_REGS_BASE_ADDR 0x211E0000u

/**
 * Peripheral size for regs device on rom_ctrl0 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_ROM_CTRL0_REGS_BASE_ADDR and
 * `TOP_DARIC2_ROM_CTRL0_REGS_BASE_ADDR + TOP_DARIC2_ROM_CTRL0_REGS_SIZE_BYTES`.
 */
#define TOP_DARIC2_ROM_CTRL0_REGS_SIZE_BYTES 0x80u

/**
 * Peripheral base address for rom device on rom_ctrl0 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_ROM_CTRL0_ROM_BASE_ADDR 0x8000u

/**
 * Peripheral size for rom device on rom_ctrl0 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_ROM_CTRL0_ROM_BASE_ADDR and
 * `TOP_DARIC2_ROM_CTRL0_ROM_BASE_ADDR + TOP_DARIC2_ROM_CTRL0_ROM_SIZE_BYTES`.
 */
#define TOP_DARIC2_ROM_CTRL0_ROM_SIZE_BYTES 0x8000u

/**
 * Peripheral base address for regs device on rom_ctrl1 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_ROM_CTRL1_REGS_BASE_ADDR 0x211E1000u

/**
 * Peripheral size for regs device on rom_ctrl1 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_ROM_CTRL1_REGS_BASE_ADDR and
 * `TOP_DARIC2_ROM_CTRL1_REGS_BASE_ADDR + TOP_DARIC2_ROM_CTRL1_REGS_SIZE_BYTES`.
 */
#define TOP_DARIC2_ROM_CTRL1_REGS_SIZE_BYTES 0x80u

/**
 * Peripheral base address for rom device on rom_ctrl1 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_ROM_CTRL1_ROM_BASE_ADDR 0x20000u

/**
 * Peripheral size for rom device on rom_ctrl1 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_ROM_CTRL1_ROM_BASE_ADDR and
 * `TOP_DARIC2_ROM_CTRL1_ROM_BASE_ADDR + TOP_DARIC2_ROM_CTRL1_ROM_SIZE_BYTES`.
 */
#define TOP_DARIC2_ROM_CTRL1_ROM_SIZE_BYTES 0x10000u

/**
 * Peripheral base address for dma in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_DMA_BASE_ADDR 0x22010000u

/**
 * Peripheral size for dma in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_DMA_BASE_ADDR and
 * `TOP_DARIC2_DMA_BASE_ADDR + TOP_DARIC2_DMA_SIZE_BYTES`.
 */
#define TOP_DARIC2_DMA_SIZE_BYTES 0x200u

/**
 * Peripheral base address for core device on mbx0 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_MBX0_CORE_BASE_ADDR 0x22000000u

/**
 * Peripheral size for core device on mbx0 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_MBX0_CORE_BASE_ADDR and
 * `TOP_DARIC2_MBX0_CORE_BASE_ADDR + TOP_DARIC2_MBX0_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_MBX0_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx1 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_MBX1_CORE_BASE_ADDR 0x22000100u

/**
 * Peripheral size for core device on mbx1 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_MBX1_CORE_BASE_ADDR and
 * `TOP_DARIC2_MBX1_CORE_BASE_ADDR + TOP_DARIC2_MBX1_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_MBX1_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx2 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_MBX2_CORE_BASE_ADDR 0x22000200u

/**
 * Peripheral size for core device on mbx2 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_MBX2_CORE_BASE_ADDR and
 * `TOP_DARIC2_MBX2_CORE_BASE_ADDR + TOP_DARIC2_MBX2_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_MBX2_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx3 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_MBX3_CORE_BASE_ADDR 0x22000300u

/**
 * Peripheral size for core device on mbx3 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_MBX3_CORE_BASE_ADDR and
 * `TOP_DARIC2_MBX3_CORE_BASE_ADDR + TOP_DARIC2_MBX3_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_MBX3_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx4 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_MBX4_CORE_BASE_ADDR 0x22000400u

/**
 * Peripheral size for core device on mbx4 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_MBX4_CORE_BASE_ADDR and
 * `TOP_DARIC2_MBX4_CORE_BASE_ADDR + TOP_DARIC2_MBX4_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_MBX4_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx5 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_MBX5_CORE_BASE_ADDR 0x22000500u

/**
 * Peripheral size for core device on mbx5 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_MBX5_CORE_BASE_ADDR and
 * `TOP_DARIC2_MBX5_CORE_BASE_ADDR + TOP_DARIC2_MBX5_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_MBX5_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx6 in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_MBX6_CORE_BASE_ADDR 0x22000600u

/**
 * Peripheral size for core device on mbx6 in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_MBX6_CORE_BASE_ADDR and
 * `TOP_DARIC2_MBX6_CORE_BASE_ADDR + TOP_DARIC2_MBX6_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_MBX6_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx_jtag in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_MBX_JTAG_CORE_BASE_ADDR 0x22000800u

/**
 * Peripheral size for core device on mbx_jtag in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_MBX_JTAG_CORE_BASE_ADDR and
 * `TOP_DARIC2_MBX_JTAG_CORE_BASE_ADDR + TOP_DARIC2_MBX_JTAG_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_MBX_JTAG_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on soc_dbg_ctrl in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_SOC_DBG_CTRL_CORE_BASE_ADDR 0x30170000u

/**
 * Peripheral size for core device on soc_dbg_ctrl in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_SOC_DBG_CTRL_CORE_BASE_ADDR and
 * `TOP_DARIC2_SOC_DBG_CTRL_CORE_BASE_ADDR + TOP_DARIC2_SOC_DBG_CTRL_CORE_SIZE_BYTES`.
 */
#define TOP_DARIC2_SOC_DBG_CTRL_CORE_SIZE_BYTES 0x20u

/**
 * Peripheral base address for cfg device on rv_core_ibex in top daric2.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARIC2_RV_CORE_IBEX_CFG_BASE_ADDR 0x211F0000u

/**
 * Peripheral size for cfg device on rv_core_ibex in top daric2.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARIC2_RV_CORE_IBEX_CFG_BASE_ADDR and
 * `TOP_DARIC2_RV_CORE_IBEX_CFG_BASE_ADDR + TOP_DARIC2_RV_CORE_IBEX_CFG_SIZE_BYTES`.
 */
#define TOP_DARIC2_RV_CORE_IBEX_CFG_SIZE_BYTES 0x800u


/**
 * Memory base address for ctn in top daric2.
 */
#define TOP_DARIC2_CTN_BASE_ADDR 0x40000000u

/**
 * Memory size for ctn in top daric2.
 */
#define TOP_DARIC2_CTN_SIZE_BYTES 0x40000000u

/**
 * Memory base address for ram_ret_aon in top daric2.
 */
#define TOP_DARIC2_RAM_RET_AON_BASE_ADDR 0x30600000u

/**
 * Memory size for ram_ret_aon in top daric2.
 */
#define TOP_DARIC2_RAM_RET_AON_SIZE_BYTES 0x1000u

/**
 * Memory base address for ram_main in top daric2.
 */
#define TOP_DARIC2_RAM_MAIN_BASE_ADDR 0x10000000u

/**
 * Memory size for ram_main in top daric2.
 */
#define TOP_DARIC2_RAM_MAIN_SIZE_BYTES 0x10000u

/**
 * Memory base address for ram_mbox in top daric2.
 */
#define TOP_DARIC2_RAM_MBOX_BASE_ADDR 0x11000000u

/**
 * Memory size for ram_mbox in top daric2.
 */
#define TOP_DARIC2_RAM_MBOX_SIZE_BYTES 0x1000u

/**
 * Memory base address for rom0 in top daric2.
 */
#define TOP_DARIC2_ROM0_BASE_ADDR 0x8000u

/**
 * Memory size for rom0 in top daric2.
 */
#define TOP_DARIC2_ROM0_SIZE_BYTES 0x8000u

/**
 * Memory base address for rom1 in top daric2.
 */
#define TOP_DARIC2_ROM1_BASE_ADDR 0x20000u

/**
 * Memory size for rom1 in top daric2.
 */
#define TOP_DARIC2_ROM1_SIZE_BYTES 0x10000u


/**
 * PLIC Interrupt Source Peripheral.
 *
 * Enumeration used to determine which peripheral asserted the corresponding
 * interrupt.
 */
typedef enum top_daric2_plic_peripheral {
  kTopDaric2PlicPeripheralUnknown = 0, /**< Unknown Peripheral */
  kTopDaric2PlicPeripheralUart0 = 1, /**< uart0 */
  kTopDaric2PlicPeripheralGpio = 2, /**< gpio */
  kTopDaric2PlicPeripheralRvTimer = 3, /**< rv_timer */
  kTopDaric2PlicPeripheralOtpCtrl = 4, /**< otp_ctrl */
  kTopDaric2PlicPeripheralAlertHandler = 5, /**< alert_handler */
  kTopDaric2PlicPeripheralPwrmgrAon = 6, /**< pwrmgr_aon */
  kTopDaric2PlicPeripheralAonTimerAon = 7, /**< aon_timer_aon */
  kTopDaric2PlicPeripheralSocProxy = 8, /**< soc_proxy */
  kTopDaric2PlicPeripheralHmac = 9, /**< hmac */
  kTopDaric2PlicPeripheralKmac = 10, /**< kmac */
  kTopDaric2PlicPeripheralOtbn = 11, /**< otbn */
  kTopDaric2PlicPeripheralKeymgrDpe = 12, /**< keymgr_dpe */
  kTopDaric2PlicPeripheralCsrng = 13, /**< csrng */
  kTopDaric2PlicPeripheralEdn0 = 14, /**< edn0 */
  kTopDaric2PlicPeripheralEdn1 = 15, /**< edn1 */
  kTopDaric2PlicPeripheralDma = 16, /**< dma */
  kTopDaric2PlicPeripheralMbx0 = 17, /**< mbx0 */
  kTopDaric2PlicPeripheralMbx1 = 18, /**< mbx1 */
  kTopDaric2PlicPeripheralMbx2 = 19, /**< mbx2 */
  kTopDaric2PlicPeripheralMbx3 = 20, /**< mbx3 */
  kTopDaric2PlicPeripheralMbx4 = 21, /**< mbx4 */
  kTopDaric2PlicPeripheralMbx5 = 22, /**< mbx5 */
  kTopDaric2PlicPeripheralMbx6 = 23, /**< mbx6 */
  kTopDaric2PlicPeripheralMbxJtag = 24, /**< mbx_jtag */
  kTopDaric2PlicPeripheralRaclCtrl = 25, /**< racl_ctrl */
  kTopDaric2PlicPeripheralAcRangeCheck = 26, /**< ac_range_check */
  kTopDaric2PlicPeripheralLast = 26, /**< \internal Final PLIC peripheral */
} top_daric2_plic_peripheral_t;

/**
 * PLIC Interrupt Source.
 *
 * Enumeration of all PLIC interrupt sources. The interrupt sources belonging to
 * the same peripheral are guaranteed to be consecutive.
 */
typedef enum top_daric2_plic_irq_id {
  kTopDaric2PlicIrqIdNone = 0, /**< No Interrupt */
  kTopDaric2PlicIrqIdUart0TxWatermark = 1, /**< uart0_tx_watermark */
  kTopDaric2PlicIrqIdUart0RxWatermark = 2, /**< uart0_rx_watermark */
  kTopDaric2PlicIrqIdUart0TxDone = 3, /**< uart0_tx_done */
  kTopDaric2PlicIrqIdUart0RxOverflow = 4, /**< uart0_rx_overflow */
  kTopDaric2PlicIrqIdUart0RxFrameErr = 5, /**< uart0_rx_frame_err */
  kTopDaric2PlicIrqIdUart0RxBreakErr = 6, /**< uart0_rx_break_err */
  kTopDaric2PlicIrqIdUart0RxTimeout = 7, /**< uart0_rx_timeout */
  kTopDaric2PlicIrqIdUart0RxParityErr = 8, /**< uart0_rx_parity_err */
  kTopDaric2PlicIrqIdUart0TxEmpty = 9, /**< uart0_tx_empty */
  kTopDaric2PlicIrqIdGpioGpio0 = 10, /**< gpio_gpio 0 */
  kTopDaric2PlicIrqIdGpioGpio1 = 11, /**< gpio_gpio 1 */
  kTopDaric2PlicIrqIdGpioGpio2 = 12, /**< gpio_gpio 2 */
  kTopDaric2PlicIrqIdGpioGpio3 = 13, /**< gpio_gpio 3 */
  kTopDaric2PlicIrqIdGpioGpio4 = 14, /**< gpio_gpio 4 */
  kTopDaric2PlicIrqIdGpioGpio5 = 15, /**< gpio_gpio 5 */
  kTopDaric2PlicIrqIdGpioGpio6 = 16, /**< gpio_gpio 6 */
  kTopDaric2PlicIrqIdGpioGpio7 = 17, /**< gpio_gpio 7 */
  kTopDaric2PlicIrqIdGpioGpio8 = 18, /**< gpio_gpio 8 */
  kTopDaric2PlicIrqIdGpioGpio9 = 19, /**< gpio_gpio 9 */
  kTopDaric2PlicIrqIdGpioGpio10 = 20, /**< gpio_gpio 10 */
  kTopDaric2PlicIrqIdGpioGpio11 = 21, /**< gpio_gpio 11 */
  kTopDaric2PlicIrqIdGpioGpio12 = 22, /**< gpio_gpio 12 */
  kTopDaric2PlicIrqIdGpioGpio13 = 23, /**< gpio_gpio 13 */
  kTopDaric2PlicIrqIdGpioGpio14 = 24, /**< gpio_gpio 14 */
  kTopDaric2PlicIrqIdGpioGpio15 = 25, /**< gpio_gpio 15 */
  kTopDaric2PlicIrqIdGpioGpio16 = 26, /**< gpio_gpio 16 */
  kTopDaric2PlicIrqIdGpioGpio17 = 27, /**< gpio_gpio 17 */
  kTopDaric2PlicIrqIdGpioGpio18 = 28, /**< gpio_gpio 18 */
  kTopDaric2PlicIrqIdGpioGpio19 = 29, /**< gpio_gpio 19 */
  kTopDaric2PlicIrqIdGpioGpio20 = 30, /**< gpio_gpio 20 */
  kTopDaric2PlicIrqIdGpioGpio21 = 31, /**< gpio_gpio 21 */
  kTopDaric2PlicIrqIdGpioGpio22 = 32, /**< gpio_gpio 22 */
  kTopDaric2PlicIrqIdGpioGpio23 = 33, /**< gpio_gpio 23 */
  kTopDaric2PlicIrqIdGpioGpio24 = 34, /**< gpio_gpio 24 */
  kTopDaric2PlicIrqIdGpioGpio25 = 35, /**< gpio_gpio 25 */
  kTopDaric2PlicIrqIdGpioGpio26 = 36, /**< gpio_gpio 26 */
  kTopDaric2PlicIrqIdGpioGpio27 = 37, /**< gpio_gpio 27 */
  kTopDaric2PlicIrqIdGpioGpio28 = 38, /**< gpio_gpio 28 */
  kTopDaric2PlicIrqIdGpioGpio29 = 39, /**< gpio_gpio 29 */
  kTopDaric2PlicIrqIdGpioGpio30 = 40, /**< gpio_gpio 30 */
  kTopDaric2PlicIrqIdGpioGpio31 = 41, /**< gpio_gpio 31 */
  kTopDaric2PlicIrqIdRvTimerTimerExpiredHart0Timer0 = 42, /**< rv_timer_timer_expired_hart0_timer0 */
  kTopDaric2PlicIrqIdOtpCtrlOtpOperationDone = 43, /**< otp_ctrl_otp_operation_done */
  kTopDaric2PlicIrqIdOtpCtrlOtpError = 44, /**< otp_ctrl_otp_error */
  kTopDaric2PlicIrqIdAlertHandlerClassa = 45, /**< alert_handler_classa */
  kTopDaric2PlicIrqIdAlertHandlerClassb = 46, /**< alert_handler_classb */
  kTopDaric2PlicIrqIdAlertHandlerClassc = 47, /**< alert_handler_classc */
  kTopDaric2PlicIrqIdAlertHandlerClassd = 48, /**< alert_handler_classd */
  kTopDaric2PlicIrqIdPwrmgrAonWakeup = 49, /**< pwrmgr_aon_wakeup */
  kTopDaric2PlicIrqIdAonTimerAonWkupTimerExpired = 50, /**< aon_timer_aon_wkup_timer_expired */
  kTopDaric2PlicIrqIdAonTimerAonWdogTimerBark = 51, /**< aon_timer_aon_wdog_timer_bark */
  kTopDaric2PlicIrqIdSocProxyExternal0 = 52, /**< soc_proxy_external 0 */
  kTopDaric2PlicIrqIdSocProxyExternal1 = 53, /**< soc_proxy_external 1 */
  kTopDaric2PlicIrqIdSocProxyExternal2 = 54, /**< soc_proxy_external 2 */
  kTopDaric2PlicIrqIdSocProxyExternal3 = 55, /**< soc_proxy_external 3 */
  kTopDaric2PlicIrqIdSocProxyExternal4 = 56, /**< soc_proxy_external 4 */
  kTopDaric2PlicIrqIdSocProxyExternal5 = 57, /**< soc_proxy_external 5 */
  kTopDaric2PlicIrqIdSocProxyExternal6 = 58, /**< soc_proxy_external 6 */
  kTopDaric2PlicIrqIdSocProxyExternal7 = 59, /**< soc_proxy_external 7 */
  kTopDaric2PlicIrqIdSocProxyExternal8 = 60, /**< soc_proxy_external 8 */
  kTopDaric2PlicIrqIdSocProxyExternal9 = 61, /**< soc_proxy_external 9 */
  kTopDaric2PlicIrqIdSocProxyExternal10 = 62, /**< soc_proxy_external 10 */
  kTopDaric2PlicIrqIdSocProxyExternal11 = 63, /**< soc_proxy_external 11 */
  kTopDaric2PlicIrqIdSocProxyExternal12 = 64, /**< soc_proxy_external 12 */
  kTopDaric2PlicIrqIdSocProxyExternal13 = 65, /**< soc_proxy_external 13 */
  kTopDaric2PlicIrqIdSocProxyExternal14 = 66, /**< soc_proxy_external 14 */
  kTopDaric2PlicIrqIdSocProxyExternal15 = 67, /**< soc_proxy_external 15 */
  kTopDaric2PlicIrqIdSocProxyExternal16 = 68, /**< soc_proxy_external 16 */
  kTopDaric2PlicIrqIdSocProxyExternal17 = 69, /**< soc_proxy_external 17 */
  kTopDaric2PlicIrqIdSocProxyExternal18 = 70, /**< soc_proxy_external 18 */
  kTopDaric2PlicIrqIdSocProxyExternal19 = 71, /**< soc_proxy_external 19 */
  kTopDaric2PlicIrqIdSocProxyExternal20 = 72, /**< soc_proxy_external 20 */
  kTopDaric2PlicIrqIdSocProxyExternal21 = 73, /**< soc_proxy_external 21 */
  kTopDaric2PlicIrqIdSocProxyExternal22 = 74, /**< soc_proxy_external 22 */
  kTopDaric2PlicIrqIdSocProxyExternal23 = 75, /**< soc_proxy_external 23 */
  kTopDaric2PlicIrqIdSocProxyExternal24 = 76, /**< soc_proxy_external 24 */
  kTopDaric2PlicIrqIdSocProxyExternal25 = 77, /**< soc_proxy_external 25 */
  kTopDaric2PlicIrqIdSocProxyExternal26 = 78, /**< soc_proxy_external 26 */
  kTopDaric2PlicIrqIdSocProxyExternal27 = 79, /**< soc_proxy_external 27 */
  kTopDaric2PlicIrqIdSocProxyExternal28 = 80, /**< soc_proxy_external 28 */
  kTopDaric2PlicIrqIdSocProxyExternal29 = 81, /**< soc_proxy_external 29 */
  kTopDaric2PlicIrqIdSocProxyExternal30 = 82, /**< soc_proxy_external 30 */
  kTopDaric2PlicIrqIdSocProxyExternal31 = 83, /**< soc_proxy_external 31 */
  kTopDaric2PlicIrqIdHmacHmacDone = 84, /**< hmac_hmac_done */
  kTopDaric2PlicIrqIdHmacFifoEmpty = 85, /**< hmac_fifo_empty */
  kTopDaric2PlicIrqIdHmacHmacErr = 86, /**< hmac_hmac_err */
  kTopDaric2PlicIrqIdKmacKmacDone = 87, /**< kmac_kmac_done */
  kTopDaric2PlicIrqIdKmacFifoEmpty = 88, /**< kmac_fifo_empty */
  kTopDaric2PlicIrqIdKmacKmacErr = 89, /**< kmac_kmac_err */
  kTopDaric2PlicIrqIdOtbnDone = 90, /**< otbn_done */
  kTopDaric2PlicIrqIdKeymgrDpeOpDone = 91, /**< keymgr_dpe_op_done */
  kTopDaric2PlicIrqIdCsrngCsCmdReqDone = 92, /**< csrng_cs_cmd_req_done */
  kTopDaric2PlicIrqIdCsrngCsEntropyReq = 93, /**< csrng_cs_entropy_req */
  kTopDaric2PlicIrqIdCsrngCsHwInstExc = 94, /**< csrng_cs_hw_inst_exc */
  kTopDaric2PlicIrqIdCsrngCsFatalErr = 95, /**< csrng_cs_fatal_err */
  kTopDaric2PlicIrqIdEdn0EdnCmdReqDone = 96, /**< edn0_edn_cmd_req_done */
  kTopDaric2PlicIrqIdEdn0EdnFatalErr = 97, /**< edn0_edn_fatal_err */
  kTopDaric2PlicIrqIdEdn1EdnCmdReqDone = 98, /**< edn1_edn_cmd_req_done */
  kTopDaric2PlicIrqIdEdn1EdnFatalErr = 99, /**< edn1_edn_fatal_err */
  kTopDaric2PlicIrqIdDmaDmaDone = 100, /**< dma_dma_done */
  kTopDaric2PlicIrqIdDmaDmaChunkDone = 101, /**< dma_dma_chunk_done */
  kTopDaric2PlicIrqIdDmaDmaError = 102, /**< dma_dma_error */
  kTopDaric2PlicIrqIdMbx0MbxReady = 103, /**< mbx0_mbx_ready */
  kTopDaric2PlicIrqIdMbx0MbxAbort = 104, /**< mbx0_mbx_abort */
  kTopDaric2PlicIrqIdMbx0MbxError = 105, /**< mbx0_mbx_error */
  kTopDaric2PlicIrqIdMbx1MbxReady = 106, /**< mbx1_mbx_ready */
  kTopDaric2PlicIrqIdMbx1MbxAbort = 107, /**< mbx1_mbx_abort */
  kTopDaric2PlicIrqIdMbx1MbxError = 108, /**< mbx1_mbx_error */
  kTopDaric2PlicIrqIdMbx2MbxReady = 109, /**< mbx2_mbx_ready */
  kTopDaric2PlicIrqIdMbx2MbxAbort = 110, /**< mbx2_mbx_abort */
  kTopDaric2PlicIrqIdMbx2MbxError = 111, /**< mbx2_mbx_error */
  kTopDaric2PlicIrqIdMbx3MbxReady = 112, /**< mbx3_mbx_ready */
  kTopDaric2PlicIrqIdMbx3MbxAbort = 113, /**< mbx3_mbx_abort */
  kTopDaric2PlicIrqIdMbx3MbxError = 114, /**< mbx3_mbx_error */
  kTopDaric2PlicIrqIdMbx4MbxReady = 115, /**< mbx4_mbx_ready */
  kTopDaric2PlicIrqIdMbx4MbxAbort = 116, /**< mbx4_mbx_abort */
  kTopDaric2PlicIrqIdMbx4MbxError = 117, /**< mbx4_mbx_error */
  kTopDaric2PlicIrqIdMbx5MbxReady = 118, /**< mbx5_mbx_ready */
  kTopDaric2PlicIrqIdMbx5MbxAbort = 119, /**< mbx5_mbx_abort */
  kTopDaric2PlicIrqIdMbx5MbxError = 120, /**< mbx5_mbx_error */
  kTopDaric2PlicIrqIdMbx6MbxReady = 121, /**< mbx6_mbx_ready */
  kTopDaric2PlicIrqIdMbx6MbxAbort = 122, /**< mbx6_mbx_abort */
  kTopDaric2PlicIrqIdMbx6MbxError = 123, /**< mbx6_mbx_error */
  kTopDaric2PlicIrqIdMbxJtagMbxReady = 124, /**< mbx_jtag_mbx_ready */
  kTopDaric2PlicIrqIdMbxJtagMbxAbort = 125, /**< mbx_jtag_mbx_abort */
  kTopDaric2PlicIrqIdMbxJtagMbxError = 126, /**< mbx_jtag_mbx_error */
  kTopDaric2PlicIrqIdRaclCtrlRaclError = 127, /**< racl_ctrl_racl_error */
  kTopDaric2PlicIrqIdAcRangeCheckDenyCntReached = 128, /**< ac_range_check_deny_cnt_reached */
  kTopDaric2PlicIrqIdLast = 128, /**< \internal The Last Valid Interrupt ID. */
} top_daric2_plic_irq_id_t;

/**
 * PLIC Interrupt Source to Peripheral Map
 *
 * This array is a mapping from `top_daric2_plic_irq_id_t` to
 * `top_daric2_plic_peripheral_t`.
 */
extern const top_daric2_plic_peripheral_t
    top_daric2_plic_interrupt_for_peripheral[129];

/**
 * PLIC Interrupt Target.
 *
 * Enumeration used to determine which set of IE, CC, threshold registers to
 * access for a given interrupt target.
 */
typedef enum top_daric2_plic_target {
  kTopDaric2PlicTargetIbex0 = 0, /**< Ibex Core 0 */
  kTopDaric2PlicTargetLast = 0, /**< \internal Final PLIC target */
} top_daric2_plic_target_t;

/**
 * Alert Handler Source Peripheral.
 *
 * Enumeration used to determine which peripheral asserted the corresponding
 * alert.
 */
typedef enum top_daric2_alert_peripheral {
  kTopDaric2AlertPeripheralExternal = 0, /**< External Peripheral */
  kTopDaric2AlertPeripheralUart0 = 1, /**< uart0 */
  kTopDaric2AlertPeripheralGpio = 2, /**< gpio */
  kTopDaric2AlertPeripheralRvTimer = 3, /**< rv_timer */
  kTopDaric2AlertPeripheralOtpCtrl = 4, /**< otp_ctrl */
  kTopDaric2AlertPeripheralLcCtrl = 5, /**< lc_ctrl */
  kTopDaric2AlertPeripheralPwrmgrAon = 6, /**< pwrmgr_aon */
  kTopDaric2AlertPeripheralRstmgrAon = 7, /**< rstmgr_aon */
  kTopDaric2AlertPeripheralClkmgrAon = 8, /**< clkmgr_aon */
  kTopDaric2AlertPeripheralPinmuxAon = 9, /**< pinmux_aon */
  kTopDaric2AlertPeripheralAonTimerAon = 10, /**< aon_timer_aon */
  kTopDaric2AlertPeripheralSocProxy = 11, /**< soc_proxy */
  kTopDaric2AlertPeripheralSramCtrlRetAon = 12, /**< sram_ctrl_ret_aon */
  kTopDaric2AlertPeripheralRvDm = 13, /**< rv_dm */
  kTopDaric2AlertPeripheralRvPlic = 14, /**< rv_plic */
  kTopDaric2AlertPeripheralAes = 15, /**< aes */
  kTopDaric2AlertPeripheralHmac = 16, /**< hmac */
  kTopDaric2AlertPeripheralKmac = 17, /**< kmac */
  kTopDaric2AlertPeripheralOtbn = 18, /**< otbn */
  kTopDaric2AlertPeripheralKeymgrDpe = 19, /**< keymgr_dpe */
  kTopDaric2AlertPeripheralCsrng = 20, /**< csrng */
  kTopDaric2AlertPeripheralEdn0 = 21, /**< edn0 */
  kTopDaric2AlertPeripheralEdn1 = 22, /**< edn1 */
  kTopDaric2AlertPeripheralSramCtrlMain = 23, /**< sram_ctrl_main */
  kTopDaric2AlertPeripheralSramCtrlMbox = 24, /**< sram_ctrl_mbox */
  kTopDaric2AlertPeripheralRomCtrl0 = 25, /**< rom_ctrl0 */
  kTopDaric2AlertPeripheralRomCtrl1 = 26, /**< rom_ctrl1 */
  kTopDaric2AlertPeripheralDma = 27, /**< dma */
  kTopDaric2AlertPeripheralMbx0 = 28, /**< mbx0 */
  kTopDaric2AlertPeripheralMbx1 = 29, /**< mbx1 */
  kTopDaric2AlertPeripheralMbx2 = 30, /**< mbx2 */
  kTopDaric2AlertPeripheralMbx3 = 31, /**< mbx3 */
  kTopDaric2AlertPeripheralMbx4 = 32, /**< mbx4 */
  kTopDaric2AlertPeripheralMbx5 = 33, /**< mbx5 */
  kTopDaric2AlertPeripheralMbx6 = 34, /**< mbx6 */
  kTopDaric2AlertPeripheralMbxJtag = 35, /**< mbx_jtag */
  kTopDaric2AlertPeripheralSocDbgCtrl = 36, /**< soc_dbg_ctrl */
  kTopDaric2AlertPeripheralRaclCtrl = 37, /**< racl_ctrl */
  kTopDaric2AlertPeripheralAcRangeCheck = 38, /**< ac_range_check */
  kTopDaric2AlertPeripheralRvCoreIbex = 39, /**< rv_core_ibex */
  kTopDaric2AlertPeripheralLast = 39, /**< \internal Final Alert peripheral */
} top_daric2_alert_peripheral_t;

/**
 * Alert Handler Alert Source.
 *
 * Enumeration of all Alert Handler Alert Sources. The alert sources belonging to
 * the same peripheral are guaranteed to be consecutive.
 */
typedef enum top_daric2_alert_id {
  kTopDaric2AlertIdUart0FatalFault = 0, /**< uart0_fatal_fault */
  kTopDaric2AlertIdGpioFatalFault = 1, /**< gpio_fatal_fault */
  kTopDaric2AlertIdRvTimerFatalFault = 2, /**< rv_timer_fatal_fault */
  kTopDaric2AlertIdOtpCtrlFatalMacroError = 3, /**< otp_ctrl_fatal_macro_error */
  kTopDaric2AlertIdOtpCtrlFatalCheckError = 4, /**< otp_ctrl_fatal_check_error */
  kTopDaric2AlertIdOtpCtrlFatalBusIntegError = 5, /**< otp_ctrl_fatal_bus_integ_error */
  kTopDaric2AlertIdOtpCtrlFatalPrimOtpAlert = 6, /**< otp_ctrl_fatal_prim_otp_alert */
  kTopDaric2AlertIdOtpCtrlRecovPrimOtpAlert = 7, /**< otp_ctrl_recov_prim_otp_alert */
  kTopDaric2AlertIdLcCtrlFatalProgError = 8, /**< lc_ctrl_fatal_prog_error */
  kTopDaric2AlertIdLcCtrlFatalStateError = 9, /**< lc_ctrl_fatal_state_error */
  kTopDaric2AlertIdLcCtrlFatalBusIntegError = 10, /**< lc_ctrl_fatal_bus_integ_error */
  kTopDaric2AlertIdPwrmgrAonFatalFault = 11, /**< pwrmgr_aon_fatal_fault */
  kTopDaric2AlertIdRstmgrAonFatalFault = 12, /**< rstmgr_aon_fatal_fault */
  kTopDaric2AlertIdRstmgrAonFatalCnstyFault = 13, /**< rstmgr_aon_fatal_cnsty_fault */
  kTopDaric2AlertIdClkmgrAonRecovFault = 14, /**< clkmgr_aon_recov_fault */
  kTopDaric2AlertIdClkmgrAonFatalFault = 15, /**< clkmgr_aon_fatal_fault */
  kTopDaric2AlertIdPinmuxAonFatalFault = 16, /**< pinmux_aon_fatal_fault */
  kTopDaric2AlertIdAonTimerAonFatalFault = 17, /**< aon_timer_aon_fatal_fault */
  kTopDaric2AlertIdSocProxyFatalAlertIntg = 18, /**< soc_proxy_fatal_alert_intg */
  kTopDaric2AlertIdSocProxyFatalAlertExternal0 = 19, /**< soc_proxy_fatal_alert_external_0 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal1 = 20, /**< soc_proxy_fatal_alert_external_1 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal2 = 21, /**< soc_proxy_fatal_alert_external_2 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal3 = 22, /**< soc_proxy_fatal_alert_external_3 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal4 = 23, /**< soc_proxy_fatal_alert_external_4 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal5 = 24, /**< soc_proxy_fatal_alert_external_5 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal6 = 25, /**< soc_proxy_fatal_alert_external_6 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal7 = 26, /**< soc_proxy_fatal_alert_external_7 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal8 = 27, /**< soc_proxy_fatal_alert_external_8 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal9 = 28, /**< soc_proxy_fatal_alert_external_9 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal10 = 29, /**< soc_proxy_fatal_alert_external_10 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal11 = 30, /**< soc_proxy_fatal_alert_external_11 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal12 = 31, /**< soc_proxy_fatal_alert_external_12 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal13 = 32, /**< soc_proxy_fatal_alert_external_13 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal14 = 33, /**< soc_proxy_fatal_alert_external_14 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal15 = 34, /**< soc_proxy_fatal_alert_external_15 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal16 = 35, /**< soc_proxy_fatal_alert_external_16 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal17 = 36, /**< soc_proxy_fatal_alert_external_17 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal18 = 37, /**< soc_proxy_fatal_alert_external_18 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal19 = 38, /**< soc_proxy_fatal_alert_external_19 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal20 = 39, /**< soc_proxy_fatal_alert_external_20 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal21 = 40, /**< soc_proxy_fatal_alert_external_21 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal22 = 41, /**< soc_proxy_fatal_alert_external_22 */
  kTopDaric2AlertIdSocProxyFatalAlertExternal23 = 42, /**< soc_proxy_fatal_alert_external_23 */
  kTopDaric2AlertIdSocProxyRecovAlertExternal0 = 43, /**< soc_proxy_recov_alert_external_0 */
  kTopDaric2AlertIdSocProxyRecovAlertExternal1 = 44, /**< soc_proxy_recov_alert_external_1 */
  kTopDaric2AlertIdSocProxyRecovAlertExternal2 = 45, /**< soc_proxy_recov_alert_external_2 */
  kTopDaric2AlertIdSocProxyRecovAlertExternal3 = 46, /**< soc_proxy_recov_alert_external_3 */
  kTopDaric2AlertIdSramCtrlRetAonFatalError = 47, /**< sram_ctrl_ret_aon_fatal_error */
  kTopDaric2AlertIdRvDmFatalFault = 48, /**< rv_dm_fatal_fault */
  kTopDaric2AlertIdRvPlicFatalFault = 49, /**< rv_plic_fatal_fault */
  kTopDaric2AlertIdAesRecovCtrlUpdateErr = 50, /**< aes_recov_ctrl_update_err */
  kTopDaric2AlertIdAesFatalFault = 51, /**< aes_fatal_fault */
  kTopDaric2AlertIdHmacFatalFault = 52, /**< hmac_fatal_fault */
  kTopDaric2AlertIdKmacRecovOperationErr = 53, /**< kmac_recov_operation_err */
  kTopDaric2AlertIdKmacFatalFaultErr = 54, /**< kmac_fatal_fault_err */
  kTopDaric2AlertIdOtbnFatal = 55, /**< otbn_fatal */
  kTopDaric2AlertIdOtbnRecov = 56, /**< otbn_recov */
  kTopDaric2AlertIdKeymgrDpeRecovOperationErr = 57, /**< keymgr_dpe_recov_operation_err */
  kTopDaric2AlertIdKeymgrDpeFatalFaultErr = 58, /**< keymgr_dpe_fatal_fault_err */
  kTopDaric2AlertIdCsrngRecovAlert = 59, /**< csrng_recov_alert */
  kTopDaric2AlertIdCsrngFatalAlert = 60, /**< csrng_fatal_alert */
  kTopDaric2AlertIdEdn0RecovAlert = 61, /**< edn0_recov_alert */
  kTopDaric2AlertIdEdn0FatalAlert = 62, /**< edn0_fatal_alert */
  kTopDaric2AlertIdEdn1RecovAlert = 63, /**< edn1_recov_alert */
  kTopDaric2AlertIdEdn1FatalAlert = 64, /**< edn1_fatal_alert */
  kTopDaric2AlertIdSramCtrlMainFatalError = 65, /**< sram_ctrl_main_fatal_error */
  kTopDaric2AlertIdSramCtrlMboxFatalError = 66, /**< sram_ctrl_mbox_fatal_error */
  kTopDaric2AlertIdRomCtrl0Fatal = 67, /**< rom_ctrl0_fatal */
  kTopDaric2AlertIdRomCtrl1Fatal = 68, /**< rom_ctrl1_fatal */
  kTopDaric2AlertIdDmaFatalFault = 69, /**< dma_fatal_fault */
  kTopDaric2AlertIdMbx0FatalFault = 70, /**< mbx0_fatal_fault */
  kTopDaric2AlertIdMbx0RecovFault = 71, /**< mbx0_recov_fault */
  kTopDaric2AlertIdMbx1FatalFault = 72, /**< mbx1_fatal_fault */
  kTopDaric2AlertIdMbx1RecovFault = 73, /**< mbx1_recov_fault */
  kTopDaric2AlertIdMbx2FatalFault = 74, /**< mbx2_fatal_fault */
  kTopDaric2AlertIdMbx2RecovFault = 75, /**< mbx2_recov_fault */
  kTopDaric2AlertIdMbx3FatalFault = 76, /**< mbx3_fatal_fault */
  kTopDaric2AlertIdMbx3RecovFault = 77, /**< mbx3_recov_fault */
  kTopDaric2AlertIdMbx4FatalFault = 78, /**< mbx4_fatal_fault */
  kTopDaric2AlertIdMbx4RecovFault = 79, /**< mbx4_recov_fault */
  kTopDaric2AlertIdMbx5FatalFault = 80, /**< mbx5_fatal_fault */
  kTopDaric2AlertIdMbx5RecovFault = 81, /**< mbx5_recov_fault */
  kTopDaric2AlertIdMbx6FatalFault = 82, /**< mbx6_fatal_fault */
  kTopDaric2AlertIdMbx6RecovFault = 83, /**< mbx6_recov_fault */
  kTopDaric2AlertIdMbxJtagFatalFault = 84, /**< mbx_jtag_fatal_fault */
  kTopDaric2AlertIdMbxJtagRecovFault = 85, /**< mbx_jtag_recov_fault */
  kTopDaric2AlertIdSocDbgCtrlFatalFault = 86, /**< soc_dbg_ctrl_fatal_fault */
  kTopDaric2AlertIdSocDbgCtrlRecovCtrlUpdateErr = 87, /**< soc_dbg_ctrl_recov_ctrl_update_err */
  kTopDaric2AlertIdRaclCtrlFatalFault = 88, /**< racl_ctrl_fatal_fault */
  kTopDaric2AlertIdRaclCtrlRecovCtrlUpdateErr = 89, /**< racl_ctrl_recov_ctrl_update_err */
  kTopDaric2AlertIdAcRangeCheckRecovCtrlUpdateErr = 90, /**< ac_range_check_recov_ctrl_update_err */
  kTopDaric2AlertIdAcRangeCheckFatalFault = 91, /**< ac_range_check_fatal_fault */
  kTopDaric2AlertIdRvCoreIbexFatalSwErr = 92, /**< rv_core_ibex_fatal_sw_err */
  kTopDaric2AlertIdRvCoreIbexRecovSwErr = 93, /**< rv_core_ibex_recov_sw_err */
  kTopDaric2AlertIdRvCoreIbexFatalHwErr = 94, /**< rv_core_ibex_fatal_hw_err */
  kTopDaric2AlertIdRvCoreIbexRecovHwErr = 95, /**< rv_core_ibex_recov_hw_err */
  kTopDaric2AlertIdLast = 95, /**< \internal The Last Valid Alert ID. */
} top_daric2_alert_id_t;

/**
 * Alert Handler Alert Source to Peripheral Map
 *
 * This array is a mapping from `top_daric2_alert_id_t` to
 * `top_daric2_alert_peripheral_t`.
 */
extern const top_daric2_alert_peripheral_t
    top_daric2_alert_for_peripheral[96];

#define PINMUX_MIO_PERIPH_INSEL_IDX_OFFSET 2

// PERIPH_INSEL ranges from 0 to NUM_MIO_PADS + 2 -1}
//  0 and 1 are tied to value 0 and 1
#define NUM_MIO_PADS 12
#define NUM_DIO_PADS 58

#define PINMUX_PERIPH_OUTSEL_IDX_OFFSET 3

/**
 * Pinmux Peripheral Input.
 */
typedef enum top_daric2_pinmux_peripheral_in {
  kTopDaric2PinmuxPeripheralInSocProxySocGpi12 = 0, /**< Peripheral Input 0 */
  kTopDaric2PinmuxPeripheralInSocProxySocGpi13 = 1, /**< Peripheral Input 1 */
  kTopDaric2PinmuxPeripheralInSocProxySocGpi14 = 2, /**< Peripheral Input 2 */
  kTopDaric2PinmuxPeripheralInSocProxySocGpi15 = 3, /**< Peripheral Input 3 */
  kTopDaric2PinmuxPeripheralInLast = 3, /**< \internal Last valid peripheral input */
} top_daric2_pinmux_peripheral_in_t;

/**
 * Pinmux MIO Input Selector.
 */
typedef enum top_daric2_pinmux_insel {
  kTopDaric2PinmuxInselConstantZero = 0, /**< Tie constantly to zero */
  kTopDaric2PinmuxInselConstantOne = 1, /**< Tie constantly to one */
  kTopDaric2PinmuxInselMio0 = 2, /**< MIO Pad 0 */
  kTopDaric2PinmuxInselMio1 = 3, /**< MIO Pad 1 */
  kTopDaric2PinmuxInselMio2 = 4, /**< MIO Pad 2 */
  kTopDaric2PinmuxInselMio3 = 5, /**< MIO Pad 3 */
  kTopDaric2PinmuxInselMio4 = 6, /**< MIO Pad 4 */
  kTopDaric2PinmuxInselMio5 = 7, /**< MIO Pad 5 */
  kTopDaric2PinmuxInselMio6 = 8, /**< MIO Pad 6 */
  kTopDaric2PinmuxInselMio7 = 9, /**< MIO Pad 7 */
  kTopDaric2PinmuxInselMio8 = 10, /**< MIO Pad 8 */
  kTopDaric2PinmuxInselMio9 = 11, /**< MIO Pad 9 */
  kTopDaric2PinmuxInselMio10 = 12, /**< MIO Pad 10 */
  kTopDaric2PinmuxInselMio11 = 13, /**< MIO Pad 11 */
  kTopDaric2PinmuxInselLast = 13, /**< \internal Last valid insel value */
} top_daric2_pinmux_insel_t;

/**
 * Pinmux MIO Output.
 */
typedef enum top_daric2_pinmux_mio_out {
  kTopDaric2PinmuxMioOutMio0 = 0, /**< MIO Pad 0 */
  kTopDaric2PinmuxMioOutMio1 = 1, /**< MIO Pad 1 */
  kTopDaric2PinmuxMioOutMio2 = 2, /**< MIO Pad 2 */
  kTopDaric2PinmuxMioOutMio3 = 3, /**< MIO Pad 3 */
  kTopDaric2PinmuxMioOutMio4 = 4, /**< MIO Pad 4 */
  kTopDaric2PinmuxMioOutMio5 = 5, /**< MIO Pad 5 */
  kTopDaric2PinmuxMioOutMio6 = 6, /**< MIO Pad 6 */
  kTopDaric2PinmuxMioOutMio7 = 7, /**< MIO Pad 7 */
  kTopDaric2PinmuxMioOutMio8 = 8, /**< MIO Pad 8 */
  kTopDaric2PinmuxMioOutMio9 = 9, /**< MIO Pad 9 */
  kTopDaric2PinmuxMioOutMio10 = 10, /**< MIO Pad 10 */
  kTopDaric2PinmuxMioOutMio11 = 11, /**< MIO Pad 11 */
  kTopDaric2PinmuxMioOutLast = 11, /**< \internal Last valid mio output */
} top_daric2_pinmux_mio_out_t;

/**
 * Pinmux Peripheral Output Selector.
 */
typedef enum top_daric2_pinmux_outsel {
  kTopDaric2PinmuxOutselConstantZero = 0, /**< Tie constantly to zero */
  kTopDaric2PinmuxOutselConstantOne = 1, /**< Tie constantly to one */
  kTopDaric2PinmuxOutselConstantHighZ = 2, /**< Tie constantly to high-Z */
  kTopDaric2PinmuxOutselSocProxySocGpo12 = 3, /**< Peripheral Output 0 */
  kTopDaric2PinmuxOutselSocProxySocGpo13 = 4, /**< Peripheral Output 1 */
  kTopDaric2PinmuxOutselSocProxySocGpo14 = 5, /**< Peripheral Output 2 */
  kTopDaric2PinmuxOutselSocProxySocGpo15 = 6, /**< Peripheral Output 3 */
  kTopDaric2PinmuxOutselOtpMacroTest0 = 7, /**< Peripheral Output 4 */
  kTopDaric2PinmuxOutselLast = 7, /**< \internal Last valid outsel value */
} top_daric2_pinmux_outsel_t;

/**
 * Dedicated Pad Selects
 */
typedef enum top_daric2_direct_pads {
  kTopDaric2DirectPadsGpioGpio0 = 0, /**<  */
  kTopDaric2DirectPadsGpioGpio1 = 1, /**<  */
  kTopDaric2DirectPadsGpioGpio2 = 2, /**<  */
  kTopDaric2DirectPadsGpioGpio3 = 3, /**<  */
  kTopDaric2DirectPadsGpioGpio4 = 4, /**<  */
  kTopDaric2DirectPadsGpioGpio5 = 5, /**<  */
  kTopDaric2DirectPadsGpioGpio6 = 6, /**<  */
  kTopDaric2DirectPadsGpioGpio7 = 7, /**<  */
  kTopDaric2DirectPadsGpioGpio8 = 8, /**<  */
  kTopDaric2DirectPadsGpioGpio9 = 9, /**<  */
  kTopDaric2DirectPadsGpioGpio10 = 10, /**<  */
  kTopDaric2DirectPadsGpioGpio11 = 11, /**<  */
  kTopDaric2DirectPadsGpioGpio12 = 12, /**<  */
  kTopDaric2DirectPadsGpioGpio13 = 13, /**<  */
  kTopDaric2DirectPadsGpioGpio14 = 14, /**<  */
  kTopDaric2DirectPadsGpioGpio15 = 15, /**<  */
  kTopDaric2DirectPadsGpioGpio16 = 16, /**<  */
  kTopDaric2DirectPadsGpioGpio17 = 17, /**<  */
  kTopDaric2DirectPadsGpioGpio18 = 18, /**<  */
  kTopDaric2DirectPadsGpioGpio19 = 19, /**<  */
  kTopDaric2DirectPadsGpioGpio20 = 20, /**<  */
  kTopDaric2DirectPadsGpioGpio21 = 21, /**<  */
  kTopDaric2DirectPadsGpioGpio22 = 22, /**<  */
  kTopDaric2DirectPadsGpioGpio23 = 23, /**<  */
  kTopDaric2DirectPadsGpioGpio24 = 24, /**<  */
  kTopDaric2DirectPadsGpioGpio25 = 25, /**<  */
  kTopDaric2DirectPadsGpioGpio26 = 26, /**<  */
  kTopDaric2DirectPadsGpioGpio27 = 27, /**<  */
  kTopDaric2DirectPadsGpioGpio28 = 28, /**<  */
  kTopDaric2DirectPadsGpioGpio29 = 29, /**<  */
  kTopDaric2DirectPadsGpioGpio30 = 30, /**<  */
  kTopDaric2DirectPadsGpioGpio31 = 31, /**<  */
  kTopDaric2DirectPadsUart0Rx = 32, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi0 = 33, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi1 = 34, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi2 = 35, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi3 = 36, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi4 = 37, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi5 = 38, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi6 = 39, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi7 = 40, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi8 = 41, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi9 = 42, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi10 = 43, /**<  */
  kTopDaric2DirectPadsSocProxySocGpi11 = 44, /**<  */
  kTopDaric2DirectPadsUart0Tx = 45, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo0 = 46, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo1 = 47, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo2 = 48, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo3 = 49, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo4 = 50, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo5 = 51, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo6 = 52, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo7 = 53, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo8 = 54, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo9 = 55, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo10 = 56, /**<  */
  kTopDaric2DirectPadsSocProxySocGpo11 = 57, /**<  */
  kTopDaric2DirectPadsLast = 57, /**< \internal Last valid direct pad */
} top_daric2_direct_pads_t;

/**
 * Muxed Pad Selects
 */
typedef enum top_daric2_muxed_pads {
  kTopDaric2MuxedPadsMio0 = 0, /**<  */
  kTopDaric2MuxedPadsMio1 = 1, /**<  */
  kTopDaric2MuxedPadsMio2 = 2, /**<  */
  kTopDaric2MuxedPadsMio3 = 3, /**<  */
  kTopDaric2MuxedPadsMio4 = 4, /**<  */
  kTopDaric2MuxedPadsMio5 = 5, /**<  */
  kTopDaric2MuxedPadsMio6 = 6, /**<  */
  kTopDaric2MuxedPadsMio7 = 7, /**<  */
  kTopDaric2MuxedPadsMio8 = 8, /**<  */
  kTopDaric2MuxedPadsMio9 = 9, /**<  */
  kTopDaric2MuxedPadsMio10 = 10, /**<  */
  kTopDaric2MuxedPadsMio11 = 11, /**<  */
  kTopDaric2MuxedPadsLast = 11, /**< \internal Last valid muxed pad */
} top_daric2_muxed_pads_t;

/**
 * Power Manager Wakeup Signals
 */
typedef enum top_daric2_power_manager_wake_ups {
  kTopDaric2PowerManagerWakeUpsPinmuxAonPinWkupReq = 0, /**<  */
  kTopDaric2PowerManagerWakeUpsAonTimerAonWkupReq = 1, /**<  */
  kTopDaric2PowerManagerWakeUpsSocProxyWkupInternalReq = 2, /**<  */
  kTopDaric2PowerManagerWakeUpsSocProxyWkupExternalReq = 3, /**<  */
  kTopDaric2PowerManagerWakeUpsLast = 3, /**< \internal Last valid pwrmgr wakeup signal */
} top_daric2_power_manager_wake_ups_t;

/**
 * Reset Manager Software Controlled Resets
 */
typedef enum top_daric2_reset_manager_sw_resets {
  kTopDaric2ResetManagerSwResetsSysSrc = 0, /**<  */
  kTopDaric2ResetManagerSwResetsLast = 0, /**< \internal Last valid rstmgr software reset request */
} top_daric2_reset_manager_sw_resets_t;

/**
 * Power Manager Reset Request Signals
 */
typedef enum top_daric2_power_manager_reset_requests {
  kTopDaric2PowerManagerResetRequestsAonTimerAonAonTimerRstReq = 0, /**<  */
  kTopDaric2PowerManagerResetRequestsSocProxyRstReqExternal = 1, /**<  */
  kTopDaric2PowerManagerResetRequestsLast = 1, /**< \internal Last valid pwrmgr reset_request signal */
} top_daric2_power_manager_reset_requests_t;

/**
 * Clock Manager Software-Controlled ("Gated") Clocks.
 *
 * The Software has full control over these clocks.
 */
typedef enum top_daric2_gateable_clocks {
  kTopDaric2GateableClocksIoDiv4Peri = 0, /**< Clock clk_io_div4_peri in group peri */
  kTopDaric2GateableClocksLast = 0, /**< \internal Last Valid Gateable Clock */
} top_daric2_gateable_clocks_t;

/**
 * Clock Manager Software-Hinted Clocks.
 *
 * The Software has partial control over these clocks. It can ask them to stop,
 * but the clock manager is in control of whether the clock actually is stopped.
 */
typedef enum top_daric2_hintable_clocks {
  kTopDaric2HintableClocksMainAes = 0, /**< Clock clk_main_aes in group trans */
  kTopDaric2HintableClocksMainHmac = 1, /**< Clock clk_main_hmac in group trans */
  kTopDaric2HintableClocksMainKmac = 2, /**< Clock clk_main_kmac in group trans */
  kTopDaric2HintableClocksMainOtbn = 3, /**< Clock clk_main_otbn in group trans */
  kTopDaric2HintableClocksLast = 3, /**< \internal Last Valid Hintable Clock */
} top_daric2_hintable_clocks_t;

/**
 * MMIO Region
 *
 * MMIO region excludes any memory that is separate from the module
 * configuration space, i.e. ROM, main SRAM, and mbx SRAM are excluded but
 * retention SRAM or spi_device are included.
 */
#define TOP_DARIC2_MMIO_BASE_ADDR 0x21100000u
#define TOP_DARIC2_MMIO_SIZE_BYTES 0xF501000u

// Header Extern Guard
#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // OPENTITAN_HW_TOP_DARIC2_SW_AUTOGEN_TOP_DARIC2_H_
