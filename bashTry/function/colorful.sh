#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./colorful.sh
###################################################

print_colored(){
    # Check if the functions was called with correct arguments
    if [[ $# -ne 2 ]]; then
        echo "print_colored needs two arguments, exiting."
        exit 1
    fi

    # Grab both arguments passed to the function print_colored()
    local string=$1
    local color=$2

    case ${color} in
    red)
        local color_code="\e[31m";;
    blue)
        local color_code="\e[34m";;
    green)
        local color_code="\e[32m";;
    *)
        local color_code="\e[39m";; # Wrong color, use default
    esac

    # Perform the echo, and reset color to default with 
    echo -e ${color_code}${string}"\e[39m <= Printed"
}

# Print text in different colors
print_colored "Hello World!" "red"
print_colored "Hello World!" "blue"
print_colored "Hello World!" "green"
print_colored "Hello World!" "magenta"

