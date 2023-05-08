// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

int main(){
    char j[16];
    for(int i = 1; i <= 15; ++i){
        int l, r;
        scanf("%d %d", &l, &r);
        j[i] = l > r ? 'l' : 'r';
    }
    
    // vai cair no priemeiro jogo de quem ganhou.
    int p = 15;
    int d = 1;
    for(int i = 0; i < 3; ++i){
        if(j[p] == 'l'){
            p = p - d -1;
            d = 2*d +1;
        }
        else{
            p = p - d;
            d = 2*d;
        }
    }
    
    // so fazer a manipulacao pra saber quem ganhou.
    p = p*2 - (j[p] == 'l' ? 1 : 0);

    printf("%c\n", 'A'+p-1);

    return 0;
 }
// AC.
