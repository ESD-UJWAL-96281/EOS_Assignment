#!/bin/bash


echo "Enter the number of terms:"
read t

prev=0
curnt=1

for ((i=0 ; i<=t ; i++))
do
	echo -n "$prev "
	next=`expr $prev + $curnt`
	prev=$curnt
	curnt=$next

done
echo -e "\n"
