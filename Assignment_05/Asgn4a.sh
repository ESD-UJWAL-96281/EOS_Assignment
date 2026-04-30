#!/bin/bash


echo "Enter a Number:"
read num

if [ $(factor $num | wc -w) -eq 2 ]
then 
		echo "$num is Prime Number"
else
		echo "$num is not Prime Number"
fi
