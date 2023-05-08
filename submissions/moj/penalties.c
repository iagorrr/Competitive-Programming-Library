// iagorrr ;)
#include <stdio.h>
int abs(int x){
    return x < 0 ? -x : x;
}
int main(){
    int n;
    scanf("%d", &n);

    char ca[n+1];
    char cb[n+1];
    scanf("%s", ca);
    scanf("%s", cb);

    int pa = 0;
    int pb = 0;
    int ans = -1;
    for(int i = 1; i <= 2*n; ++i){

 
        if(i&1)
            pa += ca[i/2] == 'o';
        else
            pb += cb[i/2 -1+ i%2] == 'o';

        // printf("%d %d %d\n", i, pa, pb);
        // printf("%d %d %d %d\n", pa, pb + (n*2 -i)/2 + (i)%2, pb, pa + (n*2-i)/2);
        if((pa > pb + (n*2 -i)/2 + (i)%2) || (pb > pa + (n*2-i)/2)){
            ans = i;
            break;
        }

    }
    if(ans == -1) printf("Empate\n");
    else printf("%d\n", ans);
    return 0;
}

// AC.