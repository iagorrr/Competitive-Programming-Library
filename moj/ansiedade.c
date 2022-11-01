// iagorrr ;)
#include <stdio.h>
#include <string.h>

int main(){
    int i = 0;
    int ans = 0; 
    int s = 0;

    char ss[10];
    while(scanf("%s", ss) != EOF){
        if(!strcmp(ss, "sim\0")) s++;

        ++i;
        if(i == 10){
            if(s >= 2) ans++;
            s = 0;
            i = 0;
        }
    }
    printf("%i\n", ans);
    return 0;
}

// AC.