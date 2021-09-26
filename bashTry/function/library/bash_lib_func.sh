#!/usr/bin/bash

#####################################################################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: source ~/Desktop/cpp_c_py_rust_js_dev/workshop/bashTry/function/library/bash_lib_func.sh
#####################################################################################################

# Check if the number of arguments supplied is exactly correct.
check_arguments() {
    # We need at least one argument.
    if [[ $# -lt 1 ]]; then
        echo "Less than 1 argument received, exiting."
        exit 1
    fi
    # Deal with arguments
    expected_arguments=$1
    shift 1 # Removes the first argument.

    # Check if the expected_arguments is not equal to the subsequent no.of arguments given
    # e.g check_arguments 2 "one" "two" "three" # Incorrect.
    # e.g check_arguments 1 "one two three" # Correct.
    if [[ ${expected_arguments} -ne $# ]]; then
        return 1 # Return exit status 1.
        # return is similar to exit, but it does not stop the script execution
    fi
}

# Set the current working directory to the script location.
set_cwd() {
    cd $(dirname $0)
}

# Checks if the argument is an integer.
check_integer() {

    # Input validation.
    if [[ $# -ne 1 ]]; then
        echo "Need exactly one argument, exiting."
        exit 1
    fi

    # Check if the input is an integer.
    if [[ $1 =~ ^[[:digit:]]+$ ]]; then
        return 0 # Is an integer.
    else
        return 1 # Is not an integer.
    fi
}

# Checks if the user answered yes or no.
check_yes_no() {

    # Function incorrectly called: exit 1
    # Function found a yes: return 0
    # Function found a no: return 1
    # Function found neither: exit 2

    # Input validation.
    if [[ $# -ne 1 ]]; then
        echo "Need exactly one argument, exiting."
        exit 1 # No validation done, exit script.
    fi

    # Return 0 for yes, 1 for no, exit 2 for neither.
    if [[ ${1,,} = 'y' || ${1,,} = 'yes' ]]; then
        return 0
    elif [[ ${1,,} = 'n' || ${1,,} = 'no' ]]; then
        return 1
    else
        echo "Neither yes or no, exiting."
        exit 2
    fi
}



