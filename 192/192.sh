#!/usr/bin/env bash

sed 's/\s\+/\n/g' words.txt | sort | sed -r '/^\s*$/d' | awk '{if ($1 != w) { if (NR != 1) {print w" "wc} w = $1; wc=1} else {wc++}} END {print w" "wc}' | sort -r -k 2 -n

cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r -n | awk '{print $2, $1}'
