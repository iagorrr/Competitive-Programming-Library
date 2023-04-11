// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

#define less(a, b) a < b 
#define exchange(a, b) Item t = a; a = b; b = t;
typedef int Item;

int main() {
  int n;
  scanf("%d", &n);

  while(n) {
    Item *xs = (Item*) calloc(n +1, sizeof(Item));
    for(int i = 0; i < n; ++i) {
      scanf("%d", &xs[i]); 
    }
    int best = -1;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
      if(cnt == 0) best = xs[i];
      cnt += best == xs[i] ? 1 : -1;
    }
    printf("%d\n", best);
    scanf("%d", &n);
  }
}

// AC, majority vote algorithm.

