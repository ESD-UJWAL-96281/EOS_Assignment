#!/bin/bash


echo "Printed pattern using echo command"
echo -e "*\n*  *\n*  *  *\n*  *  *  *\n*  *  *  *  *\n"

echo "Printed pattern using for loop"
for ((i=1 ; i<=5 ; i++))
do
	for ((j=1 ; j<=i ; j++))
	do
		echo -n "*  "
	done
		echo 
done
