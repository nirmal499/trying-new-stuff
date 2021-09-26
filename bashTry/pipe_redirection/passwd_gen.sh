#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./passwd_gen.sh [<length>]
###################################################

# Check for the correct no.of arguments
# if [[ $# -ne 1 ]]; then
#     echo "Wrong number of arguments!"
#     echo "Usage: $0 <length>"
#     exit 1
# fi

password_length=20

# Check if length is given by the user (since it is optional)
if [[ $# -ne 0 ]]; then
    # Since length is given so, use that instead of default
    # Verify if the length is a number or not
    if [[ ! $1 =~ ^[[:digit:]]+$ ]]; then
        echo "Please enter a length (number)."
        exit 1
    fi
    password_length=$1
fi

# tr grabs readable characters from input, deletes the rest.
# Input for tr comes from /dev/urandom, via input redirection.
random_passwd1=$(tr -dc 'a-zA-Z0-9' < /dev/urandom | head -c ${password_length})

# Default behavior for head when nothing is specified is 10 lines
random_passwd2=$(head /dev/random | tr -dc 'a-zA-Z0-9' | head -c ${password_length})

echo "Your random password1 is: ${random_passwd1}"
echo "Your random password2 is: ${random_passwd2}"

