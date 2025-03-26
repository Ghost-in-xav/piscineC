#!/bin/sh

if [ $# -lt 1 ];then
    echo "Sorry, expected 1 argument but 0 were passed"
    exit 1
fi
if [ $# -gt 1 ];then
    echo "Sorry, expected 1 argument but $# were passed"
    exit 1
fi
if [ -f $1 ];then
    cat $1
else
    echo "$1:"
    echo "\tis not a valid file"
    exit 2
fi


   ##FI




 
