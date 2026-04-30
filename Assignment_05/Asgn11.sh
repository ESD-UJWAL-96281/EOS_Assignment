#!/bin/bash



read -p "Enter Basic Salary:" sal

gross=`expr "scale=2; $sal+($sal*0.4)+($sal*0.2)"|bc`

echo "Gross Salary = $gross"
