#!/bin/bash
#
cd $2
for file in * ; do
	find ../$1 -name $file -print > store
       if [ ! -s store ] ; then
	       cp $file ../$1
	    
       else
	       continue
       fi
       done
       
	       
	    



