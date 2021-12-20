#!/bin/bash

A() {
  if [[ $1 = 0 ]]; then
    echo $(($2+1))
  elif [[ $2 == 0 ]]; then
    echo "$(A $(($1-1)) 1)"
  else
    echo "$(A $(($1-1)) "$(A $1 $(($2-1)))")"
  fi
}

echo "$(A $1 $2)"
