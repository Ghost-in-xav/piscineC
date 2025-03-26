#!/bin/sh

if [ $# -ne 3 ]; then
  echo "Usage: ./seq.sh FIRST INCREMENT LAST" >&2
  exit 1
fi

if [ "$2" -eq 0 ];then
  exit 1
fi

if [ "$1" -eq "$3" ];then
  echo "$1"
  exit 0
fi

TEMP="$1"

if [ "$1" -lt "$3" ];then
  if [ "$2" -le 0 ]; then
      exit 1
  else
    while [ "$TEMP" -lt "$3" ];do
      echo "$TEMP"
      TEMP=$((TEMP + $2))
    done
    if [ "$TEMP" -eq "$3" ]; then
      echo "$TEMP"
    fi
  fi
fi

if [ "$1" -gt "$3" ]; then
    if [ "$2" -ge 0 ]; then
        exit 1
    else
        while [ "$TEMP" -gt "$3" ];do
            echo "$TEMP"
            TEMP=$((TEMP+$2))
        done
        if [ "$TEMP" -eq "$3" ]; then
            echo "$TEMP"
        fi
    fi
fi

exit 0