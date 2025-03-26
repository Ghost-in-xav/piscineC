#!/bin/sh

if [ $# -lt 1 ];then
    rm -r *.txt
else
    rm -r *.$1
fi



