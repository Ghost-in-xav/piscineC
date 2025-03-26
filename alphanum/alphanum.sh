#!/bin/sh

while IFS='' read -r expression;
do
  if echo "$expression" | grep -q '^[a-zA-Z]\+$'; then
      echo "it is a word"

  elif echo "$expression" | grep -q '^[0-9]$'; then
        echo "it is a digit"

  elif echo "$expression" | grep -q '^[0-9]\+$'; then
      echo "it is a number"

  elif echo "$expression" | grep -q '^[A-Za-z0-9]\+$'; then
      echo "it is an alphanum"

  elif [ -z "$expression" ] ; then
          echo "it is empty"

  elif  echo -z "$expression" |grep -q '[^a-zA-Z0-9]\+[[:space:]]\+$';then
      echo "it is empty"
      
  else
     echo "it is too complicated"
     exit 0
  fi

done
