#!/bin/bash
#
. mainfunc.sh

user=`valid_string "Enter your user-id :" 16`
stty -echo
password=`valid_string "Enter your password:" 5`
stty echo
echo -e "\nYour user-id is $user and your password is $password"

