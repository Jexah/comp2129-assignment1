#! /usr/bin/env bash

clang -std=c11 -Wall checksum.c -o checksum
clang -std=c11 -Wall farecalc.c -o farecalc

cp balance.sh balance
cp outstanding.sh outstanding

chmod 700 checksum farecalc balance outstanding
