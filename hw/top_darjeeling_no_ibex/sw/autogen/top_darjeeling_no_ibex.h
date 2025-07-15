// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// ------------------- W A R N I N G: A U T O - G E N E R A T E D   C O D E !! -------------------//
// PLEASE DO NOT HAND-EDIT THIS FILE. IT HAS BEEN AUTO-GENERATED WITH THE FOLLOWING COMMAND:
// util/topgen.py -t hw/top_darjeeling_no_ibex/data/top_darjeeling_no_ibex.hjson
// -o hw/top_darjeeling_no_ibex

#ifndef OPENTITAN_HW_TOP_DARJEELING_NO_IBEX_SW_AUTOGEN_TOP_DARJEELING_NO_IBEX_H_
#define OPENTITAN_HW_TOP_DARJEELING_NO_IBEX_SW_AUTOGEN_TOP_DARJEELING_NO_IBEX_H_

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
 * Peripheral base address for uart0 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_UART0_BASE_ADDR 0x30010000u

/**
 * Peripheral size for uart0 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_UART0_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_UART0_BASE_ADDR + TOP_DARJEELING_NO_IBEX_UART0_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_UART0_SIZE_BYTES 0x40u

/**
 * Peripheral base address for gpio in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_GPIO_BASE_ADDR 0x30000000u

/**
 * Peripheral size for gpio in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_GPIO_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_GPIO_BASE_ADDR + TOP_DARJEELING_NO_IBEX_GPIO_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_GPIO_SIZE_BYTES 0x100u

/**
 * Peripheral base address for spi_device in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SPI_DEVICE_BASE_ADDR 0x30310000u

/**
 * Peripheral size for spi_device in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SPI_DEVICE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SPI_DEVICE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SPI_DEVICE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SPI_DEVICE_SIZE_BYTES 0x2000u

/**
 * Peripheral base address for i2c0 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_I2C0_BASE_ADDR 0x30080000u

/**
 * Peripheral size for i2c0 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_I2C0_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_I2C0_BASE_ADDR + TOP_DARJEELING_NO_IBEX_I2C0_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_I2C0_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on otp_ctrl in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_OTP_CTRL_CORE_BASE_ADDR 0x30130000u

/**
 * Peripheral size for core device on otp_ctrl in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_OTP_CTRL_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_OTP_CTRL_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_OTP_CTRL_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_OTP_CTRL_CORE_SIZE_BYTES 0x8000u

/**
 * Peripheral base address for prim device on otp_macro in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_OTP_MACRO_PRIM_BASE_ADDR 0x30140000u

/**
 * Peripheral size for prim device on otp_macro in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_OTP_MACRO_PRIM_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_OTP_MACRO_PRIM_BASE_ADDR + TOP_DARJEELING_NO_IBEX_OTP_MACRO_PRIM_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_OTP_MACRO_PRIM_SIZE_BYTES 0x20u

/**
 * Peripheral base address for regs device on lc_ctrl in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_LC_CTRL_REGS_BASE_ADDR 0x30150000u

/**
 * Peripheral size for regs device on lc_ctrl in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_LC_CTRL_REGS_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_LC_CTRL_REGS_BASE_ADDR + TOP_DARJEELING_NO_IBEX_LC_CTRL_REGS_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_LC_CTRL_REGS_SIZE_BYTES 0x100u

/**
 * Peripheral base address for alert_handler in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_ALERT_HANDLER_BASE_ADDR 0x30160000u

/**
 * Peripheral size for alert_handler in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_ALERT_HANDLER_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_ALERT_HANDLER_BASE_ADDR + TOP_DARJEELING_NO_IBEX_ALERT_HANDLER_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_ALERT_HANDLER_SIZE_BYTES 0x800u

/**
 * Peripheral base address for spi_host0 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SPI_HOST0_BASE_ADDR 0x30300000u

/**
 * Peripheral size for spi_host0 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SPI_HOST0_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SPI_HOST0_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SPI_HOST0_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SPI_HOST0_SIZE_BYTES 0x40u

/**
 * Peripheral base address for pwrmgr_aon in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_PWRMGR_AON_BASE_ADDR 0x30400000u

/**
 * Peripheral size for pwrmgr_aon in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_PWRMGR_AON_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_PWRMGR_AON_BASE_ADDR + TOP_DARJEELING_NO_IBEX_PWRMGR_AON_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_PWRMGR_AON_SIZE_BYTES 0x80u

/**
 * Peripheral base address for rstmgr_aon in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_RSTMGR_AON_BASE_ADDR 0x30410000u

/**
 * Peripheral size for rstmgr_aon in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_RSTMGR_AON_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_RSTMGR_AON_BASE_ADDR + TOP_DARJEELING_NO_IBEX_RSTMGR_AON_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_RSTMGR_AON_SIZE_BYTES 0x80u

/**
 * Peripheral base address for clkmgr_aon in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_CLKMGR_AON_BASE_ADDR 0x30420000u

/**
 * Peripheral size for clkmgr_aon in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_CLKMGR_AON_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_CLKMGR_AON_BASE_ADDR + TOP_DARJEELING_NO_IBEX_CLKMGR_AON_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_CLKMGR_AON_SIZE_BYTES 0x40u

/**
 * Peripheral base address for pinmux_aon in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_PINMUX_AON_BASE_ADDR 0x30460000u

/**
 * Peripheral size for pinmux_aon in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_PINMUX_AON_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_PINMUX_AON_BASE_ADDR + TOP_DARJEELING_NO_IBEX_PINMUX_AON_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_PINMUX_AON_SIZE_BYTES 0x800u

/**
 * Peripheral base address for aon_timer_aon in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_AON_TIMER_AON_BASE_ADDR 0x30470000u

/**
 * Peripheral size for aon_timer_aon in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_AON_TIMER_AON_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_AON_TIMER_AON_BASE_ADDR + TOP_DARJEELING_NO_IBEX_AON_TIMER_AON_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_AON_TIMER_AON_SIZE_BYTES 0x40u

/**
 * Peripheral base address for ast in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_AST_BASE_ADDR 0x30480000u

/**
 * Peripheral size for ast in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_AST_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_AST_BASE_ADDR + TOP_DARJEELING_NO_IBEX_AST_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_AST_SIZE_BYTES 0x400u

/**
 * Peripheral base address for core device on soc_proxy in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SOC_PROXY_CORE_BASE_ADDR 0x22030000u

/**
 * Peripheral size for core device on soc_proxy in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SOC_PROXY_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SOC_PROXY_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SOC_PROXY_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SOC_PROXY_CORE_SIZE_BYTES 0x10u

/**
 * Peripheral base address for ctn device on soc_proxy in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SOC_PROXY_CTN_BASE_ADDR 0x40000000u

/**
 * Peripheral size for ctn device on soc_proxy in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SOC_PROXY_CTN_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SOC_PROXY_CTN_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SOC_PROXY_CTN_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SOC_PROXY_CTN_SIZE_BYTES 0x40000000u

/**
 * Peripheral base address for regs device on sram_ctrl_ret_aon in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_RET_AON_REGS_BASE_ADDR 0x30500000u

/**
 * Peripheral size for regs device on sram_ctrl_ret_aon in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SRAM_CTRL_RET_AON_REGS_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SRAM_CTRL_RET_AON_REGS_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SRAM_CTRL_RET_AON_REGS_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_RET_AON_REGS_SIZE_BYTES 0x40u

/**
 * Peripheral base address for ram device on sram_ctrl_ret_aon in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_RET_AON_RAM_BASE_ADDR 0x30600000u

/**
 * Peripheral size for ram device on sram_ctrl_ret_aon in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SRAM_CTRL_RET_AON_RAM_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SRAM_CTRL_RET_AON_RAM_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SRAM_CTRL_RET_AON_RAM_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_RET_AON_RAM_SIZE_BYTES 0x1000u

/**
 * Peripheral base address for rv_plic in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_RV_PLIC_BASE_ADDR 0x28000000u

/**
 * Peripheral size for rv_plic in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_RV_PLIC_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_RV_PLIC_BASE_ADDR + TOP_DARJEELING_NO_IBEX_RV_PLIC_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_RV_PLIC_SIZE_BYTES 0x8000000u

/**
 * Peripheral base address for aes in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_AES_BASE_ADDR 0x21100000u

/**
 * Peripheral size for aes in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_AES_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_AES_BASE_ADDR + TOP_DARJEELING_NO_IBEX_AES_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_AES_SIZE_BYTES 0x100u

/**
 * Peripheral base address for hmac in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_HMAC_BASE_ADDR 0x21110000u

/**
 * Peripheral size for hmac in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_HMAC_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_HMAC_BASE_ADDR + TOP_DARJEELING_NO_IBEX_HMAC_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_HMAC_SIZE_BYTES 0x2000u

/**
 * Peripheral base address for kmac in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_KMAC_BASE_ADDR 0x21120000u

/**
 * Peripheral size for kmac in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_KMAC_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_KMAC_BASE_ADDR + TOP_DARJEELING_NO_IBEX_KMAC_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_KMAC_SIZE_BYTES 0x1000u

/**
 * Peripheral base address for otbn in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_OTBN_BASE_ADDR 0x21130000u

/**
 * Peripheral size for otbn in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_OTBN_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_OTBN_BASE_ADDR + TOP_DARJEELING_NO_IBEX_OTBN_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_OTBN_SIZE_BYTES 0x10000u

/**
 * Peripheral base address for keymgr_dpe in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_KEYMGR_DPE_BASE_ADDR 0x21140000u

/**
 * Peripheral size for keymgr_dpe in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_KEYMGR_DPE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_KEYMGR_DPE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_KEYMGR_DPE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_KEYMGR_DPE_SIZE_BYTES 0x100u

/**
 * Peripheral base address for csrng in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_CSRNG_BASE_ADDR 0x21150000u

/**
 * Peripheral size for csrng in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_CSRNG_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_CSRNG_BASE_ADDR + TOP_DARJEELING_NO_IBEX_CSRNG_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_CSRNG_SIZE_BYTES 0x80u

/**
 * Peripheral base address for entropy_src in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_ENTROPY_SRC_BASE_ADDR 0x21160000u

/**
 * Peripheral size for entropy_src in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_ENTROPY_SRC_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_ENTROPY_SRC_BASE_ADDR + TOP_DARJEELING_NO_IBEX_ENTROPY_SRC_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_ENTROPY_SRC_SIZE_BYTES 0x100u

/**
 * Peripheral base address for edn0 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_EDN0_BASE_ADDR 0x21170000u

/**
 * Peripheral size for edn0 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_EDN0_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_EDN0_BASE_ADDR + TOP_DARJEELING_NO_IBEX_EDN0_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_EDN0_SIZE_BYTES 0x80u

/**
 * Peripheral base address for edn1 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_EDN1_BASE_ADDR 0x21180000u

/**
 * Peripheral size for edn1 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_EDN1_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_EDN1_BASE_ADDR + TOP_DARJEELING_NO_IBEX_EDN1_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_EDN1_SIZE_BYTES 0x80u

/**
 * Peripheral base address for regs device on sram_ctrl_main in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MAIN_REGS_BASE_ADDR 0x211C0000u

/**
 * Peripheral size for regs device on sram_ctrl_main in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MAIN_REGS_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MAIN_REGS_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MAIN_REGS_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MAIN_REGS_SIZE_BYTES 0x40u

/**
 * Peripheral base address for ram device on sram_ctrl_main in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MAIN_RAM_BASE_ADDR 0x10000000u

/**
 * Peripheral size for ram device on sram_ctrl_main in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MAIN_RAM_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MAIN_RAM_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MAIN_RAM_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MAIN_RAM_SIZE_BYTES 0x10000u

/**
 * Peripheral base address for regs device on sram_ctrl_mbox in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MBOX_REGS_BASE_ADDR 0x211D0000u

/**
 * Peripheral size for regs device on sram_ctrl_mbox in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MBOX_REGS_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MBOX_REGS_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MBOX_REGS_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MBOX_REGS_SIZE_BYTES 0x40u

/**
 * Peripheral base address for ram device on sram_ctrl_mbox in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MBOX_RAM_BASE_ADDR 0x11000000u

/**
 * Peripheral size for ram device on sram_ctrl_mbox in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MBOX_RAM_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MBOX_RAM_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MBOX_RAM_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SRAM_CTRL_MBOX_RAM_SIZE_BYTES 0x1000u

/**
 * Peripheral base address for regs device on rom_ctrl0 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_ROM_CTRL0_REGS_BASE_ADDR 0x211E0000u

/**
 * Peripheral size for regs device on rom_ctrl0 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_ROM_CTRL0_REGS_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_ROM_CTRL0_REGS_BASE_ADDR + TOP_DARJEELING_NO_IBEX_ROM_CTRL0_REGS_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_ROM_CTRL0_REGS_SIZE_BYTES 0x80u

/**
 * Peripheral base address for rom device on rom_ctrl0 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_ROM_CTRL0_ROM_BASE_ADDR 0x8000u

/**
 * Peripheral size for rom device on rom_ctrl0 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_ROM_CTRL0_ROM_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_ROM_CTRL0_ROM_BASE_ADDR + TOP_DARJEELING_NO_IBEX_ROM_CTRL0_ROM_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_ROM_CTRL0_ROM_SIZE_BYTES 0x8000u

/**
 * Peripheral base address for regs device on rom_ctrl1 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_ROM_CTRL1_REGS_BASE_ADDR 0x211E1000u

/**
 * Peripheral size for regs device on rom_ctrl1 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_ROM_CTRL1_REGS_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_ROM_CTRL1_REGS_BASE_ADDR + TOP_DARJEELING_NO_IBEX_ROM_CTRL1_REGS_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_ROM_CTRL1_REGS_SIZE_BYTES 0x80u

/**
 * Peripheral base address for rom device on rom_ctrl1 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_ROM_CTRL1_ROM_BASE_ADDR 0x20000u

/**
 * Peripheral size for rom device on rom_ctrl1 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_ROM_CTRL1_ROM_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_ROM_CTRL1_ROM_BASE_ADDR + TOP_DARJEELING_NO_IBEX_ROM_CTRL1_ROM_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_ROM_CTRL1_ROM_SIZE_BYTES 0x10000u

/**
 * Peripheral base address for dma in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_DMA_BASE_ADDR 0x22010000u

/**
 * Peripheral size for dma in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_DMA_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_DMA_BASE_ADDR + TOP_DARJEELING_NO_IBEX_DMA_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_DMA_SIZE_BYTES 0x200u

/**
 * Peripheral base address for core device on mbx0 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_MBX0_CORE_BASE_ADDR 0x22000000u

/**
 * Peripheral size for core device on mbx0 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_MBX0_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_MBX0_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_MBX0_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_MBX0_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx1 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_MBX1_CORE_BASE_ADDR 0x22000100u

/**
 * Peripheral size for core device on mbx1 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_MBX1_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_MBX1_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_MBX1_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_MBX1_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx2 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_MBX2_CORE_BASE_ADDR 0x22000200u

/**
 * Peripheral size for core device on mbx2 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_MBX2_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_MBX2_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_MBX2_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_MBX2_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx3 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_MBX3_CORE_BASE_ADDR 0x22000300u

/**
 * Peripheral size for core device on mbx3 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_MBX3_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_MBX3_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_MBX3_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_MBX3_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx4 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_MBX4_CORE_BASE_ADDR 0x22000400u

/**
 * Peripheral size for core device on mbx4 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_MBX4_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_MBX4_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_MBX4_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_MBX4_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx5 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_MBX5_CORE_BASE_ADDR 0x22000500u

/**
 * Peripheral size for core device on mbx5 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_MBX5_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_MBX5_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_MBX5_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_MBX5_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx6 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_MBX6_CORE_BASE_ADDR 0x22000600u

/**
 * Peripheral size for core device on mbx6 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_MBX6_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_MBX6_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_MBX6_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_MBX6_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx_jtag in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_MBX_JTAG_CORE_BASE_ADDR 0x22000800u

/**
 * Peripheral size for core device on mbx_jtag in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_MBX_JTAG_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_MBX_JTAG_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_MBX_JTAG_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_MBX_JTAG_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx_pcie0 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_MBX_PCIE0_CORE_BASE_ADDR 0x22040000u

/**
 * Peripheral size for core device on mbx_pcie0 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_MBX_PCIE0_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_MBX_PCIE0_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_MBX_PCIE0_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_MBX_PCIE0_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on mbx_pcie1 in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_MBX_PCIE1_CORE_BASE_ADDR 0x22040100u

/**
 * Peripheral size for core device on mbx_pcie1 in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_MBX_PCIE1_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_MBX_PCIE1_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_MBX_PCIE1_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_MBX_PCIE1_CORE_SIZE_BYTES 0x80u

/**
 * Peripheral base address for core device on soc_dbg_ctrl in top darjeeling_no_ibex.
 *
 * This should be used with #mmio_region_from_addr to access the memory-mapped
 * registers associated with the peripheral (usually via a DIF).
 */
