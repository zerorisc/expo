/* Copyright lowRISC contributors (OpenTitan project). */
/* Licensed under the Apache License, Version 2.0, see LICENSE for details. */
/* SPDX-License-Identifier: Apache-2.0 */

/**
 * Linker script for an OpenTitan ROM_EXT in the CTN RAM on Darjeeling using
 * virtual addressing.
 *
 * Portions of this file are Ibex-specific.
 */

INCLUDE hw/top_earlgrey/sw/autogen/top_darjeeling_memory.ld

/**
 * Symbols to be used in the setup of the address translation for ROM_EXT.
 */
_rom_ext_start_address = ORIGIN(rom_ext_virtual);
_rom_ext_size = LENGTH(rom_ext_virtual);
ASSERT(_rom_ext_size <= LENGTH(ctn), "Error: rom ext flash is bigger than slot");

REGION_ALIAS("rom_ext_ram", rom_ext_virtual);

INCLUDE sw/device/silicon_creator/rom_ext/rom_ext_ram_common.ld
