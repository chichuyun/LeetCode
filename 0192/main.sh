# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | xargs -n1 | sort | uniq -c | sort -rn | awk '{print $2,$1}'