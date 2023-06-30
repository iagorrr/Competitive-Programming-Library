// iagorrr ;)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **alloc_2darray(int n, int m) {
  int **arr = (int **)malloc(sizeof(int **) * n);
  for (int i = 0; i < n; ++i)
    arr[i] = (int *)calloc(m, sizeof(int));
  return arr;
}
int main(void) {
  int n;
  scanf("%d", &n);
  int **adj = alloc_2darray(n + 1, n + 1);
  while (true) {
    int u, v, d;
    scanf("%d %d %d", &u, &v, &d);
    if (v == 0 && u == 0 && d == 0)
      break;
    adj[u][v] = true;
    if (d == 2)
      adj[v][u] = true;
    adj[u][u] = true;
    adj[v][v] = true;
  }
  for (int i = 0; i < n; ++i)
    adj[i][i] = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (adj[j][i])
        for (int k = 0; k < n; ++k)
          if (adj[i][k])
            adj[j][k] = true;

  int u, v;
  while (scanf("%d %d", &u, &v) == 2) {
    bool ida = adj[u][v];
    bool volta = adj[v][u];
    if (ida && volta)
      printf("Ida e Volta\n");
    else if (ida)
      printf("Apenas Ida\n");
    else if (volta)
      printf("Apenas Volta\n");
    else
      printf("Impossibru\n");
  }
}

// AC, floyd warshall
