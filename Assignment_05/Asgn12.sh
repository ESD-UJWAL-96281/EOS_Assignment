#!/bin/bash

echo "Enter filename:"
read fname

if [ -e $fname ]
then
	echo "Last Modification Time:"
	date -r $fname
else
	echo "File doesn't exist"
fi
