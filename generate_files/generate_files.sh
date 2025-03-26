#!/bin/sh

FILENAME=default
NUMBER=1
EXTENSION=txt

while [ $# -gt 0 ];
do
    case $1 in
	--filename) FILENAME=$2;shift 2;;
	--number) NUMBER=$2;shift 2;;
	--extension) EXTENSION=$2;shift 2;;
	-f) FILENAME=$2;shift 2;;
	-n) NUMBER=$2; shift 2;;
	-e) EXTENSION=$2; shift 2;;
	*) exit 1;;
    esac
done
    
    
until [ $NUMBER -lt 1 ];
do
    touch -- "$FILENAME-$NUMBER.$EXTENSION"
    NUMBER=$(($NUMBER -1))
done


	
	
	    
	
