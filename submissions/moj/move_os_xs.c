// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>


void excreveitor(int tx){
    if(!(tx)) return;
    printf("x");
    excreveitor(tx-1);
}
void movimentaitor(char *s, int tx){
    // final da string printar todos os x que foram encontrados ate aqui.
    if(*s == '\0'){
        excreveitor(tx);
        return;
    }

    // caracter qualquer so printa mesmo.
    if(*s == 'x') ++tx;
    else printf("%c", *s);

    // chama o proximo familia.
    movimentaitor(s+1, tx);
    
}
int main(){
    char *s = malloc(sizeof(char)*200);

    scanf("%s", s);

    movimentaitor(s, 0);
    printf("\n");

    free(s);
    return 0;
}

// AC.
