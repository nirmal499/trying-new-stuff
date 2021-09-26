#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./sqaure_number.sh <number>
###################################################

INPUT_NUMBER=$1

# Check the no.of arguments
if [[ $# -ne 1 ]]; then
    echo "Incorrect usage, wrong number of arguments."
    echo "Usage: $0 <number>"
    exit 1
fi

# Check to see if the input is a number
if [[ ! ${INPUT_NUMBER} =~ ^[[:digit:]]+$ ]]; then
    echo "Incorrect usage, wrong type of argument."
    echo "Usage: $0 <number>"
    exit 1
fi

echo $(( ${INPUT_NUMBER} * ${INPUT_NUMBER} ))

