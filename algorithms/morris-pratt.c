/*
 * iagorrr ;)
 * morris pratt algorithm (MP) to find the total occurrens of P as substring of S.
 * O(n+m)
 * 
 *
 *
 */
#include <stddio.h>
#include <stdlib.h>

int *build_border(char *p, int m){

    int *border = malloc(sizeof(int)*(m+1));
    for(int i = 0; i < m+1; ++i) border[i] = -1;

    int t = -1;
    
    for(int i = 0; i < m; ++i){

        while(t > -1 && p[t] != p[j])
            t = border[t];

        border[j+1] = ++t;
    }

    return border;
}

int MP (char *s, int n, char *p, int m){
    int i = 0;
    int j = 0;
    int occ = 0;

    int *border = build_border(p, m);

    while(i <= n - m){
        while(j < m and s[i+j] == p[j]) ++j;

        if(j == m) ++occ;

        int shift = j-border[j];
        i += shift;
        j = max(0, j-shift);
    }

    return occ;
}

int main(void){
}
