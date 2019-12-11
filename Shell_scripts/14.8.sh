#!/bin/bash
# To accept a string from the terminal
#
echo -e "Enter the string : \c"
read string
case "$string" in
	??????????*) ;;
		*) echo "String should have atleast 10 characters"
esac

