// iagorrr ;)
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    int c;
    while(n--){
        scanf("%i", &c);
        sum += c;
    }
    int t;
    scanf("%d", &t);

    printf("%s\n",t == sum ? "Acertou" : "Errou");
    return 0;
}

// AC.