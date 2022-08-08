#!/bin/bash
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 {source.cpp}"
    exit
fi

source=$1
output=${source%.*}

g++ -o $output -W -Wall -O2 -std=c++17 -Wextra -Wshadow -Wformat=2 -Wconversion -fsanitize=address,undefined -fno-sanitize-recover -Wfatal-errors -static-libasan $source $2