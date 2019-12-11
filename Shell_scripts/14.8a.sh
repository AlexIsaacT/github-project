#!/bin/bash
# Using expr process the string
#
echo -e "Enter a string : \c"
read string
  if [ `expr "$string" : '.*'` -lt 10 ] ; then
	  echo "The string should have atleast 10 characters"

  fi
