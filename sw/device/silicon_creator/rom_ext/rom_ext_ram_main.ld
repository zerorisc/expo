/* Copyright lowRISC contributors (OpenTitan project). */
/* Licensed under the Apache License, Version 2.0, see LICENSE for details. */
/* SPDX-License-Identifier: Apache-2.0 */

/**
 * Linker script for an OpenTitan ROM_EXT in the main SRAM in Darjeeling.
 *
 * Portions of this file are Ibex-specific.
 */

INCLUDE hw/top_earlgrey/sw/autogen/top_darjeeling_memory.ld

/* The ROM_EXT region in SRAM begins just after the ROM data memory. */
_rom_ext_size = LENGTH(ram_main);
_rom_ext_start_address = ORIGIN(ram_main);

REGION_ALIAS("rom_ext_ram", ram_main);

/*
 * The value kHardenedBoolFalse (0x1d4) is always selected here. There is no
 * translation for main SRAM.
 */
_manifest_address_translation = 0x1d4;

INCLUDE sw/device/silicon_creator/rom_ext/rom_ext_ram_common.ld
