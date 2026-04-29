#!/usr/bin/env python3
# Copyright lowRISC contributors (OpenTitan project).
# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

import re
from copy import deepcopy
from typing import Any, Dict, Iterable, List, Optional

from .information_flow import DmemInformationFlowNode
from .insn_yaml import Insn
from .operand import RegOperandType


def get_op_val_str(insn: Insn, op_vals: Dict[str, int], opname: str) -> str:
    '''Get the value of the given (register) operand as a string.'''
    op = insn.name_to_operand[opname]
    assert isinstance(op.op_type, RegOperandType)
    return op.op_type.op_val_to_str(op_vals[opname], None)


class ConstantContext:
    '''Represents known-constant GPRs and memory words.

    This datatype is used to track and evaluate GPR pointers for indirect
    references and memory offsets.
    '''

    def __init__(self, values: Dict[str, int]):
        # The x0 register needs to always be 0
        assert values.get('x0', None) == 0
        self.values = values.copy()

    @staticmethod
    def empty() -> 'ConstantContext':
        '''Represents a context with no known constants.'''
        return ConstantContext({'x0': 0})

    def set(self, key: str, value: int) -> None:
        '''Set the value of a GPR or memory address in the context.'''
        if key == 'x0':
            # Ignore writes to x0; it's read-only.
            return
        self.values[key] = value

    def get(self, key: str) -> Optional[int]:
        '''Get the value of a GPR or memory address in the context.'''
        return self.values.get(key, None)

    def __contains__(self, gpr: str) -> bool:
        return gpr in self.values

    def __deepcopy__(self, memo: Optional[Dict[int,
                                               Any]]) -> 'ConstantContext':
        return ConstantContext(deepcopy(self.values, memo))

    def includes(self, other: 'ConstantContext') -> bool:
        '''Returns true iff other is a restriction of self.'''
        for k, v in other.values.items():
            if self.get(k) != v:
                return False
        return True

    def intersect(self, other: 'ConstantContext') -> 'ConstantContext':
        '''Returns a new context with only values on which self/other agree.

        Does not modify self or other.
        '''
        out = {}
        for k, v in self.values.items():
            if other.get(k) == v:
                out[k] = v
        return ConstantContext(out)

    def removemany(self, to_remove: Iterable[str]) -> None:
        '''Remove the given registers from the constant context.

        Useful for cases when, for example, the given registers have been
        overwritten. Does nothing for registers that are not known constants,
        or for the special register x0.
        '''
        for reg in to_remove:
            if reg != 'x0':
                self.values.pop(reg, None)

    def update_insn(self, insn: Insn, op_vals: Dict[str, int], coarse_dmem: bool) -> None:
        '''Updates to new known constant values GPRs after the instruction.

        Currently, this procedure supports only a limited set of instructions.
        Since constant values only need to be known in order to decode indirect
        references to WDRs and loop counts, this set is chosen based on
        operations likely to happen to those registers: `addi`, `lui`, and
        bignum instructions containing `_inc` op_vals.
        '''
        new_values = {}
        if insn.mnemonic == 'addi':
            grs1_name = get_op_val_str(insn, op_vals, 'grs1')
            if grs1_name in self.values:
                grd_name = get_op_val_str(insn, op_vals, 'grd')
                # Operand is a constant; add/update grd
                new_values[grd_name] = (self.values[grs1_name] +
                                        op_vals['imm']) % (1 << 32)
        elif insn.mnemonic == 'slli':
            grs1_name = get_op_val_str(insn, op_vals, 'grs1')
            if grs1_name in self.values:
                grd_name = get_op_val_str(insn, op_vals, 'grd')
                # Operand is a constant; add/update grd
                new_values[grd_name] = (
                    self.values[grs1_name] << op_vals['shamt']) % (1 << 32)
        elif insn.mnemonic == 'srli':
            grs1_name = get_op_val_str(insn, op_vals, 'grs1')
            if grs1_name in self.values:
                grd_name = get_op_val_str(insn, op_vals, 'grd')
                # Operand is a constant; add/update grd
                new_values[
                    grd_name] = self.values[grs1_name] >> op_vals['shamt']
        elif insn.mnemonic == 'add':
            grs1_name = get_op_val_str(insn, op_vals, 'grs1')
            grs2_name = get_op_val_str(insn, op_vals, 'grs2')
            if grs1_name in self.values and grs2_name in self.values:
                grd_name = get_op_val_str(insn, op_vals, 'grd')
                # Operand is a constant; add/update grd
                new_values[grd_name] = (self.values[grs1_name] +
                                        self.values[grs2_name]) % (1 << 32)
        elif insn.mnemonic == 'sub':
            grs1_name = get_op_val_str(insn, op_vals, 'grs1')
            grs2_name = get_op_val_str(insn, op_vals, 'grs2')
            if grs1_name in self.values and grs2_name in self.values:
                grd_name = get_op_val_str(insn, op_vals, 'grd')
                # Operand is a constant; add/update grd
                new_values[grd_name] = (self.values[grs1_name] -
                                        self.values[grs2_name]) % (1 << 32)
        elif insn.mnemonic == 'lui':
            grd_name = get_op_val_str(insn, op_vals, 'grd')
            new_values[grd_name] = op_vals['imm'] << 12
        elif insn.mnemonic == 'lw' and not coarse_dmem:
            grd_name = get_op_val_str(insn, op_vals, 'grd')
            grs1_name = get_op_val_str(insn, op_vals, 'grs1')
            if grs1_name in self.values:
                addr = (self.values[grs1_name] + op_vals['offset']) % (1 << 32)
                src_name = DmemInformationFlowNode(addr, addr + 4).name
                if src_name in self.values:
                    new_values[grd_name] = self.values[src_name]
        elif insn.mnemonic == 'sw' and not coarse_dmem:
            grs1_name = get_op_val_str(insn, op_vals, 'grs1')
            grs2_name = get_op_val_str(insn, op_vals, 'grs2')
            if grs1_name in self.values and grs2_name in self.values:
                addr = (self.values[grs1_name] + op_vals['offset']) % (1 << 32)
                dest_name = DmemInformationFlowNode(addr, addr + 4).name
                new_values[dest_name] = self.values[grs2_name]
        elif insn.mnemonic in ['bn.lid', 'bn.sid', 'bn.movr']:
            # If the instruction has any op_vals ending in _inc,
            # assume we're incrementing the corresponding register
            for op in insn.operands:
                if op.name.endswith('_inc') and op_vals[op.name] != 0:
                    # If reg to be incremented is a constant, increment it
                    inc_op = op.name[:-(len('_inc'))]
                    inc_name = get_op_val_str(insn, op_vals, inc_op)
                    inc_amount = 1
                    if insn.mnemonic in ['bn.lid', 'bn.sid'] and op.name == 'grs1_inc':
                        inc_amount = 32
                    if inc_name in self.values:
                        new_values[inc_name] = (self.values[inc_name] +
                                                inc_amount) % (1 << 32)

        # If the instruction's information-flow graph indicates that we updated
        # any constant register other than the ones handled above, the value of
        # that register can no longer be determined; remove it from the
        # constants dictionary.
        iflow = insn.iflow.evaluate(op_vals, self.values, True)
        self.removemany([n.name for n in iflow.all_sinks()])

        self.values.update(new_values)


