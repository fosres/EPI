#!/bin/bash

: '

The following is a script to 

execute 100 tests for the

Luhn checksum validation algorithm

you made.'


#Path to program, test script file, and output files
cd /Users/tanveersalim/Desktop/Git/EPI/EPI/Imperative/C++/luhn_checksum_validation

PATH_TO_PROGRAM=/Users/tanveersalim/Desktop/Git/EPI/EPI/Imperative/C++/luhn_checksum_validation

PATH_TO_TESTS=~/Desktop/Tests/luhn_checksum_validation/

: '

The below echo line is meant to delete all content

in luhn_checksum_validation_tests.results.

'
~/Desktop/Tests/./remove_comments_from_tests.out < $PATH_TO_TESTS/luhn_checksum_validation_tests.txt >> $PATH_TO_TESTS/uncommented_luhn_checksum_validation_tests.txt

touch $PATH_TO_TESTS/uncommented_luhn_checksum_validation_tests.txt

lines=$(wc -l < $PATH_TO_TESTS/uncommented_luhn_checksum_validation_tests.txt)

((lines++))

c=1

: '

The first "sed" line appends the input to the

.results file. The second "sed" line appends

the corresponding output directly beneath

the input.

'
touch $PATH_TO_TESTS/luhn_checksum_validation_tests.results


echo "" > $PATH_TO_TESTS/luhn_checksum_validation_tests.results


cd /Users/tanveersalim/Desktop/Git/EPI/EPI/Imperative/C++/luhn_checksum_validation

while [ $c -lt $lines ]
	do

		sed -n "$c"p $PATH_TO_TESTS/uncommented_luhn_checksum_validation_tests.txt >> $PATH_TO_TESTS/luhn_checksum_validation_tests.results

		sed -n "$c"p $PATH_TO_TESTS/uncommented_luhn_checksum_validation_tests.txt | ./luhn_checksum_validation.out >> $PATH_TO_TESTS/luhn_checksum_validation_tests.results

	((c++))

	done

rm $PATH_TO_TESTS/uncommented_luhn_checksum_validation_tests.txt
