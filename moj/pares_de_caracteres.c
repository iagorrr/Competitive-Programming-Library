// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>


int hist[(int)1e3];
int conta_par(char *c){
    if(*c == '\0') return 0;

    int d = 0;
    if(*(c+1) != '\0' && *c == *(c+2)) d = 1;

    return conta_par(c+1) + d;
}

int main(){
    char *s = malloc(266*sizeof(char));
    scanf("%s", s);

    int ans = conta_par(s);

    printf("%d\n", ans);
    return 0;
}

// AC.