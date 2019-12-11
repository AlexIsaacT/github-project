#!/bin/bash
#
x=`find . -name $1 -print`
if [ -z "$x"  ] ; then
	echo "File not found"
fi
