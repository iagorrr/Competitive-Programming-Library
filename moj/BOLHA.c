// iagorrr ;)
#include <stdio.h>
int v[(int)1e3+666];
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int main(){

    int n = 0;
    while(scanf("%d", &v[n++]) != EOF){}

    n--;
    for(int i = 0 ; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(v[i] < v[j]) swap(&v[i], &v[j]);
        
    
    for(int i = 0; i < n; ++i)
        printf("%d", v[i]);
    
    printf("\n");

    return 0;
}

// AC.