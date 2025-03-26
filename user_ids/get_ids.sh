#!/bin/sh

PRECEDENT=""

#il faut envoyer les lignes couper dans la boulce ici
cut -d ':' -f 3 "/etc/passwd" | sort -nr | while IFS='' read -r line;do
    if [ "$line" != "$PRECEDENT" ];then
      echo "$line"
      PRECEDENT="$line"
    fi
done
#au lieu de le faire la
