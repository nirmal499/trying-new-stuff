#!/usr/bin/bash

########################################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./yes_or_no.sh
########################################################################

read -p "Do you like the question? " reply_variable

# In this all kinds of yes is covered
if [[ ${reply_variable,,} = 'y' || ${reply_variable,,} = 'yes' ]]; then
    echo "Great, I have worked really hard on it."
    exit 0
fi

# In this all kinds of no is covered
if [[ ${reply_variable^^} = 'N' || ${reply_variable^^} = 'NO' ]]; then
    echo "You did not! But I worked so hard."
    exit 0
fi

# If we get here , it means that the user did not give a proper response
echo "Please use yes/no"
exit 1

