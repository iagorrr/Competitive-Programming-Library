// iagorrr ;)
#include <stdio.h>
#include <string.h>
#define less(a, b) (a.p != b.p ? a.p < b.p : strcmp(a.s, b.s) > 0)
typedef struct item{
  int p;
  char s[21];
} item;

int main(){

  int n; 
  int t = 1;
  while(scanf("%d", &n) != EOF) {

    item a[101];  
    int l=0;
    for(int i = 0; i < n; ++i){
      scanf("%s %d", a[i].s, &a[i].p);
      if(less(a[i], a[l])) l = i;
    }

    printf("Instancia %d\n%s\n\n", t++, a[l].s);
  }

}
// AC, implementation.
