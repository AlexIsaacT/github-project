#!/bin/bash
# emp6.sh -- Using a for loop with positional parameters
#
for pattern in "$@" ; do
	grep "$pattern" emp || echo "Pattern $pattern not found"
done
