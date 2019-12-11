#!/bin/bash
#
r=5
while [ $r != 0 ] ; do
       echo "`ps`"
       sleep 5
       r=`expr $r - 1`
done      
