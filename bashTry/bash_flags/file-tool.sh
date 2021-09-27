#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./file_tool.sh -f <file_name> [flags]
###################################################

print_help() {
    echo "Usage: $0 -f <file_name> [flags]"
    echo "flags:"
    echo "No flags for file listing."
    echo "-d to delete the file."
    echo "-e to empty the file."
    echo "-m <new_file_name> to rename the file."
    echo "-h for help."
}

# Check if there are correct no.of arguments
if [[ $# -lt 2 ]]; then
    print_help
    exit 1
fi

command="ls -lh" # Default command if no flags given

optstring=":hdem:f:" # m option needs an argument
mflag=1 # flag indication for m

while getopts ${optstring} options; do
    case ${options} in
        f)
            file_name=${OPTARG}
            # Make sure the user supplied a file which is a writable file
            if [[ ! -w ${file_name} ]]; then
                echo "Supply a writable file to manipulate which exists! Exiting script."
                echo "You supplied: ${file_name} to -f"
                exit 1
            fi
            ;;
        m)
            new_file_name=${OPTARG}; command="mv"
            mflag=0
            ;;
        e)
            command="cp /dev/null";;
        d)
            command="rm -f";;
        h)
            print_help; exit 0;;
        :)
            echo "-${OPTARG} requires an argument."; exit 1;;
        ?)
            echo "Invalid option: -${OPTARG}."; exit 1;;
        *)
            print_help
            exit 1;;
    esac
done

# Remove the parsed flags from the arguments array
# shift $(( ${OPTIND} - 1 )) # -1 so that file_name is not shifted away

# Get the file_name
# filename=$1

# Make sure the user supplied a file and it must be a writable file
# if [[ $# -ne 1 || ! -w ${filename} ]]; then
#     echo "Supply a writable file to manipulate! Exiting script."
#     exit 1
# fi

# Everything should be fine, execute the operation.
if [[ ${mflag} -eq 0 ]]; then # Only set for -m.
    ${command} ${file_name} $(dirname ${file_name})/${new_file_name}
else # Everything besides -m.
    ${command} ${file_name}
fi


