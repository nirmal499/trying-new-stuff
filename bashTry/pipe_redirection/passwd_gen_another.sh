#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./passwd_gen_another <length>
###################################################


source ../function/library/bash_lib_func.sh

# Check for the correct number of arguments.
check_arguments 1 "$@" || \
{ echo "Incorrect usage! Usage: $0 <length>"; exit 1; }

# Verify the length argument.
check_integer $1 || { echo "Argument must be an integer!"; exit 1; }

# tr grabs readable characters from input, deletes the rest.
# Input for tr comes from /dev/urandom, via input redirection.
# echo makes sure a newline is printed.
tr -dc 'a-zA-Z0-9' < /dev/urandom | head -c $1
echo