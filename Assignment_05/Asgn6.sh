#!/bin/bash



echo "Enter an Year:"
read year

if [ $(($year % 100)) -eq 0 ]
then
	if [ $(($year % 400)) -eq 0 ]
	then
			echo "$year is Leap year"
	else
			echo "$year is not Leap year"
	fi
else
	if [ $(($year % 4)) -eq 0 ]
	then
			echo "$year is Leap year"
	else
			echo "$year is not Leap year"
	fi
fi
