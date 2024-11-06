#!/bin/bash
echo "quel est le chiffre dont il faut sortir la table ?"
read chiffre

for ((i = 1 ; i<10 ; i++)); do
	result=$((chiffre * i))

echo "$chiffre x $i = $result"
done
