#!/bin/bash


echo -e "Enter choice:\n1.Date\n2.Cal\n3.Ls\n4.Pwd\n5.Exit\n"
read choice

case $choice in
		1) 
				echo "Date:" 
				date
				;;
		2) 
				echo "Cal:"  
				cal
				;;
		3) 
				echo "Ls:"	 
				ls
				;;
		4) 
				echo "Pwd:"  
				pwd
				;;
		5) 
				echo "Exit:" 
				exit
				;;
		*) echo "Invalid Choice"
esac


