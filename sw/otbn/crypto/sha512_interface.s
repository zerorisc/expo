/* Copyright lowRISC contributors (OpenTitan project). */
/* Licensed under the Apache License, Version 2.0, see LICENSE for details. */
/* SPDX-License-Identifier: Apache-2.0 */

/**
 * The purpose of this library is to give *other OTBN code* (primarily Ed25519)
 * a clean way to call SHA-512. It is not intended for use directly from Ibex.
 */
.globl sha512_oneshot

/**
 * Initialize a SHA-512 operation by setting the initial state. 
 *
 * Sets internal buffers to their initial values. Only one SHA-512 operation
 * can be in progress at a time with this library.
 *
 * This routine runs in constant time.
 *
 * @param[in] w31: all-zero. 
 * @param[out] dmem[len]: Reset to zero. 
 * @param[out] dmem[state..state+256]: Working SHA-512 state.
 * @param[out] dmem[sha512_dptr_state]: state, pointer to working state.
 *
 * clobbered registers: x2, x3, w20
 * clobbered flag groups: FG0
 */
sha512_init:
  /* Copy the initial state into the working buffer.
       dmem[state..state+256] <= dmem[init_state..init_state+256] */
  li       x20, 20
  la       x2, init_state
  la       x3, state
  loopi    8, 2
    bn.lid   x20, 0(x2++)
    bn.sid   x20, 0(x3++)

  /* dmem[sha512_dptr_state] <= state */
  la       x2, sha512_dptr_state
  la       x3, state
  sw       x3, 0(x2)

  /* Zero the message-length buffer. */
  la       x2, len
  li       x3, 31
  bn.sid   x3, 0(x2)

  /* Zero the partial block. */
  la       x2, partial
  loopi    4, 1
    bn.sid   x3, 0(x2++)

  ret

/**
 * Add more message data to an ongoing SHA-512 operation. 
 *
 * This routine runs in constant time relative to the data but variable time
 * relative to message length.
 *
 * @param[in]     x18: msg_len, length of the new data in bytes. 
 * @param[in]     x19: dptr_msg, pointer to the new message data. 
 * @param[in]     w31: all-zero.
 *
 * clobbered registers: TODO 
 * clobbered flag groups: FG0
 */
sha512_update:
  /* Load the current message length.
       w8 <= dmem[len] */
  li       x2, 8
  la       x3, len
  bn.lid   x2, 0(x3) 

  /* Calculate the length of the current partial data.
       w9 <= len[6:0] = len mod 128 */
  bn.rshi  w9, w9, w31 >> 7
  bn.rshi  w9, w31, w9 >> 249

  /* append the message data to partial until the end of the block or end of new data */
  /* to make OK for byte-granularity, iterate through loading word (or zero) from partial,
     then shift/or message data in */
  /* if partial block is not full, simply exit*/
  /* if it is, then process it and recurse */

  ret 

/**
 * Copy data from one buffer to another in DMEM.
 *
 * The source and destination buffers should not overlap.
 *
 * This routine runs in constant time relative to the data but variable time
 * relative to data length and alignment.
 *
 * @param[in]     x18: src_len, length of the source data in bytes. 
 * @param[in]     x20: dptr_src, pointer to the source buffer
 * @param[in]     x21: dptr_dst, pointer to the destination buffer
 * @param[in]     w31: all-zero.
 *
 * clobbered registers: TODO 
 * clobbered flag groups: FG0
 */
