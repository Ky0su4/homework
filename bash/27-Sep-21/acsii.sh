#!/bin/bash
# https://stackoverflow.com/questions/35263929/how-to-iterate-through-each-letter-in-a-string-in-unix-shell

for (( i = 33; i < 256; i++ )); do
    echo "[$i] $(printf "\\$(printf '%03o' "$i")")"
done