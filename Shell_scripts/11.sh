#!/bin/bash
for file in *.c ; do
	grep "printf" $file > /dev/null
	if [ $? == 0 ] ; then
		grep "#include <stdio.h>" $file > /dev/null
		if [ $? != 0 ] ; then
			sed '1i #include <stdio.h>' $file
		fi
	fi
done







