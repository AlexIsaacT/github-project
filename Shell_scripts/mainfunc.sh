ll() {
	ls -l $* | more
}

dated_fname() {
	set -- `date`
	year=`expr $6 : '..\(..\)'`
	echo "$2$3_$year"
}

anymore() {
	echo -e "\n$1 ?(y/n) : \c" 1>&2
	read response
	case "$response" in
		y|Y) echo 1>&2 ; return 0 ;;
		  *) return 1 ;;
	  esac
  }

valid_string() {
	while echo -e "$1 \c" 1>&2 ; do
		read name
		case $name in
			"") echo "Nothing entered" 1>&2 ; continue ;;
			 *) if [ `expr "$name" : '.*'` -gt $2 ] ; then
				 echo "Maximum $2 characters permitted" 1>&2
			 else
				 break
			 fi ;;
	 esac
 done
 echo $name
 }


