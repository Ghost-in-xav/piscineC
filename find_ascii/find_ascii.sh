#!/bin/sh

for fichier in "$1"/*; do
   file "$fichier" | grep ASCII -;
    
done
