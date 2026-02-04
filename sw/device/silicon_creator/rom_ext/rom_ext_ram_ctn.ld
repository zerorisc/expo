/* Copyright lowRISC contributors (OpenTitan project). */
/* Licensed under the Apache License, Version 2.0, see LICENSE for details. */
/* SPDX-License-Identifier: Apache-2.0 */

/**
 * Linker script for an OpenTitan ROM_EXT in the CTN RAM on Darjeeling.
 *
 * Portions of this file are Ibex-specific.
 */

INCLUDE hw/top_darjeeling/sw/autogen/top_darjeeling_memory.ld

MEMORY {
    /* There is a 1MiB RAM within the CTN at offset 16MiB to hold the
     * firmware under test in DV. */
    ctn_ram(rwx) : ORIGIN = ORIGIN(ctn) + 0x1000000, LENGTH = 0x100000
}

/* The ROM_EXT region is in the CTN RAM. */
_rom_ext_size = LENGTH(ctn_ram);
_rom_ext_start_address = ORIGIN(ctn_ram);

REGION_ALIAS("rom_ext_ram", ctn);

/*
 * The value kHardenedBoolFalse (0x1d4) is selected if the code is linked in
 * the CTN region.  Otherwise, the value kHardenedBoolTrue (0x739) is
 * selected.
 */
_manifest_address_translation = (_text_start >= ORIGIN(ctn_ram) &&
                                 _text_start < (ORIGIN(ctn_ram)
                                              + LENGTH(ctn_ram))) ? 0x1d4 : 0x739;

INCLUDE sw/device/silicon_creator/rom_ext/rom_ext_ram_common.ld
