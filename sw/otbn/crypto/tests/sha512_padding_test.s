/* Copyright lowRISC contributors (OpenTitan project). */
/* Licensed under the Apache License, Version 2.0, see LICENSE for details. */
/* SPDX-License-Identifier: Apache-2.0 */

/**
 * Standalone padding test for SHA-512.
 */

.section .text.start

main:
  /* Initialize all-zero register. */
  bn.xor    w31, w31, w31

  /* Load pointers. */
  la        x11, len

  /* Load wide-register pointer. */
  li       x6, 0

  /* First test: empty message.
       x21 <= dptr_end, end of padding
       dmem[dst..dptr_end] = message padding */
  la        x10, dst
  jal       x1, sha512_pad_message

  /* Store the results (padding byte-length and value).
       x12 <= dptr_end - dst
       [w0..w1] <= dst */
  sub       x12, x21, x10
  bn.lid    x6++, 0(x10)
  bn.lid    x6++, 32(x10)

  /* Second test: 15-byte message.
       x21 <= dptr_end, end of padding
       dmem[dst+15..dptr_end] = message padding */
  la        x10, dst
  addi      x10, x10, 15
  jal       x1, sha512_pad_message

  /* Store the results (padding byte-length and value).
       x13 <= dptr_end - (dst+15)
       [w0..w1] <= dst */
  sub       x13, x21, x10
  la        x2, dst
  bn.lid    x6++, 0(x2)
  bn.lid    x6++, 32(x2)
  /* Third test: 127-byte message. */
  /* Fourth test: 128-byte message. */
  /* Fifth test: (1 << 120)-byte message. */

  ecall

.data

/* Buffer for message length. */
.balign 32
len:
.zero 32

/* Destination buffer in memory for padding. */
.balign 32
dst:
.zero 64
