#!/usr/bin/bash

# Check for arguments
if [ $# -ne 1 ];
then
    echo "Usage: $0 <filename>"
    exit 1
fi

#Read file name
FILE="$1"

#Check if the file exists
if [ ! -e "$FILE" ]; then
    echo "File '$FILE' does not exist"
    exit 1
fi

PREVIEW_LENGTH="${PREVIEW_LENGTH:-10}"
FILE_TYPE=$(file --mime-type -b "$FILE")

# Handle file types
case "$FILE_TYPE" in
    application/x-tar | application/gzip) # tar files
        tar -tf "$FILE" | head -n "$PREVIEW_LENGTH" ;;
    text/x=shellscript | text/x-c | text/plain) # txt files
        if command -v highlight > /dev/null; then
            highlight -O ansi "$FILE" | head -n "$PREVIEW_LENGTH"
        else
            cat "$FILE" | head -n "$PREVIEW_LENGTH"
        fi ;;
    application/x-executable | application/x-pie-executable) #  executable files 
        hexdump -C "$FILE" | head -n "$PREVIEW_LENGTH" ;;
    *) # another files
        cat "$FILE" | head -n "$PREVIEW_LENGTH" ;;
esac
