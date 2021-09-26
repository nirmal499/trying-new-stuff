#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./error_function.sh
###################################################

# Define a function that handles minor errors.
handle_minor_error() {
    echo "A minor error has occured, please check the output."
}
# Define a function that handles fatal errors.
handle_fatal_error() {
    echo "A critical error has occured, stopping script."
    exit 1
}

# Minor failures.
ls -l /tmp/ || handle_minor_error
ls -l /root/ || handle_minor_error

# Fatal failures.
cat /etc/shadow || handle_fatal_error
cat /etc/passwd || handle_fatal_error