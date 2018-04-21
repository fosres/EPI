#!/bin/bash
# This is the 
# template you should follow
# to print all contents of a test script
# for reference, please visit: https://ryanstutorials.net/bash-scripting-tutorial/bash-loops.php
echo "***************************************************"
cd /Users/tanveersalim/Desktop/Git/PIC-10A-HW/PIC-10A-HW/roman #Enter directory of test script

lines=$(wc -l < smart_roman_tests.txt)
((lines++))
c=1
while [ $c -lt $lines ]
	do
		sed -n "$c"p smart_roman_tests.txt | ./roman.out
	((c++))
	done
