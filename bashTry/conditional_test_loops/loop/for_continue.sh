#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./for_continue.sh
###################################################

for number in {1..20..2}; do
    if [[ $(( ${number} % 5 )) -eq 0 ]]; then
        continue # Unlucky number, skip this
    fi

    # Show the user which number we've processed
    echo "Looking at number: ${number}"
done