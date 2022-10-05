#!/bin/bash
# Init
path_to_logs=$1


if [[ -n $path_to_logs && -f $path_to_logs && -e $path_to_logs ]]
then
    # Record count (done)
    record_count=$(wc -l $path_to_logs | cut -d' ' -f8)

    # Num of unic files (done)
    num_of_unic_files=$(sort $path_to_logs | awk 'BEGIN {FS=" - "} ; {print $1 }' | uniq -ud | wc -l)

    # Num of ...
    num_of_changes=$(sort $path_to_logs | awk 'BEGIN {FS=" - "} ; {print $4 }' | uniq -ud | wc -l)
    # echo $(sort $path_to_logs | awk 'BEGIN {FS=" - "} ; {print $4 }' | uniq -ud)
    echo $record_count $num_of_unic_files $num_of_changes
else
    echo 'Error!'
    exit 1
fi
