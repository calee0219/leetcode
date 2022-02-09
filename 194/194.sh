#!/usr/bin/env bash

FILE='file.txt'

#awk '{ print NR NF }' $FILE

awk '{ for (i=1; i <= NF; ++i) m[i, NR] = $i }
END { for (i = 1; i <= NF; ++i) { for (j = 1; j <= NR; ++j) { printf m[i, j]; if (j != NR) printf " "} print "" } }' $FILE

num_col=`head -n1 $FILE | wc -w` # count how many column on first line (head -n1)

for i in $(seq 1 $num_col)
do
    echo `cut -d' ' -f$i $FILE` # for each column(field), print out and seperate with ' '
done
