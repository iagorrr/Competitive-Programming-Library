// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

struct pair
{
   int f;
   int s; 
};
typedef struct pair pair;

    // se tá no jogo não significa que é pra usar - Pêro Vaz de Caminha
int solve(int n)
{
    pair *b = calloc(66, sizeof(pair));

    while(n--)
    {
        char l;  int d; scanf("%d", &d); scanf("%c", &l); scanf("%c", &l); 

        l == 'D' ? b[d].s++ : b[d].f++; 
    }

    int ans = 0; for(int i = 0; i < 66; ++i) ans += b[i].f < b[i].s ? b[i].f : b[i].s;

    return ans;

}
int main()
{
    int n;

    while(scanf("%d", &n) != EOF) printf("%d\n", solve(n));
    return 0;
}

// AC.