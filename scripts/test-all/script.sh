set -e

tests_path=$1

SCRIPT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

for algo_path in "$tests_path"/*; do
        echo "Testing: $algo_path"

        bash "$SCRIPT_PATH/../test-algorithm/script.sh" "$algo_path"

        # # Test each problem
        # for entry in "$algo_path"/Problems/*; do
        #
        #         echo -e "\tProblem: $entry"
        #
        #         continue
        #         g++ -std=c++20 -O2 "$entry"/main.cpp -o main
        #         for infile in "$entry"/in/*; do
        #
        #                 filename="${infile##*/}"
        #                 echo -en "\t\tinput: $filename "
        #                 { \time -f "time: %E memory: %M" ./main <"$infile" >out.txt; } 2>&1 | tr -d '\n'
        #
        #                 if ! diff -q out.txt "$entry"/out/$filename &>/dev/null; then
        #                         >&2 echo " ERR"
        #                         # diff out.txt "$entry"/out/$filename
        #                         break
        #                 fi
        #                 echo -e " OK"
        #         done
        # done
        #
        # # Test the main file test
        # if [ -f "$algo_path"/main.cpp ]; then
        #         g++ -std=c++20 -O2 "$algo_path"/main.cpp -o main
        # fi
        #
        # rm -f out.txt
        # rm -f main
done
