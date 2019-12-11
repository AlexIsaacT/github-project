#!/bin/bash
#
oldifs=$IFS
IFS=:
set -- `echo $PATH`
for directory in "$@" ; do
	if [ ! -d $directory ] ; then
		echo "$directory doesn't exists"
	elif [ ! -x $directory ] ; then 
		echo "$directory is not accessible"
	fi
done
IFS=$oldifs
