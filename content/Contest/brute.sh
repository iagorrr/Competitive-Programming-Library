#!/bin/bash

set -eu

gen="$1"
p1="$2"
p2="$3"

for ((i = 1; ; i++)); do
    echo -ne "Test $i\r"

    $gen >i.txt
    $p1 <i.txt >o1.txt
    $p2 <i.txt >o2.txt
    diff -q o1.txt o2.txt
done

# Prints first 10 lines of each file as well as the diff:
#   head -n 10 i.txt o1.txt o2.txt && diff o1.txt o2.txt
