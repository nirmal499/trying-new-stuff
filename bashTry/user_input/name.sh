#!/usr/bin/bash

###################################################
# Author: Nirmal
# Version: v1.0.0
# Date: 22.09.2001
# Description: Script for giving bash a try
# Usage: ./name.sh <character_name> <location> <food>
###################################################

# Grab Arguments
character_name=$1
location=$2
food=$3

# Prompt the user for information, if it was not passed as arguments
if test -z ${character_name}; then read -p "Name a fictional character: " character_name; fi
if test -z ${location}; then read -p "Name an actual location: " location; fi
if test -z ${food}; then read -p "What's your favorite food: " food; fi

# Compose a story
echo "Recently, ${character_name} was seen in ${location} eating ${food}!"



