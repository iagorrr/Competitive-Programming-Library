# compile a c++ file
comp() {
	g++ -x c++ -g -O2 -std=gnu++20 -static "$@"
}

test_algorithm_main() {
	algo_path="$1"
	if [ -f "$algo_path"/main.cpp ]; then
		comp $algo_path -o main
		./main
		rm main
	fi
}

test_algorithm_problem() {
	algo_path="$1"
	for problem in "$algo_path/problems/*"; do
		echo -e "Problem: $problem"
		problem_main="$problem/main.cpp"
		comp problem_main -o main
		rm main
	done

}
