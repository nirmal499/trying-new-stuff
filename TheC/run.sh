file_name=`basename ${1}`
gcc -Wall ${1}.c -o bin/${file_name}.out && ./bin/${file_name}.out ${@:2}