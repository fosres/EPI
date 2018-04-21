#!/bin/bash
# This is the 
# template you should follow
# to print all contents of a test script
# for reference, please visit: https://ryanstutorials.net/bash-scripting-tutorial/bash-loops.php

cd /Users/tanveersalim/Desktop/Git/PIC-10A-HW/PIC-10A-HW/roman 

lines=$(wc -l < comprehensive_roman_test_values.txt)

((lines++))

c=1

while [ $c -lt $lines ]
	do
		sed -n "$c"p comprehensive_roman_test_values.txt | ./roman.out

	((c++))

	done
