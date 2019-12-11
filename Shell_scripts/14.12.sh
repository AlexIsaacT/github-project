#!/bin/bash
#
case "$1" in
	*.gz) command=gunzip ; name=`basename $1 .gz` ;;
	*.bz) command=bunzip ; name=`basename $1 .bz` ;;
	*.zip) command=zip ; name=`basename $1 .zip` ;;
esac
if [ -f $name ] ; then
	echo "Uncompressed file exists"
else
	$command $1
fi


