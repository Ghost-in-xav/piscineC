#!/bin/sh

if [ $# -eq 1 ];then
    echo $(($1))
else
    while read x
    do
	echo $(($x))
        
    done
fi
