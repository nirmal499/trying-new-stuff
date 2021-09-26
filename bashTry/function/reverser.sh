#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./reverser.sh <input-to-be-reversed>
###################################################

# Check if the user supplied one argument
if [[ $# -ne 1 ]]; then
    echo "Incorrect number of arguments!"
    echo "Usage: $0 <input-to-be-reversed>"
    exit 1
fi

user_input="_$1_"

reverser(){
    # Check if input is correctly passed.
    if [[ $# -ne 1 ]]; then
        echo "Supply one argument to reverser()!"
        # echo "Argument is : $# $@"
        exit 1
    fi

    # Return the reversed input to stdout (default for rev).
    rev <<< ${1}
}


# Capture the function output via command substitution.
reversed_input=$(reverser "${user_input}")
# Note in above line we are not doing => $(reverser ${user_input}) becoz
# it makes the arguments more than 1 to the reverser function
# e.g If user_input is "Hello Hi" then if we use $(reverser ${user_input}) then we will get $(reverser Hello Hi)
# and if we use $(reverser "${user_input}") then we will get $(reverser "Hello Hi")

# Show the reversed input to the user.
echo "Your reversed input is: ${reversed_input}"
