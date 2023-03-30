// iagorrr ;)
#include <stdio.h>

char c[(int)1e6 + 1];
int main(void) {
  int n; scanf("%d", &n);
  int a = 0;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    a += !c[x];
    c[x] = 1;
  }
  printf("%d\n", a);
}

// AC, 'set'
