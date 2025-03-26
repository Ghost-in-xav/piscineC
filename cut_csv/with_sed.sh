#!/bin/sh

if [ $# -ne 2 ];then
  exit 1
fi

if [ ! -f "$1" ];then
  exit 1
fi

# Check if the second argument is a number
if [ -n "$2" ] && [ "$2" -eq "$2" ] 2>/dev/null; then
  if [ "$2" -lt 0 ]; then
      exit 1
  fi

  LIGNE=1
  RES1=""
  RES2=""

  while IFS='' read -r LINE; do
    if [ "$LIGNE" -eq "$2" ]; then
      RES1=$(echo "$LINE" | sed 's/;/\n/g' | sed -n '2p')
      RES2=$(echo "$LINE" | sed 's/;/\n/g' | sed -n '3p')
       if [ -z "$RES1" ] || [ -z "$RES2" ]; then
           exit 1
       else
          echo "$RES1 is $RES2"
          exit 0
      fi
    fi
    LIGNE=$((LIGNE + 1))
  done < "$1"

  if [ "$LIGNE" -lt "$2" ]; then
    exit 1
  fi
else
  exit 1
fi

exit 1