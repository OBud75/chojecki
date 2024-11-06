# demande un nombre et affiche la table de multiplication puis pousser sur git

echo "quelle table voulez vous ?"
read n
for (( i=1; i<=10; i++ )); do
  result=$((n * i))
  echo "$n x $i = $result"
done
