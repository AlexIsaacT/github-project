#!/bin/bash
#
pattern="$1"
set -- `grep -lr "$pattern" *`
[ $# -gt 0 ] && vi +/"pattern" "$@" || echo "Pattern not found"

