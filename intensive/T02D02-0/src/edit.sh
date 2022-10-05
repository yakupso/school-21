#!/bin/bash
# Init 
path_to_file=$1
original_str=$2
replacement_str=$3

path_to_logs="files.log"

# Changing file
if [[ -n $path_to_file && $path_to_file == *.txt && -n $original_str && -n $replacement_str && -f $path_to_file && -e $path_to_file ]]
then
  extention=`sed 's/^\w\+.//' <<< "$path_to_file"`
  sed -i "" "s/$original_str/$replacement_str/g" $path_to_file
else
  echo 'Error!'
  exit 1
fi

# Write in src/files.log
size=$(stat -f%z $path_to_file)
sha_sum=$(shasum -a 256 $path_to_file | cut -d ' ' -f 1)
curr_date=$(date +'%Y-%m-%d %R')
echo "src/$path_to_file - $size - $curr_date - $sha_sum - sha256" >> $path_to_logs
exit 0
