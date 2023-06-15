// iagorrr ;)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool g[5000][5000];
bool vis[5000];

void dfs(int x) {
  vis[x] = true;

  for (int i = 0; i < 5000; ++i) {
    if (!g[x][i])
      continue;

    if (!vis[i]) {
      dfs(i);
    }
  }
}
int main(void) {
  int n;
  scanf("%d", &n);

  int i, j;
  while (scanf("%d %d", &i, &j) == 2) {
    g[i][j] = true;
    g[j][i] = true;
  }

  int ans = 0;
  for (int k = 0; k < n; ++k) {
    if (!vis[k]) {
      ans++;
      dfs(k);
    }
  }
  printf("%d\n", ans);
}
// AC, componentes conexos
