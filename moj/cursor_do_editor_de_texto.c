// iagorrr ;)
#include <stdio.h>
#include <string.h>
#define MAXL 1004
char T[MAXL][MAXL];
int L, Cl, Cc;
char buff;
int main(){
    memset(T, '\0', sizeof(T));

    scanf("%i", &L);
    scanf("%c", &buff);
    for(int i = 0; i < L; ++i){
        fgets(T[i], MAXL, stdin);
        T[i][strlen(T[i])-1] = '\0';
    }
    scanf("%i %i", &Cl, &Cc);
    Cl--; Cc--;

    char C;
    int prevpos = Cc;
    scanf("%c", &buff);
    while(scanf("%c", &C) != EOF){
        if(C == 'j'){
            Cl = Cl == L-1? Cl : Cl + 1;
        }
        else{
            Cl = Cl == 0 ? 0 : Cl-1;
        }
        if(prevpos > strlen(T[Cl])-1) Cc = strlen(T[Cl])-1;
        else Cc = prevpos;

        printf("%i %i %c\n", Cl+1, Cc+1, T[Cl][Cc]);
        scanf("%c", &buff);
    }   
}

// AC.