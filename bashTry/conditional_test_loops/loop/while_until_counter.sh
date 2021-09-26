#!/usr/bin/bash

########################################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./while_until_counter.sh
########################################################################

counter=0

# This loop runs for 10 times
while [[ ${counter} -lt 10 ]]; do
    counter=$((counter+1)) # Increment counter by 1
    echo "Hello! This is loop number ${counter}"
    sleep 1
done

echo -e "WHILE is done\n"

# Reseting the counter
counter=0

# This loop runs for 10 times
until [[ ${counter} -gt 9 ]]; do
    counter=$((counter+1)) # Increment counter by 1
    echo "Hello, This is loop number ${counter}"
    sleep 1
done

echo -e "UNTIL is done\n"

