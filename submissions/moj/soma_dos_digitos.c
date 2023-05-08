// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

int somaitor(char *s, int t){
    if(*s == '\0') return t;
    // a soma dessa string vai ser a soma de todos os que vem depois mais a propria posicao dela.
    t = somaitor(s+1, t) + (*s - '0');
    return t;
}
int main(){
    char *s = malloc(sizeof(char)*14);

    scanf("%s", s);

    printf("%d\n", somaitor(s, 0));

    free(s);
}

// AC.