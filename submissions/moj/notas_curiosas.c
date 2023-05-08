// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>
int main() {
  int n; 
  int *h = (int*) calloc(1e3+1, sizeof(int));
  int ans = 0;
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; ++i) {
      int ai; scanf("%d", &ai);
      ++h[ai];
      if(h[ai] == h[ans]){
        if(ai > ans) ans = ai;
      }
      else if (h[ai] > h[ans]) ans = ai;
    }
  }
  printf("%d\n", ans);
}

// AC, histogram.
