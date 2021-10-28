#!/usr/bin/bash
###################################################
# To run : ./run.sh <file_name_without_extension>
# e.g ./run.sh mod1/RandomAverage 
####################################################
class_path="class_files"
command1="javac ${1}.java -d ${class_path}"
command2="java -classpath ${class_path} ${1}"

${command1} && ${command2}

# rm **/*
# Open VScode [ Taking root directory as src means $code src/] beoz of the
# package system of java
