#!/bin/bash
word=$1
flag=true
for i in $(seq 1 $((${#word} / 2)))
do
  if [[ ! ${word:i-1:1} = ${word:${#word}-i:1} ]]; then
    flag=false
    break
  fi
done

if [[ $flag = true ]]; then
    echo "It is a palindrome"
else
  echo "It isn't a palindrome"
fi