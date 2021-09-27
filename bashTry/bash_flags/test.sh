new_file_name=$1
if [[ ! ${new_file_name} =~ '^[\w\- ]+[\w\-. ]*$' ]]; then
    echo "Not a Proper Rename: ${new_file_name}"
    exit 1
fi