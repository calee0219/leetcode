#!/usr/bin/env bash

FILE='file.txt'

sed -n 10p $FILE
echo
tail +10 $FILE | head -1
echo
awk 'NR == 10' $FILE
