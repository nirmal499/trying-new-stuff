#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./for_control.sh
###################################################

# Generate a random number from 1-10
random_number=$(( ( RANDOM % 10 ) + 1 ))

# Iterate over all possible random numbers
for number in {1..10}; do
    if [[ ${number} -eq ${random_number} ]]; then
        echo "Random number found: ${number}"
        break
    fi
    # If we get here it means that number did not match
    echo "Number does not match: ${number}"
done

echo "Number has been found, all done"

