#!/bin/bash
# This is the 
# template you should follow
# to do a successful
# for loop
# for reference, please visit: https://ryanstutorials.net/bash-scripting-tutorial/bash-loops.php

for i in {1..100}
do
sed -n "$i"p sync_all_git_repositories.sh
done
