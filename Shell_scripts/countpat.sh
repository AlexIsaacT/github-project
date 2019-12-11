#!/bin/bash
#
exec > $2
exec 3> $3
exec 4> $4

[ $# -ne 4 ] && { echo "4 arguments required" ; exit 2 ; }

exec < $1
while read pattern ; do
	case "$pattern" in
		????) grep $pattern empn ||
			echo $pattern not found in file 1>&3 ;;
 	           *) echo $pattern not a four-character string 1>&4 ;;
	   esac
   done
   exec > /dev/tty
   echo Job Over
