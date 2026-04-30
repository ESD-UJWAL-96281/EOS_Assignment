#!/bin/bash


echo "Enter 1st file name:"
read f1

echo "Enter 2nd file name:"
read f2

echo -e "\n$f1:\n"
cat $f1
echo -e "\n"
echo -e "$f2:\n"
cat $f2
echo -e "\n"

cat $f1 | tr 'A-Za-z' 'a-zA-Z' >> $f2
echo -e "Output:\n"
cat $f2
