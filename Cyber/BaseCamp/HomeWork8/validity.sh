#!/bin/bash

# Check for arguments
if [ $# -ne 1 ];
then
    echo "usage: $0 command or path"
    exit 1
fi

#Read input
input="$1"

# Check if it's an absolute path
if [[ "$input" =~ ^/ ]]; then
    # Check if file exists and is executable
    if [ -x "$input" ]; then
        echo "$input found and executable"
        exit 0
    else
        echo "$input not found or not executable"
        exit 1
    fi
else
    # Check if command exists in PATH
    if command -v "$input" > /dev/null 2>&1; then
        echo "$input found in PATH"
        exit 0
    else
        echo "$input not found in PATH"
        exit 1
    fi
fi
