// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);
  int ans;
  while(n) {
    int *h = (int*) calloc(1e6*1 +1, sizeof(int));
    ans = 0;
    for(int i = 0; i < n; ++i) {
      int x; scanf("%d", &x); 
      if(++h[x] > h[ans]) ans = x; 
    }
    printf("%d\n", ans);
    scanf("%d", &n);
  }
}

// AC, histogram.
