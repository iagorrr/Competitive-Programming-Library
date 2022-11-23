// iagorrr ;)
long int fibo[(int)1e4];
long int fibonacci(int n){
    if(n <= 2) return 1;

    if(fibo[n] != 0) return fibo[n];

    fibo[n] = fibonacci(n-2)+fibonacci(n-1);

    return fibo[n];
}

// AC.
