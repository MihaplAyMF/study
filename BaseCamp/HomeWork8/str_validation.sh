#!/bin/bash

# Check for arguments
if [ $# -ne 0 ];
then
    echo "usage: $0"
    exit 1
fi

# Read input
echo -n "Enter input: "
read input

# Verification: only letters and numbers
if [[ "$input" =~ ^[a-zA-Z0-9]+$ ]]; then
    echo "Input is valid"
else
    echo "Please enter only letters and numbers"
fi

