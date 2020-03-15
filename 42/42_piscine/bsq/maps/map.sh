#!/bin/bash

MAX_SIZE=20
DENSITY=5

if [ $# -eq 0 ]
then
	sh "$0" 1 | tee random.map
	# echo "usage: $(basename "$0") [x y density]"
	# exit 1
elif [ $# -eq 1 ]
then
	for i in $(seq $1)
	do
		x=$(jot -w %i -r 1 1 $MAX_SIZE)
		y=$(jot -w %i -r 1 1 $MAX_SIZE)
		density=$DENSITY
		./gen_map $x $y $density
	done
elif [ $# -eq 3 ]
then
	./gen_map $1 $2 $3 | tee "$1_$2_$3.map"
	# ./gen_map $1 $2 $3
fi