#define TOP_DARJEELING_NO_IBEX_SOC_DBG_CTRL_CORE_BASE_ADDR 0x30170000u

/**
 * Peripheral size for core device on soc_dbg_ctrl in top darjeeling_no_ibex.
 *
 * This is the size (in bytes) of the peripheral's reserved memory area. All
 * memory-mapped registers associated with this peripheral should have an
 * address between #TOP_DARJEELING_NO_IBEX_SOC_DBG_CTRL_CORE_BASE_ADDR and
 * `TOP_DARJEELING_NO_IBEX_SOC_DBG_CTRL_CORE_BASE_ADDR + TOP_DARJEELING_NO_IBEX_SOC_DBG_CTRL_CORE_SIZE_BYTES`.
 */
#define TOP_DARJEELING_NO_IBEX_SOC_DBG_CTRL_CORE_SIZE_BYTES 0x20u


/**
 * Memory base address for ctn in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_CTN_BASE_ADDR 0x40000000u

/**
 * Memory size for ctn in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_CTN_SIZE_BYTES 0x40000000u

/**
 * Memory base address for ram_ret_aon in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_RAM_RET_AON_BASE_ADDR 0x30600000u

/**
 * Memory size for ram_ret_aon in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_RAM_RET_AON_SIZE_BYTES 0x1000u

/**
 * Memory base address for ram_main in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_RAM_MAIN_BASE_ADDR 0x10000000u

/**
 * Memory size for ram_main in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_RAM_MAIN_SIZE_BYTES 0x10000u

/**
 * Memory base address for ram_mbox in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_RAM_MBOX_BASE_ADDR 0x11000000u

/**
 * Memory size for ram_mbox in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_RAM_MBOX_SIZE_BYTES 0x1000u

/**
 * Memory base address for rom0 in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_ROM0_BASE_ADDR 0x8000u

/**
 * Memory size for rom0 in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_ROM0_SIZE_BYTES 0x8000u

/**
 * Memory base address for rom1 in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_ROM1_BASE_ADDR 0x20000u

/**
 * Memory size for rom1 in top darjeeling_no_ibex.
 */
