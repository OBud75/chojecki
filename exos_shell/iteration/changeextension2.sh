for i in $(ls |  grep .txt);do
	mv "$i" "${i%.txt}.jpeg" ;
done
