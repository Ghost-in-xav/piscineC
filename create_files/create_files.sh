#!/bin/sh

touch ' '
chmod 0644 ' '
touch '\'
chmod 0644 '\'
touch -- '--'
chmod 0644 -- '--'
touch '|'
chmod 0644 '|'
touch '"'
chmod 0644 '"'
touch -- "'"
chmod 0644 -- "'"
touch -- "--\$i*'\"\\"
chmod 0644 -- "--\$i*'\"\\"
touch "# Exams are fun!"
chmod 0644 "# Exams are fun!"
touch ";\`kill -9 0\`"
chmod 0644  ";\`kill -9 0\`"
i=1
until [ $i -gt 50 ]
do
    mkdir $i
    chmod 0644 $i
    cd $i
    i=$(($i+1))
done
touch farfaraway
chmod 0644 farfaraway

