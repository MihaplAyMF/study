#!/bin/sh

file_count=$(ls -1 | wc -l)

# Вивести стільки символів @, скільки файлів у поточному каталозі
for i in $(seq 1 $file_count); do
	echo "@"
done

# Перенос на новий рядок

