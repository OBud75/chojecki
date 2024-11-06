echo -e "Number: "
read x
for ((i=0; i<=x; i++)); do
	for ((j=0; j<i; j++));do
	echo -n "*"
	done
	echo -e "\n"
done
