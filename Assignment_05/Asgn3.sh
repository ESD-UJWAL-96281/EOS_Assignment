#!/bin/bash

#Write a shell script to accept the name from the user and check whether user entered
#name is file or directory. If name is file display its size and if it is directory display its
#contents.

echo "Enter a name:"
read name

if [ -e $name ]
then
		if [ -f $name ]
		then
			echo "$name is a file"
			ls -hs $name
		elif [ -d $name ]
		then
			echo "$name is a directory"
			ls -l $name
		fi
else
		echo "Invalid name"
fi
