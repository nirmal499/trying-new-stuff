#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./single_flag.sh [flags]
###################################################

opstring=":v:"
while getopts ${opstring} options; do
    case ${options} in
        v)
            echo "-v was found"
            echo "-v option argument is: ${OPTARG}."
            ;;
        :)
            echo "-${OPTARG} requires an argument"
            exit 1
            ;;
        ?)
            echo "Invalid option: -${OPTARG}."
            exit 1
            ;;
    esac
done
