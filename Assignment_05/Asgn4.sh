#!/bin/bash

read -p "Enter a number:" num

i=1
div=$(( $num / 2 ))
if [ $num -eq 1 -o $num -eq 0 ]
then
		echo -e "$num is a Special number\nNot Prime nor Composite"
else
		for (( i=2;i<=div;i++))
		do
			res=$(( $num % $i ))
			if [ $res -eq 0 ]
			then 
					flag=0
			else
					flag=1
			fi
		done

		if [ $flag -eq 0 ]
		then
				echo "The $num is Not Prime Number"
		else
				echo "The $num is Prime Number"
		fi
fi
