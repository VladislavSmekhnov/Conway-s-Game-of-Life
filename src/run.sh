#!/bin/bash
PS4='LINENO:'

work_dir=$(pwd)
field_samples=$work_dir/field_samples
input_list=$(ls $field_samples)
echo "Input file list:"
echo "$input_list"
read -p "Choose your variant of input .txt file (from $field_samples): " file_name
if [[ -f "$field_samples/$file_name" ]]
then
    if [ "${file_name: -4}" == ".txt" ]
    then
        if [[ -f "$work_dir/conways_game_of_life" ]]
        then
            ./conways_game_of_life < $field_samples/$file_name
            exit 0
        else
            >&2 echo "There is no file $work_dir/conways_game_of_life !"
            echo "Please create it by running in $work_dir command: make build"
            exit 3
        fi
    else
        >&2 echo "This file doesn't have an extension .txt !"
        exit 2
    fi
else
    >&2 echo "There is no file $file_name in $field_samples/"
    exit 1
fi