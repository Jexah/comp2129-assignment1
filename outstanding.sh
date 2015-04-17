#! /usr/bin/env bash

i=0;\
paste -d- <(./checksum < $1 | cut -f 3 -d :) <(./checksum < $1 | cut -f 4,5,6,7 -d : | sed -r "s/,|:/ /g" | ./farecalc $2 $3 $4 $5) | while ((i++));read line; do if (cat <(echo $line "<0") | bc | grep "1" -q); then cat <(tail -n+$i $1 | head -n1) | cut -f 2 -d :; fi; done
