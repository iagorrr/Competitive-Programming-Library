algo_path=$1
echo "Testing: $algo_path"

# Test each problem
for entry in "$algo_path"/*/
do
	echo "Problem: $entry"
	g++ -std=c++20 -O2 "$entry"/main.cpp -o main
	for infile in "$entry"/in/*
	do

		filename="${infile##*/}"
		echo -n "input: $filename " 
		\time -f "%E" ./main  < $infile > out.txt -f '%E'

		if ! diff -q  out.txt "$entry"/out/$filename &>/dev/null; then
			>&2 echo  "different"
			break
		fi
	done
done

# Test the main file test
if [ -f "$algo_path"/main.cpp ]; then
	g++ -std=c++20 -O2 "$algo_path"/main.cpp -o main
fi

rm out.txt
rm main
