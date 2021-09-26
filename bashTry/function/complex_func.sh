#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./complex_func.sh
###################################################

print_system_status(){
    date # Print the current datetime

    # "$(top -bn1 | awk '{print $2}')" gives same result
    echo "CPU in use: $(top -bn1 | grep Cpu | awk '{print $2}')"

    echo "Memory in use: $(free -h | grep Mem | awk '{print $3}')"
    echo "Disk space available on /: $(df -k / | grep / | awk '{print $4}')"
    echo # Extra newline for readability.
}

# Print the system status a few times
for ((i=0; i<5; i++)); do
    print_system_status
    sleep 5
done