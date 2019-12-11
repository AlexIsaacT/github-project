#!/bin/bash
#emp3.sh: Using if and else
#
if grep "^$1" /etc/passwd 2>/dev/null
then
     echo "Pattern found - Job Over"
else
     echo "Pattern not found"
fi     
