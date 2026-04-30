#!/bin/bash


read -p "Enter a number:" n1
facto=1

for ((i=1;i<=$n1;i++))
do
	facto=`expr $facto \* $i`
done

echo "Factorial of $n1 = $facto"
