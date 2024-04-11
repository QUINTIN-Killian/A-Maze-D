#!/bin/bash

if [ "$#" -eq 1 -a "$1" = "-h" ]; then
    echo -e "$0 [N]"
    echo -e "\t[N] number of iteration"
    exit 0
fi

if [ "$#" -ne 1 ]; then
    echo "Error : incorrect number of arguments (it must be 1 but it is $#)."
    exit 84
fi

nb='^[0-9]+$'

if ! [[ $1 =~ $nb ]]; then
   echo "Error: Argument 1 must be a number"
   exit 84
fi

n=0

while [ $n -ne $1 ];
do
    echo ""
    ((n+=1))
    python3 my_generator.py -r 10 -t 10 ; ./../amazed < scripts/maze
    echo ""
done

exit 0
