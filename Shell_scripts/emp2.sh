#!/bin/bash
# emp2.sh: Non-interactive version - uses command line arguments
#
echo "Program: $0
The number of arguments specified is $#
The arguments are $*"
grep "$1" $2 || exit 2
echo "\nJob Over" 
