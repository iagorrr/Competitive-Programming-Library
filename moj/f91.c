// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

long int f91(long int n){

    return n >= 101 ? n-10l : f91(f91(n+11));
}
int main(){
    long int n;

    while(scanf("%li", &n)){
        if(n == 0) break;

        printf("f91(%li) = %li\n", n, f91(n));
    }
    return 0;
}

// AC.