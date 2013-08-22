#! /usr/bin/sh

if [ $# -ne 1 ]; then
	echo "Usage: $0 FILENAME"; exit
fi

gawk '{ sum += $1 }; END { print sum }' $1
