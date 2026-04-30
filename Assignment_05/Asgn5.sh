#!/bin/bash

read -p "Enter Three Numbers:" n1 n2 n3

if [ $n1 -eq $n2 ] && [ $n2 -eq $n3 ]
then
		echo "All numbers are equal"


elif [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then
		echo "$n1 is greater"

elif [ $n2 -gt $n3 ]
then
		echo "$n2 is greater"

else
		echo "$n3 is greater"
fi
