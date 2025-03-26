#!/bin/sh

NOMBRE_CHAR=0;

if [ ! -f $1 ];then
    exit 1
fi

if [ $# -ne 1 ];then
    exit 1
fi

while IFS='' read -r line ;
do
    NOMBRE_CHAR=$(echo -n "$line" | wc -m )
    if [ $NOMBRE_CHAR -ge 80 ];then
       printf "%s\n" "$line"
    fi
done < $1
