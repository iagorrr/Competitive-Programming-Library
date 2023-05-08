// iagorrr ;)
#include <stdio.h>

int t = 0;
void solve(int n){
    printf("Teste %i\n", ++t);
    int a = 0, b = 0;
    while(n--){
        int x, y;
        scanf("%i %i", &x, &y);
        a += x;
        b += y;

        printf("%i\n", a-b);
    }
    printf("\n");
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