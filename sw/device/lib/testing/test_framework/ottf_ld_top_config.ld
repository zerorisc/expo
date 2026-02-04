/* Copyright lowRISC contributors (OpenTitan project). */
/* Licensed under the Apache License, Version 2.0, see LICENSE for details. */
/* SPDX-License-Identifier: Apache-2.0 */

/* TODO This configuration should be split into per-top headers */
#ifdef OPENTITAN_IS_DARJEELING
MEMORY {
    /* There is a 1MiB RAM within the CTN at offset 16MiB to hold the
     * firmware under test in DV. */
    /* TODO: uncomment this to use the CTN region, not the smaller main SRAM */
    /* ctn_ram(rwx) : ORIGIN = ORIGIN(ctn) + 0x1000000, LENGTH = 0x100000 */

    /* We temporarily use the main SRAM in place of the CTN. */
    ctn_ram(rwx): ORIGIN = _bss_end, LENGTH = 0x10000 - (_bss_end - ORIGIN(ram_main))
}
REGION_ALIAS("ottf_storage", ctn_ram)
#else
REGION_ALIAS("ottf_storage", eflash)
#endif

#ifdef OPENTITAN_IS_ENGLISHBREAKFAST
/* Disable non-volatile scratch region and counters if building for english
 * breakfast. This should appear before the linker script. */
no_ottf_nv_scratch = 1
no_ottf_nv_counter = 1
#endif
