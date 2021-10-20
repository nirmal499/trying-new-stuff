#!/usr/bin/bash
#########################################################################################
# To run : ./run.sh <file_name_without_extension> <way[either_1[Default]_or_anyNumber]>
#########################################################################################
# flag1="--lib es6,dom"
# flag1="--lib es2018,dom"
flag1="--lib es2020,dom"
flag2="--experimentalDecorators"
flag3="--target es2015"
flag4="--emitDecoratorMetadata"

defaultWayValue=1
way=${2:-${defaultWayValue}}

if [[ ${way} == 1 ]]; then
    tsc ${1}.ts ${flag1} ${flag2} ${flag3} ${flag4} && node ${1}.js
else
    tsc ${1}.ts ${flag1} ${flag2} ${flag3} ${flag4}
fi

# This is not working for parameterDecorator