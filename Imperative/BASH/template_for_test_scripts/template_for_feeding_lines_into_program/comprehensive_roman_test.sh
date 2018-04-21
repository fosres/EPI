#!/bin/bash
# This is the 
# template you should follow
# to print all contents of a test script
# for reference, please visit: https://ryanstutorials.net/bash-scripting-tutorial/bash-loops.php

cd /Users/tanveersalim/Desktop/Git/PIC/PIC/roman 

roman_tests=~/Desktop/Tests/roman_tests/
lines=$(wc -l < $roman_tests/comprehensive_roman_test_values.txt)

((lines++))

c=1

g++ roman.cpp -o roman.out

touch $roman_tests/comprehensive_roman_test.output

while [ $c -lt $lines ]
	do
		sed -n "$c"p $roman_tests/comprehensive_roman_test_values.txt | ./roman.out >> $roman_tests/comprehensive_roman_test.output

	((c++))

	done
