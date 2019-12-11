#!/bin/bash
# emp1.sh: Interactive version - uses read to take two inputs
#
echo -e "Enter the pattern to be searched: \c"
read pname
echo -e "Enter the file to be used: \c"
read flname
echo "Searching for $pname from file $flname"
grep "$pname" $flname
echo "Selected records shown above"
