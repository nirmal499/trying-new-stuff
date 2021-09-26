#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./argument_checker.sh
###################################################

source ./library/check_argument.sh

check_arguments 3 "one" "two" "three" # Correct.
echo "Result $?"
check_arguments 2 "one" "two" "three" # Incorrect.
echo "Result $?"
check_arguments 1 "one two three" # Correct.
echo "Result $?"
