#!/usr/bin/bash

########################################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./file_create.sh <directory_name> <file_name> <file_content>
########################################################################

# We need exactly three arguments
if [[ $# -ne 3 ]]; then
    echo "Incorrect Usage!"
    echo "Usage: $0 <directory_name> <file_name> <file_content>"
    exit 1
fi

# Save the arguments into variables
directory_name=$1
file_name=$2
file_content=$3

# Create absolute path for the file
absolute_file_path=${directory_name}/${file_name}

# Create the directory if it does not exists
if [[ ! -d ${directory_name} ]]; then
    # exit code 0 -> everything is fine -> true
    # exit code other than 0 -> something is wrong -> false
    mkdir ${directory_name} || {
        echo "Cannot create directory, exiting script!"; exit 1;
    }
fi

# Create the file if it does not exists
if [[ ! -f ${absolute_file_path} ]]; then
    touch ${absolute_file_path} || {
        echo "Cannot create file, exiting script!"; exit 1;
    }
fi

# File has been created, echo the content to it
echo ${file_content} > ${absolute_file_path}