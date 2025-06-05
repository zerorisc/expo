# Copyright lowRISC contributors.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Modified by Authors of "Towards ML-KEM & ML-DSA on OpenTitan" (https://eprint.iacr.org/2024/1192).
# Copyright "Towards ML-KEM & ML-DSA on OpenTitan" Authors.


from .flags import FlagGroups
from .wsr import WSRFile


class CSRFile:
    '''A model of the CSR file'''
    def __init__(self) -> None:
        self.flags = FlagGroups()

        self._known_indices = set()
        self._known_indices.add(0x7c0)  # FG0
        self._known_indices.add(0x7c1)  # FG1
        self._known_indices.add(0x7c8)  # FLAGS
        for idx in range(0x7d0, 0x7d8):
            self._known_indices.add(idx)  # MODi
        self._known_indices.add(0x7d8)  # RND_PREFETCH
        self._known_indices.add(0x7d9)  # KMAC_CFG
        self._known_indices.add(0x7e2)  # KMAC_STATUS
        self._known_indices.add(0xfc0)  # RND
        self._known_indices.add(0xfc1)  # URND

    @staticmethod
    def _get_field(field_idx: int, field_size: int, val: int) -> int:
        mask = (1 << field_size) - 1
        return (val >> (field_size * field_idx)) & mask

    @staticmethod
    def _set_field(field_idx: int, field_size: int, field_val: int,
                   old_val: int) -> int:
        assert 0 <= field_val < (1 << field_size)
        mask = (1 << field_size) - 1
        shift = field_size * field_idx
        return (old_val & ~(mask << shift)) | (field_val << shift)

    def check_idx(self, idx: int) -> bool:
        '''Return True if idx points to a valid CSR; False otherwise.'''
        return idx in self._known_indices

    def read_unsigned(self, wsrs: WSRFile, idx: int) -> int:
        if 0x7c0 <= idx <= 0x7c1:
            # FG0/FG1
            fg = idx - 0x7c0
            return self._get_field(fg, 4, self.flags.read_unsigned())

        if idx == 0x7c8:
            # FLAGS register
            return self.flags.read_unsigned()

        if 0x7d0 <= idx <= 0x7d7:
            # MOD0 .. MOD7. MODi is bits [32*(i+1)-1..32*i]
            mod_n = idx - 0x7d0
            return self._get_field(mod_n, 32, wsrs.MOD.read_unsigned())

        if idx == 0x7d8:
            # RND_PREFETCH register
            return 0

        if idx == 0x7d9:
            # KMAC_CFG register
            return 0

        if idx == 0x7e2:
            # KMAC_STATUS register
            return wsrs.KMAC_STATUS.read_unsigned()

        if 0x7e3 <= idx <= 0x7ea:
            # KMAC_DIGEST_SHARE0
            digest_n = idx - 0x7e3
            return self._get_field(digest_n, 32, wsrs.KMAC_DIGEST_SHARE0.read_unsigned())

        if 0x7eb <= idx <= 0x7f2:
            # KMAC_DIGEST_SHARE1
            digest_n = idx - 0x7eb
            return self._get_field(digest_n, 32, wsrs.KMAC_DIGEST_SHARE1.read_unsigned())

        if idx == 0xfc0:
            # RND register
            return wsrs.RND.read_u32()

        if idx == 0xfc1:
            # URND register
            return wsrs.URND.read_u32()

        raise RuntimeError('Unknown CSR index: {:#x}'.format(idx))

    def write_unsigned(self, wsrs: WSRFile, idx: int, value: int) -> None:
        assert 0 <= value < (1 << 32)

        if 0x7c0 <= idx <= 0x7c1:
            # FG0/FG1
            fg = idx - 0x7c0
            old = self.flags.read_unsigned()
            self.flags.write_unsigned(self._set_field(fg, 4, value & 0xf, old))
            return

        if idx == 0x7c8:
            # FLAGS register
            self.flags.write_unsigned(value)
            return

        if 0x7d0 <= idx <= 0x7d7:
            # MOD0 .. MOD7. MODi is bits [32*(i+1)-1..32*i]. read,modify,write.
            mod_n = idx - 0x7d0
            old = wsrs.MOD.read_unsigned()
            wsrs.MOD.write_unsigned(self._set_field(mod_n, 32, value, old))
            return

        if idx == 0x7d8:
            # RND_PREFETCH
            wsrs.RND.request_value()
            return

        if idx == 0x7d9:
            # KMAC_CFG register
            wsrs.KMAC_CFG.write_unsigned(value)
            return 0

        if idx == 0x7e2:
            # KMAC_STATUS register
            return

        if 0x7e3 <= idx <= 0x7f2:
            # KMAC_DIGEST_SHARE0 and _SHARE1
            return

        if idx == 0xfc0:
            # RND register (which ignores writes)
            return

        if idx == 0xfc1:
            # URND register (which ignores writes)
            return

        raise RuntimeError('Unknown CSR index: {:#x}'.format(idx))

    def wipe(self) -> None:
        self.flags.write_unsigned(0)
