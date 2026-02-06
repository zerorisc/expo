// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "sw/device/lib/base/macros.h"
#include "sw/device/lib/base/multibits_asm.h"
#include "hw/top/ast_regs.h"
#include "hw/top/clkmgr_regs.h"
#include "hw/top/csrng_regs.h"
#include "hw/top/edn_regs.h"
#include "hw/top/sram_ctrl_regs.h"

#if defined(OPENTITAN_IS_ENGLISHBREAKFAST)
#include "hw/top/otp_ctrl_regs.h"
#include "hw/top/sensor_ctrl_regs.h"
#include "hw/top_englishbreakfast/sw/autogen/top_englishbreakfast_memory.h"
#define OTP_CTRL_CORE_BASE_ADDR             TOP_ENGLISHBREAKFAST_OTP_CTRL_CORE_BASE_ADDR
#define AST_BASE_ADDR                       TOP_ENGLISHBREAKFAST_AST_BASE_ADDR
#define CLKMGR_AON_BASE_ADDR                TOP_ENGLISHBREAKFAST_CLKMGR_AON_BASE_ADDR
#define SRAM_CTRL_MAIN_REGS_BASE_ADDR       TOP_ENGLISHBREAKFAST_SRAM_CTRL_MAIN_REGS_BASE_ADDR
#define ENTROPY_SRC_BASE_ADDR               TOP_ENGLISHBREAKFAST_ENTROPY_SRC_BASE_ADDR
#define CSRNG_BASE_ADDR                     TOP_ENGLISHBREAKFAST_CSRNG_BASE_ADDR
#define EDN0_BASE_ADDR                      TOP_ENGLISHBREAKFAST_EDN0_BASE_ADDR
#define SENSOR_CTRL_BASE_ADDR               TOP_ENGLISHBREAKFAST_SENSOR_CTRL_AON_BASE_ADDR

#elif defined(OPENTITAN_IS_EARLGREY)
#include "hw/top/otp_ctrl_regs.h"
#include "hw/top/sensor_ctrl_regs.h"
#include "hw/top_earlgrey/sw/autogen/top_earlgrey_memory.h"
#define OTP_CTRL_CORE_BASE_ADDR             TOP_EARLGREY_OTP_CTRL_CORE_BASE_ADDR
#define AST_BASE_ADDR                       TOP_EARLGREY_AST_BASE_ADDR
#define CLKMGR_AON_BASE_ADDR                TOP_EARLGREY_CLKMGR_AON_BASE_ADDR
#define SRAM_CTRL_MAIN_REGS_BASE_ADDR       TOP_EARLGREY_SRAM_CTRL_MAIN_REGS_BASE_ADDR
#define ENTROPY_SRC_BASE_ADDR               TOP_EARLGREY_ENTROPY_SRC_BASE_ADDR
#define CSRNG_BASE_ADDR                     TOP_EARLGREY_CSRNG_BASE_ADDR
#define EDN0_BASE_ADDR                      TOP_EARLGREY_EDN0_BASE_ADDR
#define SENSOR_CTRL_BASE_ADDR               TOP_EARLGREY_SENSOR_CTRL_AON_BASE_ADDR

#elif defined(OPENTITAN_IS_DARJEELING)
#include "hw/top/otp_ctrl_regs.h"
#include "hw/top_darjeeling/sw/autogen/top_darjeeling_memory.h"
#define OTP_CTRL_CORE_BASE_ADDR             TOP_DARJEELING_OTP_CTRL_CORE_BASE_ADDR
#define AST_BASE_ADDR                       TOP_DARJEELING_AST_BASE_ADDR
#define CLKMGR_AON_BASE_ADDR                TOP_DARJEELING_CLKMGR_AON_BASE_ADDR
#define SRAM_CTRL_MAIN_REGS_BASE_ADDR       TOP_DARJEELING_SRAM_CTRL_MAIN_REGS_BASE_ADDR
#define ENTROPY_SRC_BASE_ADDR               TOP_DARJEELING_ENTROPY_SRC_BASE_ADDR
#define CSRNG_BASE_ADDR                     TOP_DARJEELING_CSRNG_BASE_ADDR
#define EDN0_BASE_ADDR                      TOP_DARJEELING_EDN0_BASE_ADDR
#undef SENSOR_CTRL_BASE_ADDR                /* No sensor control */

#else
#error unsupported top
#endif

#ifdef ENTROPY_SRC_BASE_ADDR
#include "hw/top/entropy_src_regs.h"
#endif

/**
 * Test second ROM runtime initialization code.
 */

  // NOTE: The "ax" flag below is necessary to ensure that this section
  // is allocated executable space in ROM by the linker.
  .section .crt, "ax"

// -----------------------------------------------------------------------------

  /**
   * Callable entry point for the boot rom.
   *
   * Currently, this zeroes the `.bss` section, copies initial data to
   * `.data`, and then jumps to the program entry point.
   */
  .balign 4
  .global _start
  .type _start, @function
_start:
  // Jump into the C program entry point.
  call _second_rom_boot_start

  // Enter a wait for interrupt loop, the device should reset shortly.
.L_wfi_loop:
  wfi
  j   .L_wfi_loop
  .size _start, .-_start

// -----------------------------------------------------------------------------

  /**
   * Test ROM IRQ/exception handler; loops forever.
   */
  .balign 4
  .section .text
  .global _test_rom_irq_handler
  .type _test_rom_irq_handler, @function
_test_rom_irq_handler:
  wfi
  j _test_rom_irq_handler
  .size _test_rom_irq_handler, .-_test_rom_irq_handler
