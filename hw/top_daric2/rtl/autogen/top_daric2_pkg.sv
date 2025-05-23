// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// ------------------- W A R N I N G: A U T O - G E N E R A T E D   C O D E !! -------------------//
// PLEASE DO NOT HAND-EDIT THIS FILE. IT HAS BEEN AUTO-GENERATED WITH THE FOLLOWING COMMAND:
//
// util/topgen.py -t hw/top_daric2/data/top_daric2.hjson \
//                -o hw/top_daric2/ \
//                --rnd_cnst_seed \
//                101098626978340823138505263425558841856553191321056561504387354855667932335145

package top_daric2_pkg;
  /**
   * Peripheral base address for uart0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_UART0_BASE_ADDR = 32'h30010000;

  /**
   * Peripheral size in bytes for uart0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_UART0_SIZE_BYTES = 32'h40;

  /**
   * Peripheral base address for gpio in top daric2.
   */
  parameter int unsigned TOP_DARIC2_GPIO_BASE_ADDR = 32'h30000000;

  /**
   * Peripheral size in bytes for gpio in top daric2.
   */
  parameter int unsigned TOP_DARIC2_GPIO_SIZE_BYTES = 32'h100;

  /**
   * Peripheral base address for rv_timer in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RV_TIMER_BASE_ADDR = 32'h30100000;

  /**
   * Peripheral size in bytes for rv_timer in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RV_TIMER_SIZE_BYTES = 32'h200;

  /**
   * Peripheral base address for core device on otp_ctrl in top daric2.
   */
  parameter int unsigned TOP_DARIC2_OTP_CTRL_CORE_BASE_ADDR = 32'h30130000;

  /**
   * Peripheral size in bytes for core device on otp_ctrl in top daric2.
   */
  parameter int unsigned TOP_DARIC2_OTP_CTRL_CORE_SIZE_BYTES = 32'h8000;

  /**
   * Peripheral base address for otp_macro in top daric2.
   */
  parameter int unsigned TOP_DARIC2_OTP_MACRO_BASE_ADDR = 32'h30140000;

  /**
   * Peripheral size in bytes for otp_macro in top daric2.
   */
  parameter int unsigned TOP_DARIC2_OTP_MACRO_SIZE_BYTES = 32'h20;

  /**
   * Peripheral base address for regs device on lc_ctrl in top daric2.
   */
  parameter int unsigned TOP_DARIC2_LC_CTRL_REGS_BASE_ADDR = 32'h30150000;

  /**
   * Peripheral size in bytes for regs device on lc_ctrl in top daric2.
   */
  parameter int unsigned TOP_DARIC2_LC_CTRL_REGS_SIZE_BYTES = 32'h100;

  /**
   * Peripheral base address for alert_handler in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ALERT_HANDLER_BASE_ADDR = 32'h30160000;

  /**
   * Peripheral size in bytes for alert_handler in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ALERT_HANDLER_SIZE_BYTES = 32'h800;

  /**
   * Peripheral base address for pwrmgr_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_PWRMGR_AON_BASE_ADDR = 32'h30400000;

  /**
   * Peripheral size in bytes for pwrmgr_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_PWRMGR_AON_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for rstmgr_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RSTMGR_AON_BASE_ADDR = 32'h30410000;

  /**
   * Peripheral size in bytes for rstmgr_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RSTMGR_AON_SIZE_BYTES = 32'h40;

  /**
   * Peripheral base address for clkmgr_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_CLKMGR_AON_BASE_ADDR = 32'h30420000;

  /**
   * Peripheral size in bytes for clkmgr_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_CLKMGR_AON_SIZE_BYTES = 32'h40;

  /**
   * Peripheral base address for pinmux_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_PINMUX_AON_BASE_ADDR = 32'h30460000;

  /**
   * Peripheral size in bytes for pinmux_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_PINMUX_AON_SIZE_BYTES = 32'h800;

  /**
   * Peripheral base address for aon_timer_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_AON_TIMER_AON_BASE_ADDR = 32'h30470000;

  /**
   * Peripheral size in bytes for aon_timer_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_AON_TIMER_AON_SIZE_BYTES = 32'h40;

  /**
   * Peripheral base address for core device on soc_proxy in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SOC_PROXY_CORE_BASE_ADDR = 32'h22030000;

  /**
   * Peripheral size in bytes for core device on soc_proxy in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SOC_PROXY_CORE_SIZE_BYTES = 32'h10;

  /**
   * Peripheral base address for ctn device on soc_proxy in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SOC_PROXY_CTN_BASE_ADDR = 32'h40000000;

  /**
   * Peripheral size in bytes for ctn device on soc_proxy in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SOC_PROXY_CTN_SIZE_BYTES = 32'h40000000;

  /**
   * Peripheral base address for regs device on sram_ctrl_ret_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_RET_AON_REGS_BASE_ADDR = 32'h30500000;

  /**
   * Peripheral size in bytes for regs device on sram_ctrl_ret_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_RET_AON_REGS_SIZE_BYTES = 32'h40;

  /**
   * Peripheral base address for ram device on sram_ctrl_ret_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_RET_AON_RAM_BASE_ADDR = 32'h30600000;

  /**
   * Peripheral size in bytes for ram device on sram_ctrl_ret_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_RET_AON_RAM_SIZE_BYTES = 32'h1000;

  /**
   * Peripheral base address for regs device on rv_dm in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RV_DM_REGS_BASE_ADDR = 32'h21200000;

  /**
   * Peripheral size in bytes for regs device on rv_dm in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RV_DM_REGS_SIZE_BYTES = 32'h10;

  /**
   * Peripheral base address for mem device on rv_dm in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RV_DM_MEM_BASE_ADDR = 32'h40000;

  /**
   * Peripheral size in bytes for mem device on rv_dm in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RV_DM_MEM_SIZE_BYTES = 32'h1000;

  /**
   * Peripheral base address for rv_plic in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RV_PLIC_BASE_ADDR = 32'h28000000;

  /**
   * Peripheral size in bytes for rv_plic in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RV_PLIC_SIZE_BYTES = 32'h8000000;

  /**
   * Peripheral base address for aes in top daric2.
   */
  parameter int unsigned TOP_DARIC2_AES_BASE_ADDR = 32'h21100000;

  /**
   * Peripheral size in bytes for aes in top daric2.
   */
  parameter int unsigned TOP_DARIC2_AES_SIZE_BYTES = 32'h100;

  /**
   * Peripheral base address for hmac in top daric2.
   */
  parameter int unsigned TOP_DARIC2_HMAC_BASE_ADDR = 32'h21110000;

  /**
   * Peripheral size in bytes for hmac in top daric2.
   */
  parameter int unsigned TOP_DARIC2_HMAC_SIZE_BYTES = 32'h2000;

  /**
   * Peripheral base address for kmac in top daric2.
   */
  parameter int unsigned TOP_DARIC2_KMAC_BASE_ADDR = 32'h21120000;

  /**
   * Peripheral size in bytes for kmac in top daric2.
   */
  parameter int unsigned TOP_DARIC2_KMAC_SIZE_BYTES = 32'h1000;

  /**
   * Peripheral base address for otbn in top daric2.
   */
  parameter int unsigned TOP_DARIC2_OTBN_BASE_ADDR = 32'h21130000;

  /**
   * Peripheral size in bytes for otbn in top daric2.
   */
  parameter int unsigned TOP_DARIC2_OTBN_SIZE_BYTES = 32'h10000;

  /**
   * Peripheral base address for keymgr_dpe in top daric2.
   */
  parameter int unsigned TOP_DARIC2_KEYMGR_DPE_BASE_ADDR = 32'h21140000;

  /**
   * Peripheral size in bytes for keymgr_dpe in top daric2.
   */
  parameter int unsigned TOP_DARIC2_KEYMGR_DPE_SIZE_BYTES = 32'h100;

  /**
   * Peripheral base address for csrng in top daric2.
   */
  parameter int unsigned TOP_DARIC2_CSRNG_BASE_ADDR = 32'h21150000;

  /**
   * Peripheral size in bytes for csrng in top daric2.
   */
  parameter int unsigned TOP_DARIC2_CSRNG_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for edn0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_EDN0_BASE_ADDR = 32'h21170000;

  /**
   * Peripheral size in bytes for edn0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_EDN0_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for edn1 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_EDN1_BASE_ADDR = 32'h21180000;

  /**
   * Peripheral size in bytes for edn1 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_EDN1_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for regs device on sram_ctrl_main in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_MAIN_REGS_BASE_ADDR = 32'h211C0000;

  /**
   * Peripheral size in bytes for regs device on sram_ctrl_main in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_MAIN_REGS_SIZE_BYTES = 32'h40;

  /**
   * Peripheral base address for ram device on sram_ctrl_main in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_MAIN_RAM_BASE_ADDR = 32'h10000000;

  /**
   * Peripheral size in bytes for ram device on sram_ctrl_main in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_MAIN_RAM_SIZE_BYTES = 32'h10000;

  /**
   * Peripheral base address for regs device on sram_ctrl_mbox in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_MBOX_REGS_BASE_ADDR = 32'h211D0000;

  /**
   * Peripheral size in bytes for regs device on sram_ctrl_mbox in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_MBOX_REGS_SIZE_BYTES = 32'h40;

  /**
   * Peripheral base address for ram device on sram_ctrl_mbox in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_MBOX_RAM_BASE_ADDR = 32'h11000000;

  /**
   * Peripheral size in bytes for ram device on sram_ctrl_mbox in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SRAM_CTRL_MBOX_RAM_SIZE_BYTES = 32'h1000;

  /**
   * Peripheral base address for regs device on rom_ctrl0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM_CTRL0_REGS_BASE_ADDR = 32'h211E0000;

  /**
   * Peripheral size in bytes for regs device on rom_ctrl0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM_CTRL0_REGS_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for rom device on rom_ctrl0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM_CTRL0_ROM_BASE_ADDR = 32'h8000;

  /**
   * Peripheral size in bytes for rom device on rom_ctrl0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM_CTRL0_ROM_SIZE_BYTES = 32'h8000;

  /**
   * Peripheral base address for regs device on rom_ctrl1 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM_CTRL1_REGS_BASE_ADDR = 32'h211E1000;

  /**
   * Peripheral size in bytes for regs device on rom_ctrl1 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM_CTRL1_REGS_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for rom device on rom_ctrl1 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM_CTRL1_ROM_BASE_ADDR = 32'h20000;

  /**
   * Peripheral size in bytes for rom device on rom_ctrl1 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM_CTRL1_ROM_SIZE_BYTES = 32'h10000;

  /**
   * Peripheral base address for dma in top daric2.
   */
  parameter int unsigned TOP_DARIC2_DMA_BASE_ADDR = 32'h22010000;

  /**
   * Peripheral size in bytes for dma in top daric2.
   */
  parameter int unsigned TOP_DARIC2_DMA_SIZE_BYTES = 32'h200;

  /**
   * Peripheral base address for core device on mbx0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX0_CORE_BASE_ADDR = 32'h22000000;

  /**
   * Peripheral size in bytes for core device on mbx0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX0_CORE_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for core device on mbx1 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX1_CORE_BASE_ADDR = 32'h22000100;

  /**
   * Peripheral size in bytes for core device on mbx1 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX1_CORE_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for core device on mbx2 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX2_CORE_BASE_ADDR = 32'h22000200;

  /**
   * Peripheral size in bytes for core device on mbx2 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX2_CORE_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for core device on mbx3 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX3_CORE_BASE_ADDR = 32'h22000300;

  /**
   * Peripheral size in bytes for core device on mbx3 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX3_CORE_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for core device on mbx4 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX4_CORE_BASE_ADDR = 32'h22000400;

  /**
   * Peripheral size in bytes for core device on mbx4 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX4_CORE_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for core device on mbx5 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX5_CORE_BASE_ADDR = 32'h22000500;

  /**
   * Peripheral size in bytes for core device on mbx5 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX5_CORE_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for core device on mbx6 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX6_CORE_BASE_ADDR = 32'h22000600;

  /**
   * Peripheral size in bytes for core device on mbx6 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX6_CORE_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for core device on mbx_jtag in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX_JTAG_CORE_BASE_ADDR = 32'h22000800;

  /**
   * Peripheral size in bytes for core device on mbx_jtag in top daric2.
   */
  parameter int unsigned TOP_DARIC2_MBX_JTAG_CORE_SIZE_BYTES = 32'h80;

  /**
   * Peripheral base address for core device on soc_dbg_ctrl in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SOC_DBG_CTRL_CORE_BASE_ADDR = 32'h30170000;

  /**
   * Peripheral size in bytes for core device on soc_dbg_ctrl in top daric2.
   */
  parameter int unsigned TOP_DARIC2_SOC_DBG_CTRL_CORE_SIZE_BYTES = 32'h20;

  /**
   * Peripheral base address for cfg device on rv_core_ibex in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RV_CORE_IBEX_CFG_BASE_ADDR = 32'h211F0000;

  /**
   * Peripheral size in bytes for cfg device on rv_core_ibex in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RV_CORE_IBEX_CFG_SIZE_BYTES = 32'h800;

  /**
   * Memory base address for ctn in top daric2.
   */
  parameter int unsigned TOP_DARIC2_CTN_BASE_ADDR = 32'h40000000;

  /**
   * Memory size for ctn in top daric2.
   */
  parameter int unsigned TOP_DARIC2_CTN_SIZE_BYTES = 32'h40000000;

  /**
  * Memory base address for ram_ctn in top daric2.
  */
  parameter int unsigned TOP_DARIC2_RAM_CTN_BASE_ADDR = 32'h41000000;

  /**
  * Memory size for ram_ctn in top daric2.
  */
  parameter int unsigned TOP_DARIC2_RAM_CTN_SIZE_BYTES = 32'h100000;

  /**
   * Memory base address for ram_ret_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RAM_RET_AON_BASE_ADDR = 32'h30600000;

  /**
   * Memory size for ram_ret_aon in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RAM_RET_AON_SIZE_BYTES = 32'h1000;

  /**
   * Memory base address for ram_main in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RAM_MAIN_BASE_ADDR = 32'h10000000;

  /**
   * Memory size for ram_main in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RAM_MAIN_SIZE_BYTES = 32'h10000;

  /**
   * Memory base address for ram_mbox in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RAM_MBOX_BASE_ADDR = 32'h11000000;

  /**
   * Memory size for ram_mbox in top daric2.
   */
  parameter int unsigned TOP_DARIC2_RAM_MBOX_SIZE_BYTES = 32'h1000;

  /**
   * Memory base address for rom0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM0_BASE_ADDR = 32'h8000;

  /**
   * Memory size for rom0 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM0_SIZE_BYTES = 32'h8000;

  /**
   * Memory base address for rom1 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM1_BASE_ADDR = 32'h20000;

  /**
   * Memory size for rom1 in top daric2.
   */
  parameter int unsigned TOP_DARIC2_ROM1_SIZE_BYTES = 32'h10000;


  // Enumeration of alert modules
  typedef enum int unsigned {
    TopDaric2AlertPeripheralUart0 = 0,
    TopDaric2AlertPeripheralGpio = 1,
    TopDaric2AlertPeripheralRvTimer = 2,
    TopDaric2AlertPeripheralOtpCtrl = 3,
    TopDaric2AlertPeripheralLcCtrl = 4,
    TopDaric2AlertPeripheralPwrmgrAon = 5,
    TopDaric2AlertPeripheralRstmgrAon = 6,
    TopDaric2AlertPeripheralClkmgrAon = 7,
    TopDaric2AlertPeripheralPinmuxAon = 8,
    TopDaric2AlertPeripheralAonTimerAon = 9,
    TopDaric2AlertPeripheralSocProxy = 10,
    TopDaric2AlertPeripheralSramCtrlRetAon = 11,
    TopDaric2AlertPeripheralRvDm = 12,
    TopDaric2AlertPeripheralRvPlic = 13,
    TopDaric2AlertPeripheralAes = 14,
    TopDaric2AlertPeripheralHmac = 15,
    TopDaric2AlertPeripheralKmac = 16,
    TopDaric2AlertPeripheralOtbn = 17,
    TopDaric2AlertPeripheralKeymgrDpe = 18,
    TopDaric2AlertPeripheralCsrng = 19,
    TopDaric2AlertPeripheralEdn0 = 20,
    TopDaric2AlertPeripheralEdn1 = 21,
    TopDaric2AlertPeripheralSramCtrlMain = 22,
    TopDaric2AlertPeripheralSramCtrlMbox = 23,
    TopDaric2AlertPeripheralRomCtrl0 = 24,
    TopDaric2AlertPeripheralRomCtrl1 = 25,
    TopDaric2AlertPeripheralDma = 26,
    TopDaric2AlertPeripheralMbx0 = 27,
    TopDaric2AlertPeripheralMbx1 = 28,
    TopDaric2AlertPeripheralMbx2 = 29,
    TopDaric2AlertPeripheralMbx3 = 30,
    TopDaric2AlertPeripheralMbx4 = 31,
    TopDaric2AlertPeripheralMbx5 = 32,
    TopDaric2AlertPeripheralMbx6 = 33,
    TopDaric2AlertPeripheralMbxJtag = 34,
    TopDaric2AlertPeripheralSocDbgCtrl = 35,
    TopDaric2AlertPeripheralRaclCtrl = 36,
    TopDaric2AlertPeripheralAcRangeCheck = 37,
    TopDaric2AlertPeripheralRvCoreIbex = 38,
    TopDaric2AlertPeripheralCount
  } alert_peripheral_e;

  // Enumeration of alerts
  typedef enum int unsigned {
    TopDaric2AlertIdUart0FatalFault = 0,
    TopDaric2AlertIdGpioFatalFault = 1,
    TopDaric2AlertIdRvTimerFatalFault = 2,
    TopDaric2AlertIdOtpCtrlFatalMacroError = 3,
    TopDaric2AlertIdOtpCtrlFatalCheckError = 4,
    TopDaric2AlertIdOtpCtrlFatalBusIntegError = 5,
    TopDaric2AlertIdOtpCtrlFatalPrimOtpAlert = 6,
    TopDaric2AlertIdOtpCtrlRecovPrimOtpAlert = 7,
    TopDaric2AlertIdLcCtrlFatalProgError = 8,
    TopDaric2AlertIdLcCtrlFatalStateError = 9,
    TopDaric2AlertIdLcCtrlFatalBusIntegError = 10,
    TopDaric2AlertIdPwrmgrAonFatalFault = 11,
    TopDaric2AlertIdRstmgrAonFatalFault = 12,
    TopDaric2AlertIdRstmgrAonFatalCnstyFault = 13,
    TopDaric2AlertIdClkmgrAonRecovFault = 14,
    TopDaric2AlertIdClkmgrAonFatalFault = 15,
    TopDaric2AlertIdPinmuxAonFatalFault = 16,
    TopDaric2AlertIdAonTimerAonFatalFault = 17,
    TopDaric2AlertIdSocProxyFatalAlertIntg = 18,
    TopDaric2AlertIdSocProxyFatalAlertExternal0 = 19,
    TopDaric2AlertIdSocProxyFatalAlertExternal1 = 20,
    TopDaric2AlertIdSocProxyFatalAlertExternal2 = 21,
    TopDaric2AlertIdSocProxyFatalAlertExternal3 = 22,
    TopDaric2AlertIdSocProxyFatalAlertExternal4 = 23,
    TopDaric2AlertIdSocProxyFatalAlertExternal5 = 24,
    TopDaric2AlertIdSocProxyFatalAlertExternal6 = 25,
    TopDaric2AlertIdSocProxyFatalAlertExternal7 = 26,
    TopDaric2AlertIdSocProxyFatalAlertExternal8 = 27,
    TopDaric2AlertIdSocProxyFatalAlertExternal9 = 28,
    TopDaric2AlertIdSocProxyFatalAlertExternal10 = 29,
    TopDaric2AlertIdSocProxyFatalAlertExternal11 = 30,
    TopDaric2AlertIdSocProxyFatalAlertExternal12 = 31,
    TopDaric2AlertIdSocProxyFatalAlertExternal13 = 32,
    TopDaric2AlertIdSocProxyFatalAlertExternal14 = 33,
    TopDaric2AlertIdSocProxyFatalAlertExternal15 = 34,
    TopDaric2AlertIdSocProxyFatalAlertExternal16 = 35,
    TopDaric2AlertIdSocProxyFatalAlertExternal17 = 36,
    TopDaric2AlertIdSocProxyFatalAlertExternal18 = 37,
    TopDaric2AlertIdSocProxyFatalAlertExternal19 = 38,
    TopDaric2AlertIdSocProxyFatalAlertExternal20 = 39,
    TopDaric2AlertIdSocProxyFatalAlertExternal21 = 40,
    TopDaric2AlertIdSocProxyFatalAlertExternal22 = 41,
    TopDaric2AlertIdSocProxyFatalAlertExternal23 = 42,
    TopDaric2AlertIdSocProxyRecovAlertExternal0 = 43,
    TopDaric2AlertIdSocProxyRecovAlertExternal1 = 44,
    TopDaric2AlertIdSocProxyRecovAlertExternal2 = 45,
    TopDaric2AlertIdSocProxyRecovAlertExternal3 = 46,
    TopDaric2AlertIdSramCtrlRetAonFatalError = 47,
    TopDaric2AlertIdRvDmFatalFault = 48,
    TopDaric2AlertIdRvPlicFatalFault = 49,
    TopDaric2AlertIdAesRecovCtrlUpdateErr = 50,
    TopDaric2AlertIdAesFatalFault = 51,
    TopDaric2AlertIdHmacFatalFault = 52,
    TopDaric2AlertIdKmacRecovOperationErr = 53,
    TopDaric2AlertIdKmacFatalFaultErr = 54,
    TopDaric2AlertIdOtbnFatal = 55,
    TopDaric2AlertIdOtbnRecov = 56,
    TopDaric2AlertIdKeymgrDpeRecovOperationErr = 57,
    TopDaric2AlertIdKeymgrDpeFatalFaultErr = 58,
    TopDaric2AlertIdCsrngRecovAlert = 59,
    TopDaric2AlertIdCsrngFatalAlert = 60,
    TopDaric2AlertIdEdn0RecovAlert = 61,
    TopDaric2AlertIdEdn0FatalAlert = 62,
    TopDaric2AlertIdEdn1RecovAlert = 63,
    TopDaric2AlertIdEdn1FatalAlert = 64,
    TopDaric2AlertIdSramCtrlMainFatalError = 65,
    TopDaric2AlertIdSramCtrlMboxFatalError = 66,
    TopDaric2AlertIdRomCtrl0Fatal = 67,
    TopDaric2AlertIdRomCtrl1Fatal = 68,
    TopDaric2AlertIdDmaFatalFault = 69,
    TopDaric2AlertIdMbx0FatalFault = 70,
    TopDaric2AlertIdMbx0RecovFault = 71,
    TopDaric2AlertIdMbx1FatalFault = 72,
    TopDaric2AlertIdMbx1RecovFault = 73,
    TopDaric2AlertIdMbx2FatalFault = 74,
    TopDaric2AlertIdMbx2RecovFault = 75,
    TopDaric2AlertIdMbx3FatalFault = 76,
    TopDaric2AlertIdMbx3RecovFault = 77,
    TopDaric2AlertIdMbx4FatalFault = 78,
    TopDaric2AlertIdMbx4RecovFault = 79,
    TopDaric2AlertIdMbx5FatalFault = 80,
    TopDaric2AlertIdMbx5RecovFault = 81,
    TopDaric2AlertIdMbx6FatalFault = 82,
    TopDaric2AlertIdMbx6RecovFault = 83,
    TopDaric2AlertIdMbxJtagFatalFault = 84,
    TopDaric2AlertIdMbxJtagRecovFault = 85,
    TopDaric2AlertIdSocDbgCtrlFatalFault = 86,
    TopDaric2AlertIdSocDbgCtrlRecovCtrlUpdateErr = 87,
    TopDaric2AlertIdRaclCtrlFatalFault = 88,
    TopDaric2AlertIdRaclCtrlRecovCtrlUpdateErr = 89,
    TopDaric2AlertIdAcRangeCheckRecovCtrlUpdateErr = 90,
    TopDaric2AlertIdAcRangeCheckFatalFault = 91,
    TopDaric2AlertIdRvCoreIbexFatalSwErr = 92,
    TopDaric2AlertIdRvCoreIbexRecovSwErr = 93,
    TopDaric2AlertIdRvCoreIbexFatalHwErr = 94,
    TopDaric2AlertIdRvCoreIbexRecovHwErr = 95,
    TopDaric2AlertIdCount
  } alert_id_e;

  // Enumeration of IO power domains.
  // Only used in ASIC target.
  typedef enum logic [0:0] {
    IoBankVio = 0,
    IoBankCount = 1
  } pwr_dom_e;

  // Enumeration for MIO signals on the top-level.
  typedef enum int unsigned {
    MioInSocProxySocGpi12 = 0,
    MioInSocProxySocGpi13 = 1,
    MioInSocProxySocGpi14 = 2,
    MioInSocProxySocGpi15 = 3,
    MioInCount = 4
  } mio_in_e;

  typedef enum {
    MioOutSocProxySocGpo12 = 0,
    MioOutSocProxySocGpo13 = 1,
    MioOutSocProxySocGpo14 = 2,
    MioOutSocProxySocGpo15 = 3,
    MioOutOtpMacroTest0 = 4,
    MioOutCount = 5
  } mio_out_e;

  // Enumeration for DIO signals, used on both the top and chip-levels.
  typedef enum int unsigned {
    DioGpioGpio0 = 0,
    DioGpioGpio1 = 1,
    DioGpioGpio2 = 2,
    DioGpioGpio3 = 3,
    DioGpioGpio4 = 4,
    DioGpioGpio5 = 5,
    DioGpioGpio6 = 6,
    DioGpioGpio7 = 7,
    DioGpioGpio8 = 8,
    DioGpioGpio9 = 9,
    DioGpioGpio10 = 10,
    DioGpioGpio11 = 11,
    DioGpioGpio12 = 12,
    DioGpioGpio13 = 13,
    DioGpioGpio14 = 14,
    DioGpioGpio15 = 15,
    DioGpioGpio16 = 16,
    DioGpioGpio17 = 17,
    DioGpioGpio18 = 18,
    DioGpioGpio19 = 19,
    DioGpioGpio20 = 20,
    DioGpioGpio21 = 21,
    DioGpioGpio22 = 22,
    DioGpioGpio23 = 23,
    DioGpioGpio24 = 24,
    DioGpioGpio25 = 25,
    DioGpioGpio26 = 26,
    DioGpioGpio27 = 27,
    DioGpioGpio28 = 28,
    DioGpioGpio29 = 29,
    DioGpioGpio30 = 30,
    DioGpioGpio31 = 31,
    DioUart0Rx = 32,
    DioSocProxySocGpi0 = 33,
    DioSocProxySocGpi1 = 34,
    DioSocProxySocGpi2 = 35,
    DioSocProxySocGpi3 = 36,
    DioSocProxySocGpi4 = 37,
    DioSocProxySocGpi5 = 38,
    DioSocProxySocGpi6 = 39,
    DioSocProxySocGpi7 = 40,
    DioSocProxySocGpi8 = 41,
    DioSocProxySocGpi9 = 42,
    DioSocProxySocGpi10 = 43,
    DioSocProxySocGpi11 = 44,
    DioUart0Tx = 45,
    DioSocProxySocGpo0 = 46,
    DioSocProxySocGpo1 = 47,
    DioSocProxySocGpo2 = 48,
    DioSocProxySocGpo3 = 49,
    DioSocProxySocGpo4 = 50,
    DioSocProxySocGpo5 = 51,
    DioSocProxySocGpo6 = 52,
    DioSocProxySocGpo7 = 53,
    DioSocProxySocGpo8 = 54,
    DioSocProxySocGpo9 = 55,
    DioSocProxySocGpo10 = 56,
    DioSocProxySocGpo11 = 57,
    DioCount = 58
  } dio_e;

  // Enumeration for the types of pads.
  typedef enum {
    MioPad,
    DioPad
  } pad_type_e;

  // Raw MIO/DIO input array indices on chip-level.
  // TODO: Does not account for target specific stubbed/added pads.
  // Need to make a target-specific package for those.
  typedef enum int unsigned {
    MioPadMio0 = 0,
    MioPadMio1 = 1,
    MioPadMio2 = 2,
    MioPadMio3 = 3,
    MioPadMio4 = 4,
    MioPadMio5 = 5,
    MioPadMio6 = 6,
    MioPadMio7 = 7,
    MioPadMio8 = 8,
    MioPadMio9 = 9,
    MioPadMio10 = 10,
    MioPadMio11 = 11,
    MioPadCount
  } mio_pad_e;

  typedef enum int unsigned {
    DioPadPorN = 0,
    DioPadJtagTck = 1,
    DioPadJtagTms = 2,
    DioPadJtagTdi = 3,
    DioPadJtagTdo = 4,
    DioPadJtagTrstN = 5,
    DioPadOtpExtVolt = 6,
    DioPadUartRx = 7,
    DioPadUartTx = 8,
    DioPadGpio0 = 9,
    DioPadGpio1 = 10,
    DioPadGpio2 = 11,
    DioPadGpio3 = 12,
    DioPadGpio4 = 13,
    DioPadGpio5 = 14,
    DioPadGpio6 = 15,
    DioPadGpio7 = 16,
    DioPadGpio8 = 17,
    DioPadGpio9 = 18,
    DioPadGpio10 = 19,
    DioPadGpio11 = 20,
    DioPadGpio12 = 21,
    DioPadGpio13 = 22,
    DioPadGpio14 = 23,
    DioPadGpio15 = 24,
    DioPadGpio16 = 25,
    DioPadGpio17 = 26,
    DioPadGpio18 = 27,
    DioPadGpio19 = 28,
    DioPadGpio20 = 29,
    DioPadGpio21 = 30,
    DioPadGpio22 = 31,
    DioPadGpio23 = 32,
    DioPadGpio24 = 33,
    DioPadGpio25 = 34,
    DioPadGpio26 = 35,
    DioPadGpio27 = 36,
    DioPadGpio28 = 37,
    DioPadGpio29 = 38,
    DioPadGpio30 = 39,
    DioPadGpio31 = 40,
    DioPadSocGpi0 = 41,
    DioPadSocGpi1 = 42,
    DioPadSocGpi2 = 43,
    DioPadSocGpi3 = 44,
    DioPadSocGpi4 = 45,
    DioPadSocGpi5 = 46,
    DioPadSocGpi6 = 47,
    DioPadSocGpi7 = 48,
    DioPadSocGpi8 = 49,
    DioPadSocGpi9 = 50,
    DioPadSocGpi10 = 51,
    DioPadSocGpi11 = 52,
    DioPadSocGpo0 = 53,
    DioPadSocGpo1 = 54,
    DioPadSocGpo2 = 55,
    DioPadSocGpo3 = 56,
    DioPadSocGpo4 = 57,
    DioPadSocGpo5 = 58,
    DioPadSocGpo6 = 59,
    DioPadSocGpo7 = 60,
    DioPadSocGpo8 = 61,
    DioPadSocGpo9 = 62,
    DioPadSocGpo10 = 63,
    DioPadSocGpo11 = 64,
    DioPadCount
  } dio_pad_e;

  // List of peripheral instantiated in this chip.
  typedef enum {
    PeripheralAes,
    PeripheralAlertHandler,
    PeripheralAonTimerAon,
    PeripheralClkmgrAon,
    PeripheralCsrng,
    PeripheralDma,
    PeripheralEdn0,
    PeripheralEdn1,
    PeripheralGpio,
    PeripheralHmac,
    PeripheralKeymgrDpe,
    PeripheralKmac,
    PeripheralLcCtrl,
    PeripheralMbx0,
    PeripheralMbx1,
    PeripheralMbx2,
    PeripheralMbx3,
    PeripheralMbx4,
    PeripheralMbx5,
    PeripheralMbx6,
    PeripheralMbxJtag,
    PeripheralOtbn,
    PeripheralOtpCtrl,
    PeripheralOtpMacro,
    PeripheralPinmuxAon,
    PeripheralPwrmgrAon,
    PeripheralRomCtrl0,
    PeripheralRomCtrl1,
    PeripheralRstmgrAon,
    PeripheralRvCoreIbex,
    PeripheralRvDm,
    PeripheralRvPlic,
    PeripheralRvTimer,
    PeripheralSocDbgCtrl,
    PeripheralSocProxy,
    PeripheralSramCtrlMain,
    PeripheralSramCtrlMbox,
    PeripheralSramCtrlRetAon,
    PeripheralUart0,
    PeripheralCount
  } peripheral_e;

  // TODO: Enumeration for PLIC Interrupt source peripheral.
  // TODO: Enumeration for PLIC Interrupt Ids.

// MACROs for AST analog simulation support
`ifdef ANALOGSIM
  `define INOUT_AI input ast_pkg::awire_t
  `define INOUT_AO output ast_pkg::awire_t
`else
  `define INOUT_AI inout
  `define INOUT_AO inout
`endif

endpackage
