#!/usr/bin/bash
flag1="--lib es6,dom"
flag2="--experimentalDecorators"
flag3="--target es2015"
flag4="--emitDecoratorMetadata"
tsc ${1}.ts ${flag1} ${flag2} ${flag3} ${flag4} && node ${1}.js
# This is not working for parameterDecorator