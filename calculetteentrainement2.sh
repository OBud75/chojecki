#!/bin/bash
echo "quelle chiffre pour la tavble?"
read chiffre


for ((i=1; i<$chiffre ; i++)) do
result=$(($i*$chiffre))
echo $i "*" $chiffre = $result
done