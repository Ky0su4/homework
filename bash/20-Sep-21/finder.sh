#!/bin/bash
current=0

while [ "$($(python -c "$current*$current") | grep ".*269696")" != "0" ]; do
    current="$(( $current+1 ))"
done

echo "$current"