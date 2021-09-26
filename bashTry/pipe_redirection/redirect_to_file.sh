#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./redirect_to_file.sh
###################################################

source ../function/library/bash_lib_func.sh

# Set the current working directory
set_cwd

read -p "Type anything you like: " input

# It is same as 1>> sample_file.txt
echo ${input} >> sample_file.txt