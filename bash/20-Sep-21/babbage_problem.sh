#!/bin/bash
current=0

while [[ ! $((current**2)) =~ ^.*269696  ]]; do
    current=$((current+1))
done

echo $((current**2))