#define TOP_DARJEELING_NO_IBEX_ROM1_SIZE_BYTES 0x10000u


/**
 * PLIC Interrupt Source Peripheral.
 *
 * Enumeration used to determine which peripheral asserted the corresponding
 * interrupt.
 */
typedef enum top_darjeeling_no_ibex_plic_peripheral {
  kTopDarjeelingNoIbexPlicPeripheralUnknown = 0, /**< Unknown Peripheral */
  kTopDarjeelingNoIbexPlicPeripheralUart0 = 1, /**< uart0 */
  kTopDarjeelingNoIbexPlicPeripheralGpio = 2, /**< gpio */
  kTopDarjeelingNoIbexPlicPeripheralSpiDevice = 3, /**< spi_device */
  kTopDarjeelingNoIbexPlicPeripheralI2c0 = 4, /**< i2c0 */
  kTopDarjeelingNoIbexPlicPeripheralOtpCtrl = 5, /**< otp_ctrl */
  kTopDarjeelingNoIbexPlicPeripheralAlertHandler = 6, /**< alert_handler */
  kTopDarjeelingNoIbexPlicPeripheralSpiHost0 = 7, /**< spi_host0 */
  kTopDarjeelingNoIbexPlicPeripheralPwrmgrAon = 8, /**< pwrmgr_aon */
  kTopDarjeelingNoIbexPlicPeripheralAonTimerAon = 9, /**< aon_timer_aon */
  kTopDarjeelingNoIbexPlicPeripheralSocProxy = 10, /**< soc_proxy */
  kTopDarjeelingNoIbexPlicPeripheralHmac = 11, /**< hmac */
  kTopDarjeelingNoIbexPlicPeripheralKmac = 12, /**< kmac */
  kTopDarjeelingNoIbexPlicPeripheralOtbn = 13, /**< otbn */
  kTopDarjeelingNoIbexPlicPeripheralKeymgrDpe = 14, /**< keymgr_dpe */
  kTopDarjeelingNoIbexPlicPeripheralCsrng = 15, /**< csrng */
  kTopDarjeelingNoIbexPlicPeripheralEntropySrc = 16, /**< entropy_src */
  kTopDarjeelingNoIbexPlicPeripheralEdn0 = 17, /**< edn0 */
  kTopDarjeelingNoIbexPlicPeripheralEdn1 = 18, /**< edn1 */
  kTopDarjeelingNoIbexPlicPeripheralDma = 19, /**< dma */
  kTopDarjeelingNoIbexPlicPeripheralMbx0 = 20, /**< mbx0 */
  kTopDarjeelingNoIbexPlicPeripheralMbx1 = 21, /**< mbx1 */
  kTopDarjeelingNoIbexPlicPeripheralMbx2 = 22, /**< mbx2 */
  kTopDarjeelingNoIbexPlicPeripheralMbx3 = 23, /**< mbx3 */
  kTopDarjeelingNoIbexPlicPeripheralMbx4 = 24, /**< mbx4 */
  kTopDarjeelingNoIbexPlicPeripheralMbx5 = 25, /**< mbx5 */
  kTopDarjeelingNoIbexPlicPeripheralMbx6 = 26, /**< mbx6 */
  kTopDarjeelingNoIbexPlicPeripheralMbxJtag = 27, /**< mbx_jtag */
  kTopDarjeelingNoIbexPlicPeripheralMbxPcie0 = 28, /**< mbx_pcie0 */
  kTopDarjeelingNoIbexPlicPeripheralMbxPcie1 = 29, /**< mbx_pcie1 */
  kTopDarjeelingNoIbexPlicPeripheralRaclCtrl = 30, /**< racl_ctrl */
  kTopDarjeelingNoIbexPlicPeripheralAcRangeCheck = 31, /**< ac_range_check */
  kTopDarjeelingNoIbexPlicPeripheralLast = 31, /**< \internal Final PLIC peripheral */
} top_darjeeling_no_ibex_plic_peripheral_t;

/**
 * PLIC Interrupt Source.
 *
 * Enumeration of all PLIC interrupt sources. The interrupt sources belonging to
 * the same peripheral are guaranteed to be consecutive.
 */
