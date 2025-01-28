#!/bin/bash

# Check for arguments
if [ $# -ne 1 ];
then
    echo "usage: $0 command or path"
    exit 1
fi

#Read input
INPUT="$1"

# Check if it's an absolute path
if [[ "$INPUT" =~ ^/ ]]; then
    # Check if file exists and is executable
    if [ -x "$INPUT" ]; then
        echo "$INPUT found and executable"
        exit 0
    else
        echo "$INPUT not found or not executable"
        exit 1
    fi
else
    # Check if command exists in PATH
    if command -v "$INPUT" > /dev/null 2>&1; then
        echo "$INPUT found in PATH"
        exit 0
    else
        echo "$INPUT not found in PATH"
        exit 1
    fi
fi
