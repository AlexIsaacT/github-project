#!/bin/bash
#
cd $1
for file in * ; do
	if [ -f ../$2/$file ] ; then
		cmp $file ../$2/$file > /dev/null && rm ../$2/$file
	fi
done