typedef enum top_darjeeling_no_ibex_plic_irq_id {
  kTopDarjeelingNoIbexPlicIrqIdNone = 0, /**< No Interrupt */
  kTopDarjeelingNoIbexPlicIrqIdUart0TxWatermark = 1, /**< uart0_tx_watermark */
  kTopDarjeelingNoIbexPlicIrqIdUart0RxWatermark = 2, /**< uart0_rx_watermark */
  kTopDarjeelingNoIbexPlicIrqIdUart0TxDone = 3, /**< uart0_tx_done */
  kTopDarjeelingNoIbexPlicIrqIdUart0RxOverflow = 4, /**< uart0_rx_overflow */
  kTopDarjeelingNoIbexPlicIrqIdUart0RxFrameErr = 5, /**< uart0_rx_frame_err */
  kTopDarjeelingNoIbexPlicIrqIdUart0RxBreakErr = 6, /**< uart0_rx_break_err */
  kTopDarjeelingNoIbexPlicIrqIdUart0RxTimeout = 7, /**< uart0_rx_timeout */
  kTopDarjeelingNoIbexPlicIrqIdUart0RxParityErr = 8, /**< uart0_rx_parity_err */
  kTopDarjeelingNoIbexPlicIrqIdUart0TxEmpty = 9, /**< uart0_tx_empty */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio0 = 10, /**< gpio_gpio 0 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio1 = 11, /**< gpio_gpio 1 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio2 = 12, /**< gpio_gpio 2 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio3 = 13, /**< gpio_gpio 3 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio4 = 14, /**< gpio_gpio 4 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio5 = 15, /**< gpio_gpio 5 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio6 = 16, /**< gpio_gpio 6 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio7 = 17, /**< gpio_gpio 7 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio8 = 18, /**< gpio_gpio 8 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio9 = 19, /**< gpio_gpio 9 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio10 = 20, /**< gpio_gpio 10 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio11 = 21, /**< gpio_gpio 11 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio12 = 22, /**< gpio_gpio 12 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio13 = 23, /**< gpio_gpio 13 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio14 = 24, /**< gpio_gpio 14 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio15 = 25, /**< gpio_gpio 15 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio16 = 26, /**< gpio_gpio 16 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio17 = 27, /**< gpio_gpio 17 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio18 = 28, /**< gpio_gpio 18 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio19 = 29, /**< gpio_gpio 19 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio20 = 30, /**< gpio_gpio 20 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio21 = 31, /**< gpio_gpio 21 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio22 = 32, /**< gpio_gpio 22 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio23 = 33, /**< gpio_gpio 23 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio24 = 34, /**< gpio_gpio 24 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio25 = 35, /**< gpio_gpio 25 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio26 = 36, /**< gpio_gpio 26 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio27 = 37, /**< gpio_gpio 27 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio28 = 38, /**< gpio_gpio 28 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio29 = 39, /**< gpio_gpio 29 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio30 = 40, /**< gpio_gpio 30 */
  kTopDarjeelingNoIbexPlicIrqIdGpioGpio31 = 41, /**< gpio_gpio 31 */
  kTopDarjeelingNoIbexPlicIrqIdSpiDeviceUploadCmdfifoNotEmpty = 42, /**< spi_device_upload_cmdfifo_not_empty */
  kTopDarjeelingNoIbexPlicIrqIdSpiDeviceUploadPayloadNotEmpty = 43, /**< spi_device_upload_payload_not_empty */
  kTopDarjeelingNoIbexPlicIrqIdSpiDeviceUploadPayloadOverflow = 44, /**< spi_device_upload_payload_overflow */
  kTopDarjeelingNoIbexPlicIrqIdSpiDeviceReadbufWatermark = 45, /**< spi_device_readbuf_watermark */
  kTopDarjeelingNoIbexPlicIrqIdSpiDeviceReadbufFlip = 46, /**< spi_device_readbuf_flip */
  kTopDarjeelingNoIbexPlicIrqIdSpiDeviceTpmHeaderNotEmpty = 47, /**< spi_device_tpm_header_not_empty */
  kTopDarjeelingNoIbexPlicIrqIdSpiDeviceTpmRdfifoCmdEnd = 48, /**< spi_device_tpm_rdfifo_cmd_end */
  kTopDarjeelingNoIbexPlicIrqIdSpiDeviceTpmRdfifoDrop = 49, /**< spi_device_tpm_rdfifo_drop */
  kTopDarjeelingNoIbexPlicIrqIdI2c0FmtThreshold = 50, /**< i2c0_fmt_threshold */
  kTopDarjeelingNoIbexPlicIrqIdI2c0RxThreshold = 51, /**< i2c0_rx_threshold */
  kTopDarjeelingNoIbexPlicIrqIdI2c0AcqThreshold = 52, /**< i2c0_acq_threshold */
  kTopDarjeelingNoIbexPlicIrqIdI2c0RxOverflow = 53, /**< i2c0_rx_overflow */
  kTopDarjeelingNoIbexPlicIrqIdI2c0ControllerHalt = 54, /**< i2c0_controller_halt */
  kTopDarjeelingNoIbexPlicIrqIdI2c0SclInterference = 55, /**< i2c0_scl_interference */
  kTopDarjeelingNoIbexPlicIrqIdI2c0SdaInterference = 56, /**< i2c0_sda_interference */
  kTopDarjeelingNoIbexPlicIrqIdI2c0StretchTimeout = 57, /**< i2c0_stretch_timeout */
  kTopDarjeelingNoIbexPlicIrqIdI2c0SdaUnstable = 58, /**< i2c0_sda_unstable */
  kTopDarjeelingNoIbexPlicIrqIdI2c0CmdComplete = 59, /**< i2c0_cmd_complete */
  kTopDarjeelingNoIbexPlicIrqIdI2c0TxStretch = 60, /**< i2c0_tx_stretch */
  kTopDarjeelingNoIbexPlicIrqIdI2c0TxThreshold = 61, /**< i2c0_tx_threshold */
  kTopDarjeelingNoIbexPlicIrqIdI2c0AcqStretch = 62, /**< i2c0_acq_stretch */
  kTopDarjeelingNoIbexPlicIrqIdI2c0UnexpStop = 63, /**< i2c0_unexp_stop */
  kTopDarjeelingNoIbexPlicIrqIdI2c0HostTimeout = 64, /**< i2c0_host_timeout */
  kTopDarjeelingNoIbexPlicIrqIdOtpCtrlOtpOperationDone = 65, /**< otp_ctrl_otp_operation_done */
  kTopDarjeelingNoIbexPlicIrqIdOtpCtrlOtpError = 66, /**< otp_ctrl_otp_error */
  kTopDarjeelingNoIbexPlicIrqIdAlertHandlerClassa = 67, /**< alert_handler_classa */
  kTopDarjeelingNoIbexPlicIrqIdAlertHandlerClassb = 68, /**< alert_handler_classb */
  kTopDarjeelingNoIbexPlicIrqIdAlertHandlerClassc = 69, /**< alert_handler_classc */
  kTopDarjeelingNoIbexPlicIrqIdAlertHandlerClassd = 70, /**< alert_handler_classd */
  kTopDarjeelingNoIbexPlicIrqIdSpiHost0Error = 71, /**< spi_host0_error */
  kTopDarjeelingNoIbexPlicIrqIdSpiHost0SpiEvent = 72, /**< spi_host0_spi_event */
  kTopDarjeelingNoIbexPlicIrqIdPwrmgrAonWakeup = 73, /**< pwrmgr_aon_wakeup */
  kTopDarjeelingNoIbexPlicIrqIdAonTimerAonWkupTimerExpired = 74, /**< aon_timer_aon_wkup_timer_expired */
  kTopDarjeelingNoIbexPlicIrqIdAonTimerAonWdogTimerBark = 75, /**< aon_timer_aon_wdog_timer_bark */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal0 = 76, /**< soc_proxy_external 0 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal1 = 77, /**< soc_proxy_external 1 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal2 = 78, /**< soc_proxy_external 2 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal3 = 79, /**< soc_proxy_external 3 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal4 = 80, /**< soc_proxy_external 4 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal5 = 81, /**< soc_proxy_external 5 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal6 = 82, /**< soc_proxy_external 6 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal7 = 83, /**< soc_proxy_external 7 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal8 = 84, /**< soc_proxy_external 8 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal9 = 85, /**< soc_proxy_external 9 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal10 = 86, /**< soc_proxy_external 10 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal11 = 87, /**< soc_proxy_external 11 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal12 = 88, /**< soc_proxy_external 12 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal13 = 89, /**< soc_proxy_external 13 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal14 = 90, /**< soc_proxy_external 14 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal15 = 91, /**< soc_proxy_external 15 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal16 = 92, /**< soc_proxy_external 16 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal17 = 93, /**< soc_proxy_external 17 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal18 = 94, /**< soc_proxy_external 18 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal19 = 95, /**< soc_proxy_external 19 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal20 = 96, /**< soc_proxy_external 20 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal21 = 97, /**< soc_proxy_external 21 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal22 = 98, /**< soc_proxy_external 22 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal23 = 99, /**< soc_proxy_external 23 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal24 = 100, /**< soc_proxy_external 24 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal25 = 101, /**< soc_proxy_external 25 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal26 = 102, /**< soc_proxy_external 26 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal27 = 103, /**< soc_proxy_external 27 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal28 = 104, /**< soc_proxy_external 28 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal29 = 105, /**< soc_proxy_external 29 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal30 = 106, /**< soc_proxy_external 30 */
  kTopDarjeelingNoIbexPlicIrqIdSocProxyExternal31 = 107, /**< soc_proxy_external 31 */
  kTopDarjeelingNoIbexPlicIrqIdHmacHmacDone = 108, /**< hmac_hmac_done */
  kTopDarjeelingNoIbexPlicIrqIdHmacFifoEmpty = 109, /**< hmac_fifo_empty */
  kTopDarjeelingNoIbexPlicIrqIdHmacHmacErr = 110, /**< hmac_hmac_err */
  kTopDarjeelingNoIbexPlicIrqIdKmacKmacDone = 111, /**< kmac_kmac_done */
  kTopDarjeelingNoIbexPlicIrqIdKmacFifoEmpty = 112, /**< kmac_fifo_empty */
  kTopDarjeelingNoIbexPlicIrqIdKmacKmacErr = 113, /**< kmac_kmac_err */
  kTopDarjeelingNoIbexPlicIrqIdOtbnDone = 114, /**< otbn_done */
  kTopDarjeelingNoIbexPlicIrqIdKeymgrDpeOpDone = 115, /**< keymgr_dpe_op_done */
  kTopDarjeelingNoIbexPlicIrqIdCsrngCsCmdReqDone = 116, /**< csrng_cs_cmd_req_done */
  kTopDarjeelingNoIbexPlicIrqIdCsrngCsEntropyReq = 117, /**< csrng_cs_entropy_req */
  kTopDarjeelingNoIbexPlicIrqIdCsrngCsHwInstExc = 118, /**< csrng_cs_hw_inst_exc */
  kTopDarjeelingNoIbexPlicIrqIdCsrngCsFatalErr = 119, /**< csrng_cs_fatal_err */
  kTopDarjeelingNoIbexPlicIrqIdEntropySrcEsEntropyValid = 120, /**< entropy_src_es_entropy_valid */
  kTopDarjeelingNoIbexPlicIrqIdEntropySrcEsHealthTestFailed = 121, /**< entropy_src_es_health_test_failed */
  kTopDarjeelingNoIbexPlicIrqIdEntropySrcEsObserveFifoReady = 122, /**< entropy_src_es_observe_fifo_ready */
  kTopDarjeelingNoIbexPlicIrqIdEntropySrcEsFatalErr = 123, /**< entropy_src_es_fatal_err */
  kTopDarjeelingNoIbexPlicIrqIdEdn0EdnCmdReqDone = 124, /**< edn0_edn_cmd_req_done */
  kTopDarjeelingNoIbexPlicIrqIdEdn0EdnFatalErr = 125, /**< edn0_edn_fatal_err */
  kTopDarjeelingNoIbexPlicIrqIdEdn1EdnCmdReqDone = 126, /**< edn1_edn_cmd_req_done */
  kTopDarjeelingNoIbexPlicIrqIdEdn1EdnFatalErr = 127, /**< edn1_edn_fatal_err */
  kTopDarjeelingNoIbexPlicIrqIdDmaDmaDone = 128, /**< dma_dma_done */
  kTopDarjeelingNoIbexPlicIrqIdDmaDmaChunkDone = 129, /**< dma_dma_chunk_done */
  kTopDarjeelingNoIbexPlicIrqIdDmaDmaError = 130, /**< dma_dma_error */
  kTopDarjeelingNoIbexPlicIrqIdMbx0MbxReady = 131, /**< mbx0_mbx_ready */
  kTopDarjeelingNoIbexPlicIrqIdMbx0MbxAbort = 132, /**< mbx0_mbx_abort */
  kTopDarjeelingNoIbexPlicIrqIdMbx0MbxError = 133, /**< mbx0_mbx_error */
  kTopDarjeelingNoIbexPlicIrqIdMbx1MbxReady = 134, /**< mbx1_mbx_ready */
  kTopDarjeelingNoIbexPlicIrqIdMbx1MbxAbort = 135, /**< mbx1_mbx_abort */
  kTopDarjeelingNoIbexPlicIrqIdMbx1MbxError = 136, /**< mbx1_mbx_error */
  kTopDarjeelingNoIbexPlicIrqIdMbx2MbxReady = 137, /**< mbx2_mbx_ready */
  kTopDarjeelingNoIbexPlicIrqIdMbx2MbxAbort = 138, /**< mbx2_mbx_abort */
  kTopDarjeelingNoIbexPlicIrqIdMbx2MbxError = 139, /**< mbx2_mbx_error */
  kTopDarjeelingNoIbexPlicIrqIdMbx3MbxReady = 140, /**< mbx3_mbx_ready */
  kTopDarjeelingNoIbexPlicIrqIdMbx3MbxAbort = 141, /**< mbx3_mbx_abort */
  kTopDarjeelingNoIbexPlicIrqIdMbx3MbxError = 142, /**< mbx3_mbx_error */
  kTopDarjeelingNoIbexPlicIrqIdMbx4MbxReady = 143, /**< mbx4_mbx_ready */
  kTopDarjeelingNoIbexPlicIrqIdMbx4MbxAbort = 144, /**< mbx4_mbx_abort */
  kTopDarjeelingNoIbexPlicIrqIdMbx4MbxError = 145, /**< mbx4_mbx_error */
  kTopDarjeelingNoIbexPlicIrqIdMbx5MbxReady = 146, /**< mbx5_mbx_ready */
  kTopDarjeelingNoIbexPlicIrqIdMbx5MbxAbort = 147, /**< mbx5_mbx_abort */
  kTopDarjeelingNoIbexPlicIrqIdMbx5MbxError = 148, /**< mbx5_mbx_error */
  kTopDarjeelingNoIbexPlicIrqIdMbx6MbxReady = 149, /**< mbx6_mbx_ready */
  kTopDarjeelingNoIbexPlicIrqIdMbx6MbxAbort = 150, /**< mbx6_mbx_abort */
  kTopDarjeelingNoIbexPlicIrqIdMbx6MbxError = 151, /**< mbx6_mbx_error */
  kTopDarjeelingNoIbexPlicIrqIdMbxJtagMbxReady = 152, /**< mbx_jtag_mbx_ready */
  kTopDarjeelingNoIbexPlicIrqIdMbxJtagMbxAbort = 153, /**< mbx_jtag_mbx_abort */
  kTopDarjeelingNoIbexPlicIrqIdMbxJtagMbxError = 154, /**< mbx_jtag_mbx_error */
  kTopDarjeelingNoIbexPlicIrqIdMbxPcie0MbxReady = 155, /**< mbx_pcie0_mbx_ready */
  kTopDarjeelingNoIbexPlicIrqIdMbxPcie0MbxAbort = 156, /**< mbx_pcie0_mbx_abort */
  kTopDarjeelingNoIbexPlicIrqIdMbxPcie0MbxError = 157, /**< mbx_pcie0_mbx_error */
  kTopDarjeelingNoIbexPlicIrqIdMbxPcie1MbxReady = 158, /**< mbx_pcie1_mbx_ready */
  kTopDarjeelingNoIbexPlicIrqIdMbxPcie1MbxAbort = 159, /**< mbx_pcie1_mbx_abort */
  kTopDarjeelingNoIbexPlicIrqIdMbxPcie1MbxError = 160, /**< mbx_pcie1_mbx_error */
  kTopDarjeelingNoIbexPlicIrqIdRaclCtrlRaclError = 161, /**< racl_ctrl_racl_error */
  kTopDarjeelingNoIbexPlicIrqIdAcRangeCheckDenyCntReached = 162, /**< ac_range_check_deny_cnt_reached */
  kTopDarjeelingNoIbexPlicIrqIdLast = 162, /**< \internal The Last Valid Interrupt ID. */
} top_darjeeling_no_ibex_plic_irq_id_t;

