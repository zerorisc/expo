/* Copyright lowRISC contributors (OpenTitan project). */
/* Licensed under the Apache License, Version 2.0, see LICENSE for details. */
/* SPDX-License-Identifier: Apache-2.0 */

/**
 * One-shot interface for SHA-512.
 *
 * The input message needs to start at a 32-byte-aligned address and be
 * followed by enough DMEM space for the padding (the total padded length will
 * be the smallest multiple of 128 bytes that fits the message plus 9 bytes).
 *
 * This routine runs in constant time.
 *
 * @param[in]     x12: dptr_msg, pointer to the start of the message.
 * @param[in]     x13: len, message length in bytes.
 * @param[in]     w31: all-zero.
 * @param[in,out] dmem[sha512_result..sha512_result+64]: SHA-512 digest.
 *
 * clobbered registers: TODO
 * clobbered flag groups: TODO
 */
sha512_oneshot:
  /* Store the length in memory as a 256-bit number, for the padding routine.
       dmem[len] <= x11 */
  li       x2, 31
  la       x3, len
  bn.sid   x2, 0(x3)
  sw       x13, 0(x3)

  /* Append padding to the message.
       x21 <= dptr_end, pointer to the end of the padding
       dmem[x12+x13..dptr_end] <= padding */
  add      x10, x12, x13
  la       x11, len
  jal      x1, sha512_pad_message

  /* Calculate and store the number of blocks with padding included.
       dmem[sha512_n_chunks] <= x11 <= (x21 - x12) / 128 */
  sub      x2, x21, x12
  slri     x11, x2, 7
  la       x2, sha512_n_chunks
  sw       x11, 0(x2)

  /* Copy the initial state into the working buffer.
       dmem[state..state+256] <= dmem[init_state..init_state+256] */
  li       x20, 20
  la       x2, init_state
  la       x3, state
  loopi    8, 2
    bn.lid   x20, 0(x2++)
    bn.sid   x20, 0(x3++)
  
  /* dmem[sha512_dptr_msg] <= x12 = dptr_msg */
  la       x2, sha512_dptr_msg
  sw       x12, 0(x2)

  /* dmem[sha512_dptr_state] <= state */
  la       x2, sha512_dptr_state
  la       x3, state
  sw       x3, 0(x2)

  /* Call the hash function to update the state in-place. */
  jal      x1, sha512_compact

  /* The state is produced in a processed form, with 8 32-bit words that each
     contain a little-endian 64-bit word in their lowest 64 bits. To comply
     with the usual SHA-512 byte order, we need to reverse each word and
     concatenate them. */
  
  
/*
 * @param[in]  x10: dptr_pad, pointer to end of message in DMEM
 * @param[in]  x11: dptr_len, pointer to message length in bytes (256 bits)
 * @param[in]  w31: all-zero
 * @param[out] x21: dptr_end, pointer to the end of the padding
 * @param[out] dmem[dptr_pad..dptr_end]: message padding
*/

/**
 * Format message blocks for SHA-512, in-place.
 *
 * The SHA-512 routine expects message blocks to be pre-processed;
 * specifically, each 64-bit section of the block should be in reverse byte
 * order.
 *
 * Apply padding before calling this routine, if it is needed.
 *
 * This routine runs in constant time relative to the message content but
 * variable time relative to the number of blocks.
 *
 * @param[in]     x10: dptr_msg, pointer to the start of the first block.
 * @param[in]     x11: nblocks, number of blocks to process. 
 * @param[in,out] dmem[dptr_msg..dptr_msg+nblocks*128]: Message blocks (modified in-place).
 *
 * clobbered registers: x2, x3, x10, x20, w20 to w29
 * clobbered flag groups: FG0
 */
sha512_format_blocks:
  /* Load constants.
       x20 <= 20
       w29 <= dmem[bswap64_mask] */
  li       x20, 20
  la       x2, bswap64_mask
  li       x3, 29
  bn.lid   x3, 0(x2)

  /* Loop through the blocks in 256-bit chunks. */
  slli     x3, x11, 2
  loop     x3, 17
    /* w20 <= dmem[x10] */
    bn.lid   x20, 0(x10)

    /* Isolate each byte of each 64-bit word.
         w20 <= byte 0 of each word = a
         w21 <= byte 1 of each word = b
         w22 <= byte 2 of each word = c
         w23 <= byte 3 of each word = d
         w24 <= byte 4 of each word = e
         w25 <= byte 5 of each word = f
         w26 <= byte 6 of each word = g
         w27 <= byte 7 of each word = h */
    bn.and   w20, w29, w28
    bn.and   w21, w29, w28 >> 8
    bn.and   w22, w29, w28 >> 16
    bn.and   w23, w29, w28 >> 24
    bn.and   w24, w29, w28 >> 32
    bn.and   w25, w29, w28 >> 40
    bn.and   w26, w29, w28 >> 48
    bn.and   w27, w29, w28 >> 56

    /* Shift/or the bytes back in reversed order.
         w20 <= a || b || c || d || e || f || g || h */
    bn.or    w28, w21, w20 << 8
    bn.or    w28, w22, w23 << 8
    bn.or    w28, w23, w23 << 8
    bn.or    w28, w24, w23 << 8
    bn.or    w28, w25, w23 << 8
    bn.or    w28, w26, w23 << 8
    bn.or    w28, w27, w23 << 8

    /* dmem[x10] <= w20 */
    bn.sid   x20, 0(x10++)

  ret

.bss

/* Number of message blocks. */
.globl sha512_n_chunks
.weak sha512_n_chunks
.balign 4
sha512_n_chunks:
  .zero 4

/* Pointer to message start. */
.globl sha512_dptr_msg
.balign 4
sha512_dptr_msg:
  .zero 4

/* Temporary buffer for message length. */
len:
.zero 128

.data

/* Specialized mask for wide word byte-swaps. */
.balign 32
bswap64_mask:
.dword 0x00000000000000ff
.dword 0x00000000000000ff
.dword 0x00000000000000ff
.dword 0x00000000000000ff

/**
 * Initial hash state in pre-processed form.
 */
.balign 32
init_state:
.dword 0x6a09e667f3bcc908
  .balign 32
.dword 0xbb67ae8584caa73b
  .balign 32
.dword 0x3c6ef372fe94f82b
  .balign 32
.dword 0xa54ff53a5f1d36f1
  .balign 32
.dword 0x510e527fade682d1
  .balign 32
.dword 0x9b05688c2b3e6c1f
  .balign 32
.dword 0x1f83d9abfb41bd6b
  .balign 32
.dword 0x5be0cd19137e2179

/* Buffer for the working hash state. */
.balign 32
state:
.zero 256

/* Buffer for the final result. */
.balign 32
.globl sha512_result
sha512_result:
.zero 64
