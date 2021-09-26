#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./for_simple.sh
###################################################

words="house dog telephone dog"

for word in ${words}; do
    echo "The word is: ${word}"
done

echo -e "All done\n"

# This loop runs 5 times
for ((counter=1; counter<=5; counter++)); do
    echo "Hello, This is a loop number ${counter}";
    sleep 1
done

echo -e "All done\n"

# This loop runs 5 times
for counter in {1..5}; do
    echo "Hello, This is a loop number ${counter}";
    sleep 1
done

echo -e "All done\n"

# Infinite for loop
for ((;;)); do
    echo "Hello!"
    sleep 1
done

# This will never run
echo -e "Everything done\n"
