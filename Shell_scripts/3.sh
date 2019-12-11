#!/bin/bash
#
case "$1" in
	lm) echo "`ls -lt`" ;;
	la) echo "`ls -lut`" ;;
	*) echo "`ls -l`"
esac
