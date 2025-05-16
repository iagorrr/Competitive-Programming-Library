set -e

algo_path=$1
echo "Testing: $algo_path"

# Iterate over each problem
for entry in "$algo_path"/Problems/*; do
        # If isn't a directory continue
        if [ ! -d "$entry" ]; then
                continue
        fi

        echo -e "\tProblem: $entry"
        g++ -std=c++20 -O2 "$entry/main.cpp" -o main -D LOCAL

        for infile in "$entry"/in/*; do
                if [ ! -f "$infile" ]; then
                        continue
                fi

                filename="${infile##*/}"
                echo -en "\t\tinput: $filename "
                { \time -f " time: %E memory: %M" ./main <"$infile" >out.txt; } 2>&1 | tr -d '\n'

                if ! diff -q out.txt "$entry/out/$filename" &>/dev/null; then
                        >&2 echo " ERR"
                        # Optionally, show the diff:
                        # diff out.txt "$entry/out/$filename"
                        break
                fi
                echo -e " OK"
        done

        rm -f main out.txt
done

# Test the main file test
if [ -f "$algo_path/main.cpp" ]; then
        echo "Testing main.cpp in $algo_path"
        g++ -std=c++20 -O2 "$algo_path/main.cpp" -o main -D LOCAL
        ./main
        rm -f main
fi
