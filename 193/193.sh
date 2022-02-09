#!/usr/bin/env bash
# One line script

egrep '(^[0-9]{3}-[0-9]{3}-[0-9]{4}$)' file.txt
echo
egrep '(^\([0-9]{3}\)\ [0-9]{3}\-[0-9]{4}$)' file.txt
echo
egrep '(^\([0-9]{3}\)\ [0-9]{3}\-[0-9]{4}$)|(^[0-9]{3}-[0-9]{3}-[0-9]{4}$)' file.txt