/**
 * PLIC Interrupt Source to Peripheral Map
 *
 * This array is a mapping from `top_darjeeling_no_ibex_plic_irq_id_t` to
 * `top_darjeeling_no_ibex_plic_peripheral_t`.
 */
extern const top_darjeeling_no_ibex_plic_peripheral_t
    top_darjeeling_no_ibex_plic_interrupt_for_peripheral[163];

/**
 * PLIC Interrupt Target.
 *
 * Enumeration used to determine which set of IE, CC, threshold registers to
 * access for a given interrupt target.
 */
typedef enum top_darjeeling_no_ibex_plic_target {
  kTopDarjeelingNoIbexPlicTargetIbex0 = 0, /**< Ibex Core 0 */
  kTopDarjeelingNoIbexPlicTargetLast = 0, /**< \internal Final PLIC target */
} top_darjeeling_no_ibex_plic_target_t;


/**
 * Alert Handler Source Peripheral.
 *
 * Enumeration used to determine which peripheral asserted the corresponding
 * alert.
 */
typedef enum top_darjeeling_no_ibex_alert_peripheral {
  kTopDarjeelingNoIbexAlertPeripheralExternal = 0, /**< External Peripheral */
  kTopDarjeelingNoIbexAlertPeripheralUart0 = 1, /**< uart0 */
  kTopDarjeelingNoIbexAlertPeripheralGpio = 2, /**< gpio */
  kTopDarjeelingNoIbexAlertPeripheralSpiDevice = 3, /**< spi_device */
  kTopDarjeelingNoIbexAlertPeripheralI2c0 = 4, /**< i2c0 */
  kTopDarjeelingNoIbexAlertPeripheralOtpCtrl = 5, /**< otp_ctrl */
  kTopDarjeelingNoIbexAlertPeripheralLcCtrl = 6, /**< lc_ctrl */
  kTopDarjeelingNoIbexAlertPeripheralSpiHost0 = 7, /**< spi_host0 */
  kTopDarjeelingNoIbexAlertPeripheralPwrmgrAon = 8, /**< pwrmgr_aon */
  kTopDarjeelingNoIbexAlertPeripheralRstmgrAon = 9, /**< rstmgr_aon */
  kTopDarjeelingNoIbexAlertPeripheralClkmgrAon = 10, /**< clkmgr_aon */
  kTopDarjeelingNoIbexAlertPeripheralPinmuxAon = 11, /**< pinmux_aon */
  kTopDarjeelingNoIbexAlertPeripheralAonTimerAon = 12, /**< aon_timer_aon */
  kTopDarjeelingNoIbexAlertPeripheralSocProxy = 13, /**< soc_proxy */
  kTopDarjeelingNoIbexAlertPeripheralSramCtrlRetAon = 14, /**< sram_ctrl_ret_aon */
  kTopDarjeelingNoIbexAlertPeripheralRvPlic = 15, /**< rv_plic */
  kTopDarjeelingNoIbexAlertPeripheralAes = 16, /**< aes */
  kTopDarjeelingNoIbexAlertPeripheralHmac = 17, /**< hmac */
  kTopDarjeelingNoIbexAlertPeripheralKmac = 18, /**< kmac */
  kTopDarjeelingNoIbexAlertPeripheralOtbn = 19, /**< otbn */
  kTopDarjeelingNoIbexAlertPeripheralKeymgrDpe = 20, /**< keymgr_dpe */
  kTopDarjeelingNoIbexAlertPeripheralCsrng = 21, /**< csrng */
  kTopDarjeelingNoIbexAlertPeripheralEntropySrc = 22, /**< entropy_src */
  kTopDarjeelingNoIbexAlertPeripheralEdn0 = 23, /**< edn0 */
  kTopDarjeelingNoIbexAlertPeripheralEdn1 = 24, /**< edn1 */
  kTopDarjeelingNoIbexAlertPeripheralSramCtrlMain = 25, /**< sram_ctrl_main */
  kTopDarjeelingNoIbexAlertPeripheralSramCtrlMbox = 26, /**< sram_ctrl_mbox */
  kTopDarjeelingNoIbexAlertPeripheralRomCtrl0 = 27, /**< rom_ctrl0 */
  kTopDarjeelingNoIbexAlertPeripheralRomCtrl1 = 28, /**< rom_ctrl1 */
  kTopDarjeelingNoIbexAlertPeripheralDma = 29, /**< dma */
  kTopDarjeelingNoIbexAlertPeripheralMbx0 = 30, /**< mbx0 */
  kTopDarjeelingNoIbexAlertPeripheralMbx1 = 31, /**< mbx1 */
  kTopDarjeelingNoIbexAlertPeripheralMbx2 = 32, /**< mbx2 */
  kTopDarjeelingNoIbexAlertPeripheralMbx3 = 33, /**< mbx3 */
  kTopDarjeelingNoIbexAlertPeripheralMbx4 = 34, /**< mbx4 */
  kTopDarjeelingNoIbexAlertPeripheralMbx5 = 35, /**< mbx5 */
  kTopDarjeelingNoIbexAlertPeripheralMbx6 = 36, /**< mbx6 */
  kTopDarjeelingNoIbexAlertPeripheralMbxJtag = 37, /**< mbx_jtag */
  kTopDarjeelingNoIbexAlertPeripheralMbxPcie0 = 38, /**< mbx_pcie0 */
  kTopDarjeelingNoIbexAlertPeripheralMbxPcie1 = 39, /**< mbx_pcie1 */
  kTopDarjeelingNoIbexAlertPeripheralSocDbgCtrl = 40, /**< soc_dbg_ctrl */
  kTopDarjeelingNoIbexAlertPeripheralRaclCtrl = 41, /**< racl_ctrl */
  kTopDarjeelingNoIbexAlertPeripheralAcRangeCheck = 42, /**< ac_range_check */
  kTopDarjeelingNoIbexAlertPeripheralLast = 42, /**< \internal Final Alert peripheral */
} top_darjeeling_no_ibex_alert_peripheral_t;

