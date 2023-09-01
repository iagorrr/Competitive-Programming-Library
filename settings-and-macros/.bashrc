cpp() {
  echo ">> COMPILING <<" 1>&2
  g++ -std=c++17 \
      -O2 \
      -g \
      -g3 \
      -Wextra \
      -Wshadow \
      -Wformat=2 \
      -Wconversion \
      -fsanitize=address,undefined \
      -fno-sanitize-recover \
      -Wfatal-errors  \
      $1

  if [ $? -ne 0 ]; then
      echo ">> FAILED <<" 1>&2
      return 1
  fi
  echo ">> DONE << " 1>&2
  time  ./a.out ${@:2}
}

prepare() {
    for i in {a..z}
    do
        cp macro.cpp $i.cpp
        touch $i.py
    done

    for i in {1..10}
    do
        touch in${i}
        touch out${i}
        touch ans${i}
    done
}
