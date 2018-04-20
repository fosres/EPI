#!/bin/bash
	read varname
	if [[ $varname != EOF ]]
	then
		echo $varname
		./read_vars.sh
	fi