/**
 * Alert Handler Alert Source.
 *
 * Enumeration of all Alert Handler Alert Sources. The alert sources belonging to
 * the same peripheral are guaranteed to be consecutive.
 */
typedef enum top_darjeeling_no_ibex_alert_id {
  kTopDarjeelingNoIbexAlertIdUart0FatalFault = 0, /**< uart0_fatal_fault */
  kTopDarjeelingNoIbexAlertIdGpioFatalFault = 1, /**< gpio_fatal_fault */
  kTopDarjeelingNoIbexAlertIdSpiDeviceFatalFault = 2, /**< spi_device_fatal_fault */
  kTopDarjeelingNoIbexAlertIdI2c0FatalFault = 3, /**< i2c0_fatal_fault */
  kTopDarjeelingNoIbexAlertIdOtpCtrlFatalMacroError = 4, /**< otp_ctrl_fatal_macro_error */
  kTopDarjeelingNoIbexAlertIdOtpCtrlFatalCheckError = 5, /**< otp_ctrl_fatal_check_error */
  kTopDarjeelingNoIbexAlertIdOtpCtrlFatalBusIntegError = 6, /**< otp_ctrl_fatal_bus_integ_error */
  kTopDarjeelingNoIbexAlertIdOtpCtrlFatalPrimOtpAlert = 7, /**< otp_ctrl_fatal_prim_otp_alert */
  kTopDarjeelingNoIbexAlertIdOtpCtrlRecovPrimOtpAlert = 8, /**< otp_ctrl_recov_prim_otp_alert */
  kTopDarjeelingNoIbexAlertIdLcCtrlFatalProgError = 9, /**< lc_ctrl_fatal_prog_error */
  kTopDarjeelingNoIbexAlertIdLcCtrlFatalStateError = 10, /**< lc_ctrl_fatal_state_error */
  kTopDarjeelingNoIbexAlertIdLcCtrlFatalBusIntegError = 11, /**< lc_ctrl_fatal_bus_integ_error */
  kTopDarjeelingNoIbexAlertIdSpiHost0FatalFault = 12, /**< spi_host0_fatal_fault */
  kTopDarjeelingNoIbexAlertIdPwrmgrAonFatalFault = 13, /**< pwrmgr_aon_fatal_fault */
  kTopDarjeelingNoIbexAlertIdRstmgrAonFatalFault = 14, /**< rstmgr_aon_fatal_fault */
  kTopDarjeelingNoIbexAlertIdRstmgrAonFatalCnstyFault = 15, /**< rstmgr_aon_fatal_cnsty_fault */
  kTopDarjeelingNoIbexAlertIdClkmgrAonRecovFault = 16, /**< clkmgr_aon_recov_fault */
  kTopDarjeelingNoIbexAlertIdClkmgrAonFatalFault = 17, /**< clkmgr_aon_fatal_fault */
  kTopDarjeelingNoIbexAlertIdPinmuxAonFatalFault = 18, /**< pinmux_aon_fatal_fault */
  kTopDarjeelingNoIbexAlertIdAonTimerAonFatalFault = 19, /**< aon_timer_aon_fatal_fault */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertIntg = 20, /**< soc_proxy_fatal_alert_intg */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal0 = 21, /**< soc_proxy_fatal_alert_external_0 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal1 = 22, /**< soc_proxy_fatal_alert_external_1 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal2 = 23, /**< soc_proxy_fatal_alert_external_2 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal3 = 24, /**< soc_proxy_fatal_alert_external_3 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal4 = 25, /**< soc_proxy_fatal_alert_external_4 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal5 = 26, /**< soc_proxy_fatal_alert_external_5 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal6 = 27, /**< soc_proxy_fatal_alert_external_6 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal7 = 28, /**< soc_proxy_fatal_alert_external_7 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal8 = 29, /**< soc_proxy_fatal_alert_external_8 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal9 = 30, /**< soc_proxy_fatal_alert_external_9 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal10 = 31, /**< soc_proxy_fatal_alert_external_10 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal11 = 32, /**< soc_proxy_fatal_alert_external_11 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal12 = 33, /**< soc_proxy_fatal_alert_external_12 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal13 = 34, /**< soc_proxy_fatal_alert_external_13 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal14 = 35, /**< soc_proxy_fatal_alert_external_14 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal15 = 36, /**< soc_proxy_fatal_alert_external_15 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal16 = 37, /**< soc_proxy_fatal_alert_external_16 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal17 = 38, /**< soc_proxy_fatal_alert_external_17 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal18 = 39, /**< soc_proxy_fatal_alert_external_18 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal19 = 40, /**< soc_proxy_fatal_alert_external_19 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal20 = 41, /**< soc_proxy_fatal_alert_external_20 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal21 = 42, /**< soc_proxy_fatal_alert_external_21 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal22 = 43, /**< soc_proxy_fatal_alert_external_22 */
  kTopDarjeelingNoIbexAlertIdSocProxyFatalAlertExternal23 = 44, /**< soc_proxy_fatal_alert_external_23 */
  kTopDarjeelingNoIbexAlertIdSocProxyRecovAlertExternal0 = 45, /**< soc_proxy_recov_alert_external_0 */
  kTopDarjeelingNoIbexAlertIdSocProxyRecovAlertExternal1 = 46, /**< soc_proxy_recov_alert_external_1 */
  kTopDarjeelingNoIbexAlertIdSocProxyRecovAlertExternal2 = 47, /**< soc_proxy_recov_alert_external_2 */
  kTopDarjeelingNoIbexAlertIdSocProxyRecovAlertExternal3 = 48, /**< soc_proxy_recov_alert_external_3 */
  kTopDarjeelingNoIbexAlertIdSramCtrlRetAonFatalError = 49, /**< sram_ctrl_ret_aon_fatal_error */
  kTopDarjeelingNoIbexAlertIdRvPlicFatalFault = 50, /**< rv_plic_fatal_fault */
  kTopDarjeelingNoIbexAlertIdAesRecovCtrlUpdateErr = 51, /**< aes_recov_ctrl_update_err */
  kTopDarjeelingNoIbexAlertIdAesFatalFault = 52, /**< aes_fatal_fault */
  kTopDarjeelingNoIbexAlertIdHmacFatalFault = 53, /**< hmac_fatal_fault */
  kTopDarjeelingNoIbexAlertIdKmacRecovOperationErr = 54, /**< kmac_recov_operation_err */
  kTopDarjeelingNoIbexAlertIdKmacFatalFaultErr = 55, /**< kmac_fatal_fault_err */
  kTopDarjeelingNoIbexAlertIdOtbnFatal = 56, /**< otbn_fatal */
  kTopDarjeelingNoIbexAlertIdOtbnRecov = 57, /**< otbn_recov */
  kTopDarjeelingNoIbexAlertIdKeymgrDpeRecovOperationErr = 58, /**< keymgr_dpe_recov_operation_err */
  kTopDarjeelingNoIbexAlertIdKeymgrDpeFatalFaultErr = 59, /**< keymgr_dpe_fatal_fault_err */
  kTopDarjeelingNoIbexAlertIdCsrngRecovAlert = 60, /**< csrng_recov_alert */
  kTopDarjeelingNoIbexAlertIdCsrngFatalAlert = 61, /**< csrng_fatal_alert */
  kTopDarjeelingNoIbexAlertIdEntropySrcRecovAlert = 62, /**< entropy_src_recov_alert */
  kTopDarjeelingNoIbexAlertIdEntropySrcFatalAlert = 63, /**< entropy_src_fatal_alert */
  kTopDarjeelingNoIbexAlertIdEdn0RecovAlert = 64, /**< edn0_recov_alert */
  kTopDarjeelingNoIbexAlertIdEdn0FatalAlert = 65, /**< edn0_fatal_alert */
  kTopDarjeelingNoIbexAlertIdEdn1RecovAlert = 66, /**< edn1_recov_alert */
  kTopDarjeelingNoIbexAlertIdEdn1FatalAlert = 67, /**< edn1_fatal_alert */
  kTopDarjeelingNoIbexAlertIdSramCtrlMainFatalError = 68, /**< sram_ctrl_main_fatal_error */
  kTopDarjeelingNoIbexAlertIdSramCtrlMboxFatalError = 69, /**< sram_ctrl_mbox_fatal_error */
  kTopDarjeelingNoIbexAlertIdRomCtrl0Fatal = 70, /**< rom_ctrl0_fatal */
  kTopDarjeelingNoIbexAlertIdRomCtrl1Fatal = 71, /**< rom_ctrl1_fatal */
  kTopDarjeelingNoIbexAlertIdDmaFatalFault = 72, /**< dma_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbx0FatalFault = 73, /**< mbx0_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbx0RecovFault = 74, /**< mbx0_recov_fault */
  kTopDarjeelingNoIbexAlertIdMbx1FatalFault = 75, /**< mbx1_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbx1RecovFault = 76, /**< mbx1_recov_fault */
  kTopDarjeelingNoIbexAlertIdMbx2FatalFault = 77, /**< mbx2_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbx2RecovFault = 78, /**< mbx2_recov_fault */
  kTopDarjeelingNoIbexAlertIdMbx3FatalFault = 79, /**< mbx3_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbx3RecovFault = 80, /**< mbx3_recov_fault */
  kTopDarjeelingNoIbexAlertIdMbx4FatalFault = 81, /**< mbx4_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbx4RecovFault = 82, /**< mbx4_recov_fault */
  kTopDarjeelingNoIbexAlertIdMbx5FatalFault = 83, /**< mbx5_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbx5RecovFault = 84, /**< mbx5_recov_fault */
  kTopDarjeelingNoIbexAlertIdMbx6FatalFault = 85, /**< mbx6_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbx6RecovFault = 86, /**< mbx6_recov_fault */
  kTopDarjeelingNoIbexAlertIdMbxJtagFatalFault = 87, /**< mbx_jtag_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbxJtagRecovFault = 88, /**< mbx_jtag_recov_fault */
  kTopDarjeelingNoIbexAlertIdMbxPcie0FatalFault = 89, /**< mbx_pcie0_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbxPcie0RecovFault = 90, /**< mbx_pcie0_recov_fault */
  kTopDarjeelingNoIbexAlertIdMbxPcie1FatalFault = 91, /**< mbx_pcie1_fatal_fault */
  kTopDarjeelingNoIbexAlertIdMbxPcie1RecovFault = 92, /**< mbx_pcie1_recov_fault */
  kTopDarjeelingNoIbexAlertIdSocDbgCtrlFatalFault = 93, /**< soc_dbg_ctrl_fatal_fault */
  kTopDarjeelingNoIbexAlertIdSocDbgCtrlRecovCtrlUpdateErr = 94, /**< soc_dbg_ctrl_recov_ctrl_update_err */
  kTopDarjeelingNoIbexAlertIdRaclCtrlFatalFault = 95, /**< racl_ctrl_fatal_fault */
  kTopDarjeelingNoIbexAlertIdRaclCtrlRecovCtrlUpdateErr = 96, /**< racl_ctrl_recov_ctrl_update_err */
  kTopDarjeelingNoIbexAlertIdAcRangeCheckRecovCtrlUpdateErr = 97, /**< ac_range_check_recov_ctrl_update_err */
  kTopDarjeelingNoIbexAlertIdAcRangeCheckFatalFault = 98, /**< ac_range_check_fatal_fault */
  kTopDarjeelingNoIbexAlertIdLast = 98, /**< \internal The Last Valid Alert ID. */
} top_darjeeling_no_ibex_alert_id_t;

