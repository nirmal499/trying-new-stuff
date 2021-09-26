#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./for_globbing.sh
###################################################


# Create a directory to store log files with errors
ERROR_DIRECTORY="${HOME}/Desktop/cpp_c_py_rust_js_dev/workshop/bashTry/extra/error_logfiles/"
mkdir -p ${ERROR_DIRECTORY}

# Create a list of log files
for file in $(ls /var/log/*.log); do

    # Check if we have access to the file
    if [[ -r ${file} ]]; then

        # Here the file is basically kind of like this -> /var/log/bootstrap.log , /var/log/dpkg.log ...
        grep --quiet -i 'error' ${file}

        # Check the return code for grep; if it is 0, file contains errors
        if [[ $? -eq 0 ]]; then
            echo "${file} contains error(s) , copying to archive ${ERROR_DIRECTORY}."
            
            cp ${file} ${ERROR_DIRECTORY} # Archive the file to another directory.

            # Create the new file location variable with the directory and basename of the file
            file_new_location="${ERROR_DIRECTORY}$(basename ${file})"

            # In-place EDIT, only print lines matching 'error' or 'Error'
            sed --quiet --in-place '/[Ee]rror/p' ${file_new_location}
        fi
    else
        # We cannot read the file print error since we do not have access to the file
        echo "Cannot read the file => ${file}" 
    fi
done
