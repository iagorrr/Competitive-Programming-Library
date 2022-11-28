// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

void reverseitor(char *c){
    if(*c == '\0') return;
    
    printf("%c", (*c == 'x'  ? 'y' : *c));
    reverseitor((c+1));
}
int main(){
    char *s = malloc(266*sizeof(char));
    scanf("%s", s);

    reverseitor(s);
    printf("\n");
    return 0;
}

// AC.
