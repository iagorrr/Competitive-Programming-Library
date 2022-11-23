// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

struct ans{
    int d; // degree-9
    unsigned char m; // 'bool' is is a multiple or not.
};
typedef struct ans ans_st;


int somaitor(char *s, int t){
    if(*s == '\0') return t;
    t = somaitor(s+1, t) + (*s - '0');
    return t;
}

int somaitor2(int n, int t){
    if(n == 0) return t;

    t = somaitor2(n/10, t) + (n- (n/10)*10);

    return t;
}

ans_st solve(char *s){
    ans_st ans;
    ans.d = 0;

    int ss = somaitor(s, 0);
    ans.m = ss%9 == 0 ? 1 : 0;

    ++ans.d;
    while(ss > 10){
        ss = somaitor2(ss, 0);
        ++ans.d;
    }

    return ans;
}

int main(){
    char *s = malloc(sizeof(char)*1666); //:evil:

    while(scanf("%s", s)){
        if(*s == '0') break;

        ans_st ans = solve(s);

        if(ans.m)
            printf("%s is a multiple of 9 and has 9-degree %i.\n", s,  ans.d);
        else
            printf("%s is not a multiple of 9.\n", s);
        
    }

    free(s);

    return 0;
}

// AC.
