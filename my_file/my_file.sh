#!/bin/sh
for arg in "$@"
do
    if [ -d "$arg" ];then
	echo "$arg: directory"
    else
	if [ -f "$arg" ];then
	    echo "$arg: file"
	else
	    echo "$arg: unknown"
	fi
    fi
done

	
