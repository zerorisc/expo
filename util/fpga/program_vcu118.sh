#!/bin/bash
# Copyright zeroRISC Inc.
# Confidential information of zeroRISC Inc. All rights reserved.

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

$TOOL -mode batch -nojournal -nolog -source "$SCRIPT_DIR/program_vcu118.tcl" -tclargs "$BITSTREAM"
