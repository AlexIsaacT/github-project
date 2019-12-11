#!/bin/bash
#
x=`ls -i $1 | cut -d " " -f 1`
find /home -inum $x -print
