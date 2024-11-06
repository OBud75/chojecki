#!/bin/bash

echo "super calto, donne ton chiffre"
read c 

for ((i=1; i<c; i++)); do
result=$((i*c))
echo $i "*" $c "=" $result

done