/**
 * Alert Handler Alert Source to Peripheral Map
 *
 * This array is a mapping from `top_darjeeling_no_ibex_alert_id_t` to
 * `top_darjeeling_no_ibex_alert_peripheral_t`.
 */
extern const top_darjeeling_no_ibex_alert_peripheral_t
    top_darjeeling_no_ibex_alert_for_peripheral[99];

#define PINMUX_MIO_PERIPH_INSEL_IDX_OFFSET 2

// PERIPH_INSEL ranges from 0 to NUM_MIO_PADS + 2 -1}
//  0 and 1 are tied to value 0 and 1
#define NUM_MIO_PADS 12
#define NUM_DIO_PADS 73

#define PINMUX_PERIPH_OUTSEL_IDX_OFFSET 3

/**
 * Pinmux Peripheral Input.
 */
typedef enum top_darjeeling_no_ibex_pinmux_peripheral_in {
  kTopDarjeelingNoIbexPinmuxPeripheralInSocProxySocGpi12 = 0, /**< Peripheral Input 0 */
  kTopDarjeelingNoIbexPinmuxPeripheralInSocProxySocGpi13 = 1, /**< Peripheral Input 1 */
  kTopDarjeelingNoIbexPinmuxPeripheralInSocProxySocGpi14 = 2, /**< Peripheral Input 2 */
  kTopDarjeelingNoIbexPinmuxPeripheralInSocProxySocGpi15 = 3, /**< Peripheral Input 3 */
  kTopDarjeelingNoIbexPinmuxPeripheralInLast = 3, /**< \internal Last valid peripheral input */
} top_darjeeling_no_ibex_pinmux_peripheral_in_t;

/**
 * Pinmux MIO Input Selector.
 */
typedef enum top_darjeeling_no_ibex_pinmux_insel {
  kTopDarjeelingNoIbexPinmuxInselConstantZero = 0, /**< Tie constantly to zero */
  kTopDarjeelingNoIbexPinmuxInselConstantOne = 1, /**< Tie constantly to one */
  kTopDarjeelingNoIbexPinmuxInselMio0 = 2, /**< MIO Pad 0 */
  kTopDarjeelingNoIbexPinmuxInselMio1 = 3, /**< MIO Pad 1 */
  kTopDarjeelingNoIbexPinmuxInselMio2 = 4, /**< MIO Pad 2 */
  kTopDarjeelingNoIbexPinmuxInselMio3 = 5, /**< MIO Pad 3 */
  kTopDarjeelingNoIbexPinmuxInselMio4 = 6, /**< MIO Pad 4 */
  kTopDarjeelingNoIbexPinmuxInselMio5 = 7, /**< MIO Pad 5 */
  kTopDarjeelingNoIbexPinmuxInselMio6 = 8, /**< MIO Pad 6 */
  kTopDarjeelingNoIbexPinmuxInselMio7 = 9, /**< MIO Pad 7 */
  kTopDarjeelingNoIbexPinmuxInselMio8 = 10, /**< MIO Pad 8 */
  kTopDarjeelingNoIbexPinmuxInselMio9 = 11, /**< MIO Pad 9 */
  kTopDarjeelingNoIbexPinmuxInselMio10 = 12, /**< MIO Pad 10 */
  kTopDarjeelingNoIbexPinmuxInselMio11 = 13, /**< MIO Pad 11 */
  kTopDarjeelingNoIbexPinmuxInselLast = 13, /**< \internal Last valid insel value */
} top_darjeeling_no_ibex_pinmux_insel_t;

/**
 * Pinmux MIO Output.
 */
typedef enum top_darjeeling_no_ibex_pinmux_mio_out {
  kTopDarjeelingNoIbexPinmuxMioOutMio0 = 0, /**< MIO Pad 0 */
  kTopDarjeelingNoIbexPinmuxMioOutMio1 = 1, /**< MIO Pad 1 */
  kTopDarjeelingNoIbexPinmuxMioOutMio2 = 2, /**< MIO Pad 2 */
  kTopDarjeelingNoIbexPinmuxMioOutMio3 = 3, /**< MIO Pad 3 */
  kTopDarjeelingNoIbexPinmuxMioOutMio4 = 4, /**< MIO Pad 4 */
  kTopDarjeelingNoIbexPinmuxMioOutMio5 = 5, /**< MIO Pad 5 */
  kTopDarjeelingNoIbexPinmuxMioOutMio6 = 6, /**< MIO Pad 6 */
  kTopDarjeelingNoIbexPinmuxMioOutMio7 = 7, /**< MIO Pad 7 */
  kTopDarjeelingNoIbexPinmuxMioOutMio8 = 8, /**< MIO Pad 8 */
  kTopDarjeelingNoIbexPinmuxMioOutMio9 = 9, /**< MIO Pad 9 */
  kTopDarjeelingNoIbexPinmuxMioOutMio10 = 10, /**< MIO Pad 10 */
  kTopDarjeelingNoIbexPinmuxMioOutMio11 = 11, /**< MIO Pad 11 */
  kTopDarjeelingNoIbexPinmuxMioOutLast = 11, /**< \internal Last valid mio output */
} top_darjeeling_no_ibex_pinmux_mio_out_t;

