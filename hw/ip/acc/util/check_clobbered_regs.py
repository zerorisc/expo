#!/usr/bin/env python3
# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
'''Check that clobbered-register annotations match actual writes.

Runs the information-flow analysis on a single subroutine to generate the
correct clobbered-register annotation, then compares against the docstring
in the assembly source file.
'''

import argparse
import re
import sys
from typing import Optional, Tuple

from shared.control_flow import subroutine_control_graph
from shared.decode import decode_elf
from shared.information_flow_analysis import get_subroutine_iflow


def _find_docstring(source_path: str, symbol: str) -> Optional[str]:
    '''Find the /** ... */ docstring for a symbol in a source file.'''
    with open(source_path, 'r') as f:
        content = f.read()

    label_m = re.search(
        r'^' + re.escape(symbol) + r'\s*:', content, re.MULTILINE)
    if label_m is None:
        return None

    before = content[:label_m.start()]
    doc_m = None
    for m in re.finditer(r'/\*\*.*?\*/', before, re.DOTALL):
        doc_m = m
    if doc_m is None or 'clobbered registers:' not in doc_m.group(0):
        return None

    between = content[doc_m.end():label_m.start()]
    if re.search(r'^[a-zA-Z_]\w*\s*:', between, re.MULTILINE):
        return None

    return doc_m.group(0)


def _extract_declared(doc: str) -> Tuple[str, str]:
    '''Extract declared clobbered registers and flags from a docstring.'''
    m = re.search(r'clobbered registers:\s*(.+)', doc)
    regs = m.group(1).strip() if m else ''
    m = re.search(r'clobbered flag groups:\s*(.+)', doc, re.IGNORECASE)
    flags = m.group(1).strip() if m else ''
    return regs, flags


def main() -> int:
    parser = argparse.ArgumentParser(
        description='Check clobbered-register annotations in ACC assembly.')
    parser.add_argument('elf', help='Path to the ACC ELF binary.')
    parser.add_argument('--subroutine', required=True,
                        help='Subroutine to check.')
    parser.add_argument('--source', '-s', required=True,
                        help='Assembly source file (.s).')
    args = parser.parse_args()

    program = decode_elf(args.elf)

    doc = _find_docstring(args.source, args.subroutine)
    if doc is None:
        print('No clobbered-registers docstring found for {}'.format(
            args.subroutine), file=sys.stderr)
        return 1

    declared_regs, declared_flags = _extract_declared(doc)

    # Generate actual clobbers via information-flow analysis.
    graph = subroutine_control_graph(program, args.subroutine)
    ret_iflow, _, _ = get_subroutine_iflow(
        program, graph, args.subroutine, {})
    if not ret_iflow.exists:
        print('No return paths found for {}'.format(
            args.subroutine), file=sys.stderr)
        return 1

    lines = ret_iflow.clobbered().split('\n')
    gen_regs = lines[0].replace('* clobbered registers: ', '')
    gen_flags = lines[1].replace('* clobbered flag groups: ', '')

    regs_match = gen_regs == declared_regs
    flags_match = gen_flags == declared_flags
    if not (regs_match and flags_match):
        print('{}:'.format(args.subroutine))
        if not regs_match:
            print('  declared: clobbered registers: {}'.format(declared_regs))
            print('  actual:   clobbered registers: {}'.format(gen_regs))
        if not flags_match:
            print('  declared: clobbered flag groups: {}'.format(
                declared_flags))
            print('  actual:   clobbered flag groups: {}'.format(gen_flags))
        return 1

    return 0


if __name__ == '__main__':
    sys.exit(main())
