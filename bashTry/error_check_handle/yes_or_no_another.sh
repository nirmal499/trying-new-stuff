#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./yes_or_no_another
###################################################

source ../function/library/bash_lib_func.sh

read -p "Do you like the question? " reply_variable

check_yes_no ${reply_variable} && \
echo "Great, I worked really hard on it!" || \
echo "You did not? But I worked so hard on it!"

# If check_yes_no returns an exit status of 0 (when a yes is found), the command
# after && is executed. Since that echoes the success, and echo has an exit code of
# 0, the failure echo after the next || is not executed.

# If check_yes_no returns an exit status of 1 (when a no is found), the command
# after && is not executed. However, it continues until it reaches ||, which goes on
# to the failure echo since the return code was still not 0.

# e.g:
# $ grep 'std' std.c && echo "Fine" || echo "Not Fine"
# grep: std.c: No such file or directory
# Not Fine

