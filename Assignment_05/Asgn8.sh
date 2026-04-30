#!/bin/bash


echo -n "Enter a number:"
read n

for i in {1..10}
do
	res=`expr $n \* $i`

	echo "$n * $i = $res"
done
