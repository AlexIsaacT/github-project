#!/bin/bash
#script.sh: Sample shell script
echo "Today's date: `date`"
echo "This month's calendar:"
cal `date "+%m 20%y"`
echo "My shell: $SHELL"

