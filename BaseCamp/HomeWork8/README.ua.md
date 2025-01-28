
# Звіт по домашній роботі №8

В цій домашній роботі потрібно реалізувати 3 скрипти за допомогою bash

## 1. preview

Скрипт preview.sh повинен приймати шлях до файлу і відповідно до типу файлу виводити відповідну інформацію.

```bash
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
```

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork8/Photo1.jpg)

## 2. validity
 
Скрипт validity.sh повинен приймати шлях до файлу/команди, перевіряти чи файл/команда існує, і виводяти відповідну інформацію.

```bash
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
```

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork8/Photo2.jpg)


## 3. str validation

Скрипт str_validity.sh повинен просити ввести рядок і перевіряти цей рядок на вміст літер та цифр.

```bash
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

```

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork8/Photo3.jpg)


