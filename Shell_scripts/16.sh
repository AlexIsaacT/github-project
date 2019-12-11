#!/bin/bash
#
list1=`who | cut -d " " -f 1`
while [ true ] ; do
sleep 60
list2=`who | cut -d " " -f 1`
set -- $list1
for file in "$@" ; do
	if [ grep "$file" $list2 ] ; then
		continue
	else
		echo "$file has logged out"
	fi
done
set -- $list2
for file in "$@" ; do
	if [ grep "$file" $list1 ] ; then 
		continue
	else
		echo "$file has logged in"
	fi
done
list1=$list2
done


