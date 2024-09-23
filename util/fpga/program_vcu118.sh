#!/bin/bash
# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

if [ "$#" -ne 1 ]; then
  echo "Usage: $0 </path/to/bitstream.bit>"
  exit 1
fi

SCRIPT_DIR=$(dirname "$(realpath "$0")")
BITSTREAM=$1

if command -v vivado; then
  TOOL=vivado
elif command -v vivado_lab; then
  TOOL=vivado_lab
else
  echo "Error: could not find tool. Please install Vivado or Vivado Lab Edition"
  exit 1
fi

# When using `bazel test` $HOME is not set but Vivado requires it to be set, so set it explicitely when running Vivado
# `bazel test` uses $TEST_TMPDIR as a base directory which seems like an appropriate directory to set $HOME to
export HOME="${HOME:=TEST_TMPDIR}"
$TOOL -mode batch -nojournal -nolog -source "$SCRIPT_DIR/program_vcu118.tcl" -tclargs "$BITSTREAM"
