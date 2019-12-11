#!/bin/bash
# Accept filename as argument and displays last modification date
#
file=$1
if [ -f $file ] ; then
	set -- `ls -l $file`
	echo "The last modification time for the given file is $6 $7 $8"
else
	echo "File not found"
fi


