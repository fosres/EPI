#!/bin/bash

: '

The following is a script to 

execute 100 tests for the

Luhn checksum validation algorithm

you made.'


#Path to program, test script file, and output files

NAME=luhn_checksum_validation # Enter the name of program here WITHOUT .ext indicating program type

PATH_TO_PROGRAM=/Users/tanveersalim/Desktop/Git/EPI/EPI/Imperative/C++/$NAME

REMOVE_COMMENTS=~/Desktop/Tests/./remove_comments_from_tests

cd $PATH_TO_PROGRAM

PATH_TO_TESTS=~/Desktop/Tests/$NAME/

: '

The below echo line is meant to delete all content

in "$NAME"_tests.results.

'

touch $PATH_TO_TESTS/uncommented_"$NAME"_tests.txt

$REMOVE_COMMENTS.out < $PATH_TO_TESTS/"$NAME"_tests.txt >> $PATH_TO_TESTS/uncommented_"$NAME"_tests.txt

lines=$(wc -l < $PATH_TO_TESTS/uncommented_"$NAME"_tests.txt)

((lines++))

c=1

: '

The first "sed" line appends the input to the

.results file. The second "sed" line appends

the corresponding output directly beneath

the input.

'
touch $PATH_TO_TESTS/"$NAME"_tests.results


echo "" > $PATH_TO_TESTS/"$NAME"_tests.results


cd /Users/tanveersalim/Desktop/Git/EPI/EPI/Imperative/C++/$NAME

while [ $c -lt $lines ]
	do

		sed -n "$c"p $PATH_TO_TESTS/uncommented_"$NAME"_tests.txt >> $PATH_TO_TESTS/"$NAME"_tests.results

		sed -n "$c"p $PATH_TO_TESTS/uncommented_"$NAME"_tests.txt | ./$NAME.out >> $PATH_TO_TESTS/"$NAME"_tests.results

	((c++))

	done

rm $PATH_TO_TESTS/uncommented_"$NAME"_tests.txt
