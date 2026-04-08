/* Copyright lowRISC contributors (OpenTitan project). */
/* Licensed under the Apache License, Version 2.0, see LICENSE for details. */
/* SPDX-License-Identifier: Apache-2.0 */
/*
 *   Standalone test for P-384 point addition in projective space
 *
 *   Performs addition of two valid P-384 points in projective space.
 *   Constant coordinates for the two points contained in the .data section.
 *
 *   See comment at the end of the file for expected values of coordinates
 *   of resulting point.
 */

.section .text.start

p384_proj_double_test:

  /* load point */
  li       x2, 25
  la       x3, p1_x
  bn.lid   x2++,   0(x3)
  bn.lid   x2++,  32(x3)
  bn.lid   x2++,  64(x3)
  bn.lid   x2++,  96(x3)
  bn.lid   x2++, 128(x3)
  bn.lid   x2++, 160(x3)

  /* load domain parameter p (modulus)
     [w13, w12] = p */
  li       x2, 12
  la       x3, p384_p
  bn.lid   x2++, 0(x3)
  bn.lid   x2++, 32(x3)

  /* init all-zero reg */
  bn.xor   w31, w31, w31

  /* set reg file pointers */
  li x22,  10
  li x23,  11
  li x24,  16
  li x25,  17

  jal      x1, proj_double_p384

  ecall

.section .data

/* point 1 x-cooridante p1_x */
p1_x:
  .word 0x1a11808b
  .word 0x02e3d5a9
  .word 0x440d8db6
  .word 0x5ef02be3
  .word 0x2a35de10
  .word 0xdbdb132e
  .word 0xf84e7899
  .word 0x7dff4c2b
  .word 0x24705317
  .word 0x30eda4ab
  .word 0xb44ba799
  .word 0x3af8f1c5
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000

/* point 2 y-cooridante p1_y */
p1_y:
  .word 0xa9f8b96e
  .word 0x82f268be
  .word 0x8e51c662
  .word 0x92b9c4bb
  .word 0x757d4493
  .word 0x26b4d3c6
  .word 0xf491007e
  .word 0x92a5c72a
  .word 0x8d8d8641
  .word 0x87498a20
  .word 0x0fe7dbde
  .word 0x841e4949
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000

/* point 1 z-cooridante p1_z */
p1_z:
  .word 0x00000001
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