copy:
  /* Continue only if the length of new data is nonzero; otherwise return. */
  bne      x0, x18, _copy_len_nonzero
  ret
  _copy_len_nonzero:

  /* Calculate the pointer offsets.
       x10 <= dptr_src % 32
       x11 <= dptr_dst % 32 */
  andi     x10, x20, 31
  andi     x11, x21, 31

  /* Load the data from the nearest aligned address.
       x20 <= dptr_src - (dptr_src % 32)
       x21 <= dptr_dst - (dptr_dst % 32)
       w20 <= dmem[x20]
       w21 <= dmem[x21] */
  li       x2, 20
  sub      x20, x20, x10
  sub      x21, x21, x11
  bn.lid   x2++, 0(x20)
  bn.lid   x2, 0(x21)

  /* Calculate the number of bytes following the offsets in each word.
       x16 <= 32 - (dptr_src % 32)
       x17 <= 32 - (dptr_dst % 32) */
  li       x2, 32
  sub      x16, x2, x10
  sub      x17, x2, x11

  /* Calculate the number of bytes to write from these two loads; it shoud be
     the minimum of:
       - the space remaining in the word after the source offset
       - the space remaining in the word after the destination offset
       - the remaining length of the copy.

     We compare the values by subtracting them and then checking the high bit
     of the result to detect underflow.

       x19 <= min(x16, x17, x18) */
  addi     x19, x16, 0
  sub      x2, x16, x17
  srli     x2, x2, 31
  bne      x2, x0, _copy_x16_lt_x17
  addi     x19, x17, 0
  _copy_x16_lt_x17:
  sub      x2, x19, x18
  srli     x2, x2, 31
  bne      x2, x0, _copy_x19_lt_x18
  addi     x19, x18, 0
  _copy_x19_lt_x18:


  /* Rotate the bytes of the old value at the destination that precede the
     destination pointer so that they occupy the most significant part of the
     word. These bytes will be unmodified. */
  loopi    x11, 1
    bn.rshi  w21, w21, w21 >> 8 

  /* Now shift in bytes starting from the source pointer. */
  loopi    x10, 1
    bn.rshi  w20, w20, w20 >> 8 
  loopi    x19, 1
    bn.rshi  w21, w20, w21 >> 8 

  /* Finally, if we reached the end of the source data, copy final bytes from
     the old value of the destination. We skip the loop if there are no final
     bytes, because loops cannot have zero iterations. */
  li       x2, 32
  sub      x2, x2, x11
  sub      x2, x2, x19
  beq      x2, x0, _copy_no_final_bytes
  loopi    x2, 1
    bn.rshi  w21, w21, w21 >> 8
  _copy_no_final_bytes:

  /* Store the result.
       dmem[dptr_dst - (dptr_dst % 32)] <= w21 */
  li       x2, 21
  bn.sid   x2, 0(x21)

  /* Update pointers and recursively tail-call the copy routine again. */
  sub      x18, x18, x19
  addi     x20, x20, x19
  addi     x21, x21, x19
  jal      x0, copy

/**
 * One-shot interface for SHA-512.
 *
 * The input message needs to start at a 32-byte-aligned address and be
 * followed by enough DMEM space for the padding (see `sha512_pad_message` for
 * guidance on how much space is enough).
 *
 * This routine runs in constant time.
 *
 * @param[in]     x18: dptr_result, pointer to the output buffer.
 * @param[in]     x19: len, message length in bytes.
 * @param[in]     w31: all-zero.
 * @param[in]     dmem[sha512_dptr_msg]: pointer to the start of the message.
 * @param[in,out] dmem[dptr_result..dptr_result+64]: SHA-512 digest.
 *
 * clobbered registers: x2 to x5, x10, x11, x14 to x17, x19 to x23,
 *                      w0 to w7, w10, w15 to w29
 * clobbered flag groups: FG0
 */
sha512_oneshot:
  /* Store the length in memory as a 256-bit number, for the padding routine.
       dmem[len] <= x11 */
  li       x2, 31
  la       x3, len
  bn.sid   x2, 0(x3)
  sw       x19, 0(x3)

  /* Append padding to the message.
       x21 <= dptr_end, pointer to the end of the padding
       dmem[dptr_msg+len..dptr_end] <= padding */
  la       x12, sha512_dptr_msg
  lw       x12, 0(x12)
  add      x10, x12, x19
  la       x11, len
  jal      x1, sha512_pad_message

  /* Calculate and store the number of blocks with padding included.
       dmem[sha512_n_chunks] <= x11 <= (x21 - dptr_msg) / 128 */
  sub      x2, x21, x12
  srli     x11, x2, 7
  la       x2, sha512_n_chunks
  sw       x11, 0(x2)
  
  /* Format the message blocks in preparation for sha512 computation. */
  jal      x1, sha512_format_blocks

  /* Copy the initial state into the working buffer.
       dmem[state..state+256] <= dmem[init_state..init_state+256] */
  li       x20, 20
  la       x2, init_state
  la       x3, state
  loopi    8, 2
    bn.lid   x20, 0(x2++)
    bn.sid   x20, 0(x3++)

  /* dmem[sha512_dptr_state] <= state */
  la       x2, sha512_dptr_state
  la       x3, state
  sw       x3, 0(x2)

  /* Call the hash function to update the state in-place. */
  jal      x1, sha512_compact
  
  /* Load the mask for byte-swaps.
       w29 <= dmem[bswap64_mask] */
  la       x2, bswap64_mask
  li       x3, 29
  bn.lid   x3, 0(x2)

  /* Load a 64-bit mask.
       w30 <= 2^64 - 1 */
  bn.not   w30, w31
  bn.rshi  w30, w31, w30 >> 192

  /* Read out the 8 64-bit integers that comprise the state. Reverse their
     bytes and concatenate to get the standard SHA-512 byte order. */
  li       x28, 28
  li       x21, 21
  la       x2, state
  addi     x3, x18, 0
  loopi    2, 7
    /* w28 <= 0 */
    bn.sub   w28, w28, w28
    loopi    4, 3
      /* w21[63:0] <= H[i] */
      bn.lid   x21, 0(x2++)
      /* w21 <= w21[63:0] */
      bn.and   w21, w21, w30
      /* w28 <= H[i] ^ (w28 << 64) */
      bn.xor   w28, w21, w28 << 64
    /* w28 <= reverse_bytes(w28) */
    jal      x1, reverse_bytes
    /* dmem[dptr_result+i*32] <= w28 */
    bn.sid   x28, 0(x3++)

  ret 

