#!/bin/bash

: '

The following is a script to 

execute 100 tests for the

Luhn checksum validation algorithm

you made.'


#NAME of program, test script file, and output files

# DO NOT CHANGE REMOVE_COMMENTS, that is where the file is located

NAME=selection_sort # Enter the name of program here WITHOUT .ext indicating program type

PATH_TO_PROGRAM_DIRECTORY=/Users/tanveersalim/Desktop/Tests/"$NAME"

REMOVE_COMMENTS=~/Desktop/Tests/./remove_comments_from_tests

cd $PATH_TO_PROGRAM_DIRECTORY

g++ "$NAME".cpp -o "$NAME".out

PATH_TO_TESTS_DIRECTORY=~/Desktop/Tests/"$NAME"/

: '

The below echo line is meant to delete all content

in "$NAME"_tests.results.

'

touch $PATH_TO_TESTS_DIRECTORY/uncommented_"$NAME"_tests.txt

$REMOVE_COMMENTS.out < $PATH_TO_TESTS_DIRECTORY/"$NAME"_tests.txt >> $PATH_TO_TESTS_DIRECTORY/uncommented_"$NAME"_tests.txt

lines=$(wc -l < $PATH_TO_TESTS_DIRECTORY/uncommented_"$NAME"_tests.txt)

((lines++))

c=1

: '

The first "sed" line appends the input to the

.results file. The second "sed" line appends

the corresponding output directly beneath

the input.

'
touch $PATH_TO_TESTS_DIRECTORY/"$NAME"_tests.results


echo "" > $PATH_TO_TESTS_DIRECTORY/"$NAME"_tests.results

# Enter PATH_TO_PROGRAM_DIRECTORY

cd $PATH_TO_PROGRAM_DIRECTORY

while [ $c -lt $lines ]
	do
		
		printf "\n" >> $PATH_TO_TESTS_DIRECTORY/"$NAME"_tests.results

		sed -n "$c"p $PATH_TO_TESTS_DIRECTORY/uncommented_"$NAME"_tests.txt >> $PATH_TO_TESTS_DIRECTORY/"$NAME"_tests.results

		sed -n "$c"p $PATH_TO_TESTS_DIRECTORY/uncommented_"$NAME"_tests.txt | ./"$NAME".out >> $PATH_TO_TESTS_DIRECTORY/"$NAME"_tests.results

	((c++))

	done

rm $PATH_TO_TESTS_DIRECTORY/uncommented_"$NAME"_tests.txt
