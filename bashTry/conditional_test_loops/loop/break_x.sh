#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./break_x.sh
###################################################

while true; do
    echo "This is the outer loop."
    sleep 1

    for iteration in {1..3}; do
        echo "This is inner loop ${iteration}"
        
        if [[ ${iteration} -eq 2 ]]; then
            break 1
            # break 2 # Break out of the outer while true loop
        else
            sleep 1
        fi
    done
done

echo "End of the script"