def _parse_constant(value: str, dmem_symbols: Dict[str, int]) -> int:
    '''Interprets a value from a literal (decimal or hex) or DMEM symbol.'''
    try:
        if value.startswith('0x'):
            return int(value, 16)
        elif value in dmem_symbols:
            return dmem_symbols[value]
        return int(value)
    except ValueError:
        raise ValueError(
            f'Cannot parse required constant: {value} is not a '
            'recognized numeric value or DMEM label.')


def is_gpr_name(name: str) -> bool:
    return name in [f'x{i}' for i in range(32)]


def parse_dmem_slot(token: str, dmem_symbols: str) -> Optional[int]:
    m = re.match(r'dmem:(.*)\[:([0-9]+)\]:(.*)', token)
    if m is None:
        raise ValueError(f'Cannot interpret constant: {token}')
    label = m.group(1)
    length = int(m.group(2))
    if length != 4:
        raise ValueError(f'Cannot interpret {token} as a constant: constant '
                         'DMEM slots must be exactly 4 bytes.')
    value = m.group(3)
    start = _parse_constant(label, dmem_symbols)
    value = _parse_constant(value, dmem_symbols)
    return DmemInformationFlowNode(start, start + length).name, value


def parse_required_constants(constants: List[str],
                             dmem_symbols: Dict[str, int]) -> Dict[str, int]:
    '''Parses required initial constants.

    Constants are expected to be provided in the form <reg>:<value>, e.g.
    x5:0xfffffff or x22:0. The value can be expressed in decimal or integer
    form. Only GPRs are accepted as required constants (not wide registers or
    special registers).
    '''
    GPR_MAX = (1 << 32) - 1

    out = {}
    for token in constants:
        if token.startswith('dmem'):
            name, value = parse_dmem_slot(token, dmem_symbols)
            out[name] = value
            continue

        reg_and_value = token.split(':')
        if len(reg_and_value) != 2:
            raise ValueError(
                f'Could not parse required constant {token}. Please provide '
                'required constants in the form <reg>:<value>, e.g. x5:3.')
        reg, value = reg_and_value
        if not is_gpr_name(reg):
            raise ValueError(
                f'Cannot parse required constant {token}: {reg} is not a '
                'valid GPR name or 4-byte DMEM slot.')
        value = _parse_constant(value, dmem_symbols)
        if value < 0 or value > GPR_MAX:
            raise ValueError(
                f'Cannot parse required constant {token}: {value} is out of '
                'range [0, GPR_MAX].')
        out[reg] = value

    return out
