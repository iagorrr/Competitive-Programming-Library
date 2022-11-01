// iagorrr ;)
#include <stdio.h>

void solve(int m){
    int a = 0;
    int b = 0;

    while(m--){
        int x;
        scanf("%i", &x);

        a += x == 0 ? 1 : 0;
        b += x == 1 ? 1 : 0;
    }

    printf("Alice ganhou %i e Beto ganhou %i\n", a, b);
}
int main(){
    int n = 1;
    while(n){
        scanf("%i", &n);

        if(n != 0) solve(n);
    }
    return 0;
}

// AC.