// iagorrr ;)
#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int t;
    scanf("%d", &t);

    printf("%s\n", t == (a+b+c) ? "Acertou" : "Errou");
    return 0;
}

// AC.