#!/bin/bash

# exercice pyramide en bash
echo "rentrez un ,nombre"
read hauteur

for ((i = 0; i < hauteur; i++)) ; do

for ((j=0; j<i ; j++)) ; do
	echo -n "*" 
done
	echo " " 
done
