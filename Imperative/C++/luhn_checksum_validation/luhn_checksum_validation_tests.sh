#!/bin/bash

: '

The following are 100 tests for the

Luhn checksum validation algorithm

you made.'

cd /Users/tanveersalim/Desktop/Git/EPI/EPI/Imperative/C++/luhn_checksum_validation

PATH_TO_CHECKSUM=/Users/tanveersalim/Desktop/Git/EPI/EPI/Imperative/C++/luhn_checksum_validation

PATH_TO_TESTS=~/Desktop/Tests/luhn_checksum_validation/

echo "" > $PATH_TO_TESTS/luhn_checksum_validation_tests.results

lines=$(wc -l < $PATH_TO_TESTS/luhn_checksum_validation_tests.txt)

((lines++))

c=1

while [ $c -lt $lines ]
	do
		sed -n "$c"p $PATH_TO_TESTS/luhn_checksum_validation_tests.txt >> $PATH_TO_TESTS/luhn_checksum_validation_tests.results

		sed -n "$c"p $PATH_TO_TESTS/luhn_checksum_validation_tests.txt | ./luhn_checksum_validation.out >> $PATH_TO_TESTS/luhn_checksum_validation_tests.results

	((c++))

	done
