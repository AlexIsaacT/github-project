#!/bin/bash
# emp5.sh: Shows use of the while loop
#
answer=y
while [ "$answer" = "y" ]
do
	echo "Enter the code and description: \c:" > /dev/tty
	read code description
	echo "$code|$description" 
	echo "Enter any more (y/n)? \c" > /dev/tty
	read anymore
	case $anymore in
		y*|Y*) answer=y ;;
		n*|N*) answer=n ;;
		    *) answer=y ;;
	    esac
    done > newlist
