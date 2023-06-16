/*
 * iagorrr ;)
 * Fazer uma travessia pra cada nó e verifica se teve
 * algum quen não foi alcançado
 * O(n*n)
 * */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int **g, int n, int *vis) {
  vis[u] = true;
  for (int i = 0; i < n; ++i)
    if (g[u][i] && !vis[i])
      dfs(i, g, n, vis);
}

bool check(int **g, int n) {
  for (int i = 0; i < n; ++i) {
    int *vis = calloc(sizeof(int), n);
    dfs(i, g, n, vis);
    for (int j = 0; j < n; ++j) {
      if (!vis[j])
        return false;
    }
    free(vis);
  }
  return true;
}

int main(void) {
  while (true) {
    int n, m;
    int r = scanf("%d %d", &n, &m);
    if (r < 2 || !n & !m)
      break;

    int **g = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i)
      g[i] = calloc(sizeof(int), n);

    for (int i = 0; i < m; ++i) {
      int v, w, p;
      scanf("%d %d %d", &v, &w, &p);
      v--;
      w--;
      p--;
      g[v][w] = 1;
      if (p)
        g[w][v] = 1;
    }

    bool ans = check(g, n);
    printf("%d\n", ans);

    for (int i = 0; i < n; ++i)
      free(g[i]);
    free(g);
  }
}

// AC, trafessia.
