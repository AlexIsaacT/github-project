#!/bin/sh
# comc.sh: Script that is called by different names
#
lastfile=`ls -lt *.c | cut -d " " -f 9` | head -n 1
command=$0
executable=./`expr $lastfile : '\(.*\).c'`
case $command in
	*runc) $executable ;;
	*vic) vi $lastfile ;;
	*comc) cc -o $executable $lastfile &&
		echo "$lastfile compiled succesfully" ;;
esac

