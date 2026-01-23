#!/bin/bash
# Copyright zeroRISC Inc.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

set -e

# Fetch arguments.
SCANCODE_BIN=$1
POLICY=$2
TAR=$3
shift 3

# Create a temporary directory for the files to scan.
SRC_DIR="$TEST_TMPDIR"/_srcs
mkdir -p ${SRC_DIR}
JSON=$TEST_TMPDIR/scancode.json

# Extract archive.
tar -xf "$TAR" -C $SRC_DIR

# Run ScanCode.
$SCANCODE_BIN -clipeu --license-policy="$POLICY" --json=$JSON "$@" $SRC_DIR

# Filter JSON to check for restricted/prohibited licenses.
filter() {
    filter_files_alert="select(.license_policy[].compliance_alert|IN(\"$1\"))"
    intermediate_json="{path: .path, license: (.license_policy[] | select(.compliance_alert == \"$1\"))}"
    format="\"\\(.path): \\(.license.license_key)\""
    echo ".files[] | ${filter_files_alert} | ${intermediate_json} | ${format}"
}

echo "Files with restricted licenses:"
out=$(cat ${JSON} | jq -r "$(filter "warning")")
echo -e "${out}\n"

echo "Files with prohibited licenses:"
out=$(cat ${JSON} | jq -r "$(filter "error")")
echo -e "${out}"
# Set the exit code nonzero iff any prohibited licenses were detected.
test -z "${out}"
