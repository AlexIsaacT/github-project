#!/bin/bash
#i
printf "Permissions\tsize   filename Last mod. time  Last access time\n"
for file in "$@" ; do
	echo "`ls -l $file`" >> temp
	echo "`ls -lut $file`" >> access
done
       
 


