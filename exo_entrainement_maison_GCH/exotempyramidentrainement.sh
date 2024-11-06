#!/bin/bash

echo "rentrez le nombre détoiles pyramide"
read p

for ((i=1; i<p; i++)) do
for ((j=1; j<i; j++)) do

echo -n "*"
done
echo -e ""

done
