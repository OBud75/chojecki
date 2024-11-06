#!/bin/bash

# exercice pyramide en bash
echo "rentrez un ,nombre"
read myvar

for ((i = 0; i < $myvar; i++)) ; do
	echo $i 
 
for (( j=i; j<n; j++ )); do
    echo -n " "

for (( k=1; k<=(2*i-1); k++ )); do
    echo -n "*"


# si utilisateur rentrez 5, on dessine une pyramide de 5 sur 5 

