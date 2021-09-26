#!/usr/bin/bash

########################################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./while_interactive.sh
########################################################################

while true; do
    read -p "I have keys but no locks. I have a space but no room. You can enter but can't go outside. What am I? : " answer
    if [[ ${answer} =~ [kK]eyboard ]]; then # Matches for both keyboard and Keyboard
        echo "Correct, Congratulations!"
        #exit 0
        break # Exit the while loop
    else
        echo "Incorrect, Please try again"
    fi
done

echo "Thank You. Hoped You struggled... a lot to find the answer"