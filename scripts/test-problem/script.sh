echo "Testing: $1"
g++ -std=c++20 -O2 "$1"/main.cpp -o main
for infile in "$1"/test_cases/*
do

	filename="${infile##*/}"
	echo -n "$filename " 
	\time -f "%E" ./main  < $infile > out.txt -f '%E'
	diff out.txt "$1"/test_answers/$filename
done
