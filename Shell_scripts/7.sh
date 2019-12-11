#!/bin/bash
#
for file in * ; do
	filename=`expr "$file" : '.*\.' - 1`
	extension=`expr "$file" : '.*' - $filename `
	if [[ $filename -le 8 && $extension -le 3 ]] ; then
		continue
	else
		echo "$file" 
	fi
done
