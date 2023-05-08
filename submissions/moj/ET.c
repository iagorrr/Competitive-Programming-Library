// iagorrr ;)
#include <stdio.h>
#include <string.h>

int main(){
    char s[34];
    char s2[] = "marte\0";
    int boool = 0;
    while(scanf("%s", s) !=  EOF)
        if(!strcmp(s, s2))
            boool = 1;        
    
    printf("%s\n", boool ? "Leonardo Cicero Marciano" : "none");
}

// AC.