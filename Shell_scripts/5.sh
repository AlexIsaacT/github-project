#!/bin/bash
#
if [ $# -eq 0 ] ; then
         for file in *.c ; do
		 echo "`cat $file | head -n 10`"
		 echo -e "Do you want to delete the file (Y/N) : \c"
		 read option
		 case "$option" in
			 [Yy] ) rm $file ;;
			 [Nn] ) continue ;;
		 esac

    done
    else
	    for file in "$@" ; do
		    echo "`cat $file | head -n 10`"
		    echo -e "Do you want to delete the file ((Y/N) : \c"
		    read option
		    case "$option" in
			    [Yy] ) rm $file ;;
			    [Nn] ) continue ;;
		    esac
	    done
	   fi


		 
