#!/bin/sh

# Перевірка наявності двох аргументів
if [ "$#" -ne 2 ]; then
  echo "Потрібно ввести N та M"
  exit 1
fi

N=$1
M=$2

# Цикл від N до M
for i in $(seq $N $(($N+$M-1)))
do
  echo "$i"
done


