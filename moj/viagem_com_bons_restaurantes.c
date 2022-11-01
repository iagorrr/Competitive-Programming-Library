// iagorrr ;)
#include <stdio.h>

int dia = 0;
void solve(int n){
    int id = 0;
    int star = 0;

    int ansid = 1<<30;
    int ansstar = 0;

    while(n--){
        scanf("%i %i", &id, &star);

        if(star > ansstar){
            ansstar = star;
            ansid = id;
        }
        else if (star == ansstar) ansid = id < ansid  ? id : ansid;
    }

    printf("Dia %i\n", ++dia);
    printf("%i\n\n", ansid);
}
int main(){
    int n = 1;

    while(scanf("%i", &n) != EOF){
        solve(n);
    }
    return 0;
}

// AC.