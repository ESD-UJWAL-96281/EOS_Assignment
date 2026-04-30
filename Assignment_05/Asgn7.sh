#!/bin/bash



read -p "Enter the number:" num

if [ $num -eq 0 ]
then
		echo "Entered number is $num"
elif [ $num -gt 0 ]
then
		echo "$num is Positive"
else
		echo "$num is Negative"
fi
