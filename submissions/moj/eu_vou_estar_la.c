// iagorrr ;)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
  int size;
  int *v;
} vector;

vector *create(int n) {
  vector *new = malloc(sizeof(vector));
  new->size = n;
  new->v = calloc(sizeof(int), n);
  return new;
}


void mark(int x, bool *vis, vector **g) {
  vis[x] = true;
  for(int i = 0; i < g[x]->size; ++i) {
    int u = g[x]->v[i];
    if(! vis[u]){
      vis[u] = true;
    }
  }
}
int main(void) {
  int n, m, j;
  scanf("%d %d %d", &n, &m, &j);

  vector **g = malloc(sizeof(vector*) * n);

  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d", &k);
    g[i] = (vector*) create(k);
    for (int l = 0; l < k; ++l) {
      int x; scanf("%d", &x);
      g[i]->v[l] = x;
    }
  }

  bool *vis = calloc(sizeof(int), n);
  for(int i = 0; i < m; ++i) {
    int x; scanf("%d", &x);
     mark(x, vis, g);
  }

  for (int i = 0; i < j; ++i) {
    int x;
    scanf("%d", &x);
    if (vis[x])
      printf("Eu vou estar la\n");
    else
      printf("Nao vou estar la\n");
  }
}

// AC, grafo
