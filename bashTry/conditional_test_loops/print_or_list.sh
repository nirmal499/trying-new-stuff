#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./print_or_list.sh <file or directory path>
###################################################

# Since we're dealing with paths, set current working directory.
cd $(dirname $0)

# Input validation.
if [[ $# -ne 1 ]]; then
    echo "Incorrect usage!"
    echo "Usage: $0 <file or directory path>"
    exit 1
fi

input_path=$1

# First, check if we can read the file or access the directory
if [[ -r ${input_path} ]]; then
    # We can read the file or access the directory, now we can determine what type it is
    # If the argument given by the user is a file then print its content
    if [[ -f ${input_path} ]]; then
        echo "File found, showing content:"
        cat ${input_path} || {
            echo "Cannot print file, exiting script!"; exit 1; 
        }
    # If the argument given by the user is a directory then list the directory
    elif [[ -d ${input_path} ]]; then
        echo "Directory found, listing:"
        ls -l ${input_path} || {
            echo "Cannot list directory, exiting script!"; exit 1;
        }
    else
        echo "Path is neither a file nor a directory, exiting script."
        exit 1
    fi
else
    # We cannot read the file or not have access to the directory, print error
    echo "Cannot read the file/directory, exiting script."
    exit 1
fi