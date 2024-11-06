#travail en groupe avec Clément Marchal


get_urls() {
	curl https://readi.fi/sitemap.xml > adressenontrie.txt 
	 sed -i 's/\bhttps\b/ \n /g' adressenontrie.txt
}


get_urls
grep -E "://readi.fi/asset/.{1,}/" adressenontrie.txt > adresseok.txt
 

