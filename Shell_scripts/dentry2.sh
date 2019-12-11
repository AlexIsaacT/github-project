#!/bin/bash
#
trap 'echo "Program interrupted"; exit' HUP INT TERM
. mainfunc.sh
prompt1="Employee id : " ; prompt2="Name : " ; prompt3="Designation : "
prompt4="Department : " ; prompt5="Date of birth : " ; prompt6="Basic pay : "

flname=`valid_string "Enter the output filename: " 8`
while true ; do
	while [ ${x:=1} -le 6 ] ; do
		eval echo -e \$prompt$x '\\c' 1>&2
		read value$x
		rekord="${rekord}`eval echo -e \\$value$x`|"
		x=`expr $x + 1`
	done
	echo "$rekord"
	anymore "More entries to add" 1>&2 || break
done > $flname

