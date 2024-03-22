#copy first argument to clipborad ! ONLY WORK ON XORG !
alias clip="xclip -sel clip"

# compile the $1 parameter, if a $2 is provided
# the name will be the the binary output, if 
# none is provided the binary name will be 
# 'a.out'
comp() {
  echo ">> COMPILING $1 <<" 1>&2

  if [ $# -gt 1 ]; then
    outfile="${2}"
  else
    outfile="a.out"
  fi

  time g++ -std=c++20 \
      -O2 \
      -g3 \
      -Wall \
      -fsanitize=address,undefined \
      -fno-sanitize-recover \
      -D LOCAL \
      -o "${outfile}" \
      $1

  if [ $? -ne 0 ]; then
      echo ">> FAILED <<" 1>&2
      return 1
  fi
  echo ">> DONE << " 1>&2
}

# run the binary given in $1, if none is 
# given it will try to run the 'a.out'
# binary
run() {
        to_run=./a.out
        if [ -n "$1" ]; then
                to_run="$1"
        fi
        time $to_run
}

testall() {
    comp $1 generator
    comp $2 brute
    comp $3 main

    input_counter=1

    while true; do
        echo "$input_counter"
        run ./generator > input
        run ./main < input > main_output.txt
        run ./brute < input > brute_output.txt

        diff brute_output.txt main_output.txt
        if [ $? -ne 0 ]; then
            echo "Outputs differ at input $input_counter"
            echo "Brute file output:"
            cat brute_output.txt
            echo "Main file output:"
            cat main_output.txt
	    echo "input used: "
	    cat input
            break
        fi

        ((input_counter++))
    done
}


