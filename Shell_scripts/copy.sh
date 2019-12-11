#!/bin/bash
#
dir=`eval echo \$$#`;
i=0 ;
while [ 1 ] ; do
	if [ $i -le $# ] ; then
	arr[i]=$i 
      else
	  break ;
  fi
done
i=0 ;
for file in arr[i] ; do
	if [ -f $file ] ; then
	       cp $file $dir/
  fi	  
     i=i+1 ;
  done

