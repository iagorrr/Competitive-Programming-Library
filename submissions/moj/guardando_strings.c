/*
 * iagorrr ;)
 * morris pratt algorithm (MP) to find the total occurrens of P as substring of S.
 * O(n+m)
 */
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b ? a : b)
int *border;
int *build_border(char *p, int m){

    int *bd = (int*)malloc(sizeof(int)*(m+1));
    for(int i = 0; i < m+1; ++i) bd[i] = -1;

    int t = -1;
    
    for(int i = 0; i < m; ++i){

        while(t > -1 && p[t] != p[i])
            t = bd[t];

        bd[i+1] = ++t;
    }

    return bd;
}
int MP (char *s, int n, char *p, int m){
    int i = 0;
    int j = 0;
    int occ = 0;

    while(i <= n - m){
        while(j < m && s[i+j] == p[j]) ++j;

        if(j == m) ++occ;

        int shift = j-border[j];
        i += shift;
        j = max(0, j-shift);
    }
    
    return occ;
}

int main(){
    int *sizes = malloc(sizeof(int)*((int)1e5+66));
    int i = 0;
    int n;
    int tsum = 0;
    char *linguicao = (char*)malloc(sizeof(char) * ((1<<23)+(int)1e5*2) );
    while(scanf("%s%n", &linguicao[tsum], &n) != EOF){
        sizes[i] = n;
        tsum += n+1;
        ++i;
        scanf("%*c");
    }

    border = build_border(&linguicao[tsum-n], sizes[i-1]);
    int cur = 0;
    for(int j = 0; j < i-1; ++j){
        printf("%d\n", MP(&linguicao[cur], sizes[j], &linguicao[tsum-sizes[i-1]-1], sizes[i-1]));
        cur += sizes[j]+1;
    }
    return 0;
}

// AC.