/**
 * Pinmux Peripheral Output Selector.
 */
typedef enum top_darjeeling_no_ibex_pinmux_outsel {
  kTopDarjeelingNoIbexPinmuxOutselConstantZero = 0, /**< Tie constantly to zero */
  kTopDarjeelingNoIbexPinmuxOutselConstantOne = 1, /**< Tie constantly to one */
  kTopDarjeelingNoIbexPinmuxOutselConstantHighZ = 2, /**< Tie constantly to high-Z */
  kTopDarjeelingNoIbexPinmuxOutselSocProxySocGpo12 = 3, /**< Peripheral Output 0 */
  kTopDarjeelingNoIbexPinmuxOutselSocProxySocGpo13 = 4, /**< Peripheral Output 1 */
  kTopDarjeelingNoIbexPinmuxOutselSocProxySocGpo14 = 5, /**< Peripheral Output 2 */
  kTopDarjeelingNoIbexPinmuxOutselSocProxySocGpo15 = 6, /**< Peripheral Output 3 */
  kTopDarjeelingNoIbexPinmuxOutselOtpMacroTest0 = 7, /**< Peripheral Output 4 */
  kTopDarjeelingNoIbexPinmuxOutselLast = 7, /**< \internal Last valid outsel value */
} top_darjeeling_no_ibex_pinmux_outsel_t;

/**
 * Dedicated Pad Selects
 */
typedef enum top_darjeeling_no_ibex_direct_pads {
  kTopDarjeelingNoIbexDirectPadsSpiHost0Sd0 = 0, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiHost0Sd1 = 1, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiHost0Sd2 = 2, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiHost0Sd3 = 3, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiDeviceSd0 = 4, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiDeviceSd1 = 5, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiDeviceSd2 = 6, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiDeviceSd3 = 7, /**<  */
  kTopDarjeelingNoIbexDirectPadsI2c0Scl = 8, /**<  */
  kTopDarjeelingNoIbexDirectPadsI2c0Sda = 9, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio0 = 10, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio1 = 11, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio2 = 12, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio3 = 13, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio4 = 14, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio5 = 15, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio6 = 16, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio7 = 17, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio8 = 18, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio9 = 19, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio10 = 20, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio11 = 21, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio12 = 22, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio13 = 23, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio14 = 24, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio15 = 25, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio16 = 26, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio17 = 27, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio18 = 28, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio19 = 29, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio20 = 30, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio21 = 31, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio22 = 32, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio23 = 33, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio24 = 34, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio25 = 35, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio26 = 36, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio27 = 37, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio28 = 38, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio29 = 39, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio30 = 40, /**<  */
  kTopDarjeelingNoIbexDirectPadsGpioGpio31 = 41, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiDeviceSck = 42, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiDeviceCsb = 43, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiDeviceTpmCsb = 44, /**<  */
  kTopDarjeelingNoIbexDirectPadsUart0Rx = 45, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi0 = 46, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi1 = 47, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi2 = 48, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi3 = 49, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi4 = 50, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi5 = 51, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi6 = 52, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi7 = 53, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi8 = 54, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi9 = 55, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi10 = 56, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpi11 = 57, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiHost0Sck = 58, /**<  */
  kTopDarjeelingNoIbexDirectPadsSpiHost0Csb = 59, /**<  */
  kTopDarjeelingNoIbexDirectPadsUart0Tx = 60, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo0 = 61, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo1 = 62, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo2 = 63, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo3 = 64, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo4 = 65, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo5 = 66, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo6 = 67, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo7 = 68, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo8 = 69, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo9 = 70, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo10 = 71, /**<  */
  kTopDarjeelingNoIbexDirectPadsSocProxySocGpo11 = 72, /**<  */
  kTopDarjeelingNoIbexDirectPadsLast = 72, /**< \internal Last valid direct pad */
} top_darjeeling_no_ibex_direct_pads_t;

/**
 * Muxed Pad Selects
 */
typedef enum top_darjeeling_no_ibex_muxed_pads {
  kTopDarjeelingNoIbexMuxedPadsMio0 = 0, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio1 = 1, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio2 = 2, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio3 = 3, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio4 = 4, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio5 = 5, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio6 = 6, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio7 = 7, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio8 = 8, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio9 = 9, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio10 = 10, /**<  */
  kTopDarjeelingNoIbexMuxedPadsMio11 = 11, /**<  */
  kTopDarjeelingNoIbexMuxedPadsLast = 11, /**< \internal Last valid muxed pad */
} top_darjeeling_no_ibex_muxed_pads_t;

/**
 * Power Manager Wakeup Signals
 */
typedef enum top_darjeeling_no_ibex_power_manager_wake_ups {
  kTopDarjeelingNoIbexPowerManagerWakeUpsPinmuxAonPinWkupReq = 0, /**<  */
  kTopDarjeelingNoIbexPowerManagerWakeUpsAonTimerAonWkupReq = 1, /**<  */
  kTopDarjeelingNoIbexPowerManagerWakeUpsSocProxyWkupInternalReq = 2, /**<  */
  kTopDarjeelingNoIbexPowerManagerWakeUpsSocProxyWkupExternalReq = 3, /**<  */
  kTopDarjeelingNoIbexPowerManagerWakeUpsLast = 3, /**< \internal Last valid pwrmgr wakeup signal */
} top_darjeeling_no_ibex_power_manager_wake_ups_t;

/**
 * Reset Manager Software Controlled Resets
 */
typedef enum top_darjeeling_no_ibex_reset_manager_sw_resets {
  kTopDarjeelingNoIbexResetManagerSwResetsSpiDevice = 0, /**<  */
  kTopDarjeelingNoIbexResetManagerSwResetsSpiHost0 = 1, /**<  */
  kTopDarjeelingNoIbexResetManagerSwResetsI2c0 = 2, /**<  */
  kTopDarjeelingNoIbexResetManagerSwResetsLast = 2, /**< \internal Last valid rstmgr software reset request */
} top_darjeeling_no_ibex_reset_manager_sw_resets_t;

/**
 * Power Manager Reset Request Signals
 */
typedef enum top_darjeeling_no_ibex_power_manager_reset_requests {
  kTopDarjeelingNoIbexPowerManagerResetRequestsAonTimerAonAonTimerRstReq = 0, /**<  */
  kTopDarjeelingNoIbexPowerManagerResetRequestsSocProxyRstReqExternal = 1, /**<  */
  kTopDarjeelingNoIbexPowerManagerResetRequestsLast = 1, /**< \internal Last valid pwrmgr reset_request signal */
} top_darjeeling_no_ibex_power_manager_reset_requests_t;

/**
 * Clock Manager Software-Controlled ("Gated") Clocks.
 *
 * The Software has full control over these clocks.
 */
typedef enum top_darjeeling_no_ibex_gateable_clocks {
  kTopDarjeelingNoIbexGateableClocksIoDiv4Peri = 0, /**< Clock clk_io_div4_peri in group peri */
  kTopDarjeelingNoIbexGateableClocksIoDiv2Peri = 1, /**< Clock clk_io_div2_peri in group peri */
  kTopDarjeelingNoIbexGateableClocksLast = 1, /**< \internal Last Valid Gateable Clock */
} top_darjeeling_no_ibex_gateable_clocks_t;

/**
 * Clock Manager Software-Hinted Clocks.
 *
 * The Software has partial control over these clocks. It can ask them to stop,
 * but the clock manager is in control of whether the clock actually is stopped.
 */
typedef enum top_darjeeling_no_ibex_hintable_clocks {
  kTopDarjeelingNoIbexHintableClocksMainAes = 0, /**< Clock clk_main_aes in group trans */
  kTopDarjeelingNoIbexHintableClocksMainHmac = 1, /**< Clock clk_main_hmac in group trans */
  kTopDarjeelingNoIbexHintableClocksMainKmac = 2, /**< Clock clk_main_kmac in group trans */
  kTopDarjeelingNoIbexHintableClocksMainOtbn = 3, /**< Clock clk_main_otbn in group trans */
  kTopDarjeelingNoIbexHintableClocksLast = 3, /**< \internal Last Valid Hintable Clock */
} top_darjeeling_no_ibex_hintable_clocks_t;

/**
 * MMIO Region
 *
 * MMIO region excludes any memory that is separate from the module
 * configuration space, i.e. ROM, main SRAM, and mbx SRAM are excluded but
 * retention SRAM or spi_device are included.
 */
#define TOP_DARJEELING_NO_IBEX_MMIO_BASE_ADDR 0x21100000u
#define TOP_DARJEELING_NO_IBEX_MMIO_SIZE_BYTES 0xF501000u

// Header Extern Guard
#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // OPENTITAN_HW_TOP_DARJEELING_NO_IBEX_SW_AUTOGEN_TOP_DARJEELING_NO_IBEX_H_
