#!/bin/bash

if [ "$#" -eq 1 -a "$1" = "-h" ]; then
    echo -e "$0 [BIN] [DIR]"
    echo -e "\t[BIN] project binary"
    echo -e "\t[DIR] a directory containing files to test"
    exit 0
fi

if [ "$#" -ne 2 ]; then
    echo "Error : incorrect number of arguments (it must be 2 but it is $#)."
    exit 84
fi

if [ ! -x "$1" ]; then
    echo "Error : first parameter must be an executable."
    exit 84
fi

if [ ! -d "$2" ]; then
    echo "Error : second parameter must be a directory."
    exit 84
fi

total=$(find "$2" -type f | wc -l)
test_nb=0

for file in $(find "$2" -type f)
do
    res=$(("./$1" < "$file") 2>&1)
    ret="$?"

    ((test_nb+=1))

    echo -e "\n\e[33m[ Test n°$test_nb - executing \"$file\" ]\e[0m\n"
    echo -e "\e[35mRESULT :\e[0m"
    echo -e "\e[34m$res\e[0m\n"
    if [ $ret -eq 0 ]; then
        echo -e "\e[32mRETURN VALUE : $ret\e[0m\n"
    else
        echo -e "\e[31mRETURN VALUE : $ret\e[0m\n"
    fi
done

echo -e "\n\e[33m[ TOTAL : $total ]\e[0m"

exit 0
