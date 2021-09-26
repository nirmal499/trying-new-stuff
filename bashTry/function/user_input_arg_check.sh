#!/usr/bin/bash

#################################################################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./user_input_arg_check.sh <argument1> <argument2>
#################################################################################################

source ./library/bash_lib_func.sh

# Check user input [Only two arguments are needed]
# We use the predefined function to check if the number of arguments is correct.
check_arguments 2 "$@" || \
{ echo "Incorrect usage! Usage: $0 <argument1> <argument2>"; exit 1; }
# Note: Use double quotes around $@ to prevent word splitting


echo "Your arguments are: $1 and $2"