/**
 * Completely reverse the bytes of a 256-bit word.
 *
 * This routine runs in constant time.
 *
 * @param[in] w29: Specialized mask (0xff as a 64-bit word, repeated 4x).
 * @param[in] w30: constant 64-bit mask, 2^64 - 1
 * @param[in,out] w28: Wide word to process (modified in-place).
 *
 * clobbered registers: w20 to w28
 * clobbered flag groups: FG0
 */
reverse_bytes:
  /* Select the 64-bit chunks of the word.
       w20 <= w28[ 63:  0]
       w21 <= w28[127: 64] << 64
       w22 <= w28[191:128] << 128
       w23 <= w28[255:192] << 192 */
  bn.and   w20, w30, w28
  bn.and   w21, w30, w28 >> 64
  bn.and   w22, w30, w28 >> 128
  bn.and   w23, w30, w28 >> 192

  /* Reverse the order of the 64-bit chunks.
       w28 <= w20 || w21 || w22 || w23 */
  bn.or    w28, w21, w20 << 64 
  bn.or    w28, w22, w28 << 64 
  bn.or    w28, w23, w28 << 64 

  /* Tail-call to byte-swap each 64-bit word. */
  jal      x0, bswap64

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
 * @param[in]     x11: nblocks, number of blocks to process. 
 * @param[in]     x12: dptr_msg, pointer to the start of the first block.
 * @param[in,out] dmem[dptr_msg..dptr_msg+nblocks*128]: Message (modified in-place).
 *
 * clobbered registers: x2, x3, x12, x28, w20 to w29
 * clobbered flag groups: FG0
 */
sha512_format_blocks:
  /* Load constants.
       x28 <= 28
       w29 <= dmem[bswap64_mask] */
  li       x28, 28
  la       x2, bswap64_mask
  li       x3, 29
  bn.lid   x3, 0(x2)

  /* Loop through the blocks in 256-bit chunks. */
  slli     x3, x11, 2
  loop     x3, 3
    /* w28 <= dmem[x12] */
    bn.lid   x28, 0(x12)
    /* w28 <= bswap64(w28) */
    jal      x1, bswap64
    /* dmem[x12++] <= w28 */
    bn.sid   x28, 0(x12++)

  ret

/**
 * Swap the bytes for each 64-bit chunk of a 256-bit word.
 *
 * This routine runs in constant time.
 *
 * @param[in,out] w28: Wide word to process (modified in-place).
 * @param[in,out] w29: Specialized mask (0xff as a 64-bit word, repeated 4x).
 *
 * clobbered registers: w20 to w28
 * clobbered flag groups: FG0
 */
bswap64:
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
  bn.or    w28, w22, w28 << 8
  bn.or    w28, w23, w28 << 8
  bn.or    w28, w24, w28 << 8
  bn.or    w28, w25, w28 << 8
  bn.or    w28, w26, w28 << 8
  bn.or    w28, w27, w28 << 8

  ret

.section .scratchpad

/* Buffer for the working hash state. */
.balign 32
state:
.zero 256

/* Temporary buffer for message length. */
.balign 32
len:
.zero 32

/* Partial message block (1024 bits). */
.balign 32
partial:
.zero 128

.data

/* Specialized mask for wide word byte-swaps. */
.balign 32
bswap64_mask:
.dword 0x00000000000000ff
.dword 0x00000000000000ff
.dword 0x00000000000000ff
.dword 0x00000000000000ff

/* Initial hash state in pre-processed form. */
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
