#include <stdio.h>
int main(){
    int x;
    while(scanf("%x", &x) != EOF){
        char *c = &x;
        for(int i = 0; i < 4; ++i){
            if(c[i] == 0){printf("\n"); return 0;}
            printf("%c", (char)c[i]);
        }
    }
    return 0;
}
// AC.