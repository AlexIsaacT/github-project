#!/bin/bash
#
       if  [ $# -eq 2 ] ;then 
           x=$1
           y=$2
             echo "The sum of two numbers is `expr $x + $y`"
       else
	       echo "Enter two arguments"
       fi
