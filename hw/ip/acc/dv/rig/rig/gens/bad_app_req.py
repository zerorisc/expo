# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

import random
from typing import Optional, Tuple
from enum import Enum, auto

from shared.insn_yaml import InsnsFile

from .app_req import KmacAppReqInsn
from ..config import Config
from ..program import ProgInsn, Program
from ..model import Model
from ..snippet import ProgSnippet
from ..snippet_gen import GenCont, GenRet, SnippetGen


class BadKmacAppReqInsn(KmacAppReqInsn):
    '''A snippet generator that generates program ending kmac instructions.
    This includes oversized/undersized messages, fifo overflows, invalid
    share read/writes.
    '''

    pqc_program = True
    ends_program = True

    def __init__(self, cfg: Config, insns_file: InsnsFile) -> None:
        super().__init__()

        self._error_mode = KmacErrorMode.Oversized

    def _gen(self, model: Model, program: Program) -> list[ProgInsn]:
        """ Helper function to build and return a full instruction list for the given message size.
            The list of instructions returned are illegal for KMAC operations.
        """
        # Take a clean KMAC operation to inject errors into
        insn_list = super()._gen(model, program)

        return insn_list


class KmacErrorMode(Enum):
    Oversized = auto()
    Undersized = auto()
    IllegalMsg = auto()
    IllegalDigest = auto()
    Overflow = auto()