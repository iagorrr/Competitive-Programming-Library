#include <stdio.h>


int fibo(int x){
    if (x == 0){
        return 0;
    }

    if (x == 1){
        return 1;
    }

    int i;
    int previous = 1;
    int now = 1;
    int temp = 0;
    for (i = 0; i < x -2; i++){
        temp = now;
        now = previous + now;
        previous = temp;
    }
    return now;
}

int main(){
    int N;
    scanf("%i", &N);

    int i;
    int x;
    for (i = 0; i < N; i++){
        scanf("%i", &x);
        printf("Fib(%i) = %i\n", x, fibo(x));
    }
}