// iagorrr ;)
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);


    if(n > a || n > b || n > c)
        printf("N\n");
    else
        printf("S\n");
    return 0;
}

// AC.
