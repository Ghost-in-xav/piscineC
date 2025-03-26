#!/bin/sh

if [ $# -ne 1 ];then
    exit 1
fi
F=1
COMPT=1

while [ "$COMPT" -le "$1" ];
do
    F=$((F * COMPT))
    COMPT=$((COMPT + 1))
done

echo $F
