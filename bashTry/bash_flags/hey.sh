#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./hey.sh [flags]
###################################################

print_help(){
    echo "Usage: $0 [flags]"
    echo "Flags:"
    echo "-h for help."
    echo "-b for male greeting."
    echo "-g for female greeting."
}

# Parse the flags
optstring=":bgh"
while getopts ${optstring} options; do
    case ${options} in
        b)
            gender="boy"
            ;;
        g)
            gender="girl"
            ;;
        h)
            print_help
            exit 0 # Stop the script but consider it a success
            ;;
        ?)
            echo "INVALID option: -${OPTARG}."
            exit 1
            ;;
    esac
done

# If $gender is n (nonzero), print specific greeting.
# Otherwise, print a neutral greeting.
if [[ -n ${gender} ]]; then
    echo "Hey ${gender}!"
else
    echo "Hey there!"
fi
