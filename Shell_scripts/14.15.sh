#!/bin/bash
#
for file in "$@" ; do
	if [ -f $file ] ; then
		file2=`echo $file | tr 'a-z' 'A-Z'`
		if [ -f $file2 ] ; then
			echo "File already exists"
		else
			mv $file $file2
		fi
	else
		echo "File doesn't exists"
	fi
done
