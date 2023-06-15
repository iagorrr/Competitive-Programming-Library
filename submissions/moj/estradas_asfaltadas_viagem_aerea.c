// iagorrr ;)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dsu {
  int *size;
  int *p;
} dsu;

dsu *create(int n) {
  dsu *new = malloc(sizeof(dsu));
  n++;
  new->size = malloc(sizeof(int) * n);
  new->p = malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) {
    new->size[i] = 1;
    new->p[i] = i;
  }
  return new;
}

int findset(dsu *st, int x) {
  if (st->p[x] == x)
    return x;
  st->p[x] = findset(st, st->p[x]);
  return st->p[x];
}

bool sameset(dsu *st, int x, int y) { return findset(st, x) == findset(st, y); }

void unionset(dsu *st, int x, int y) {
  int px = findset(st, x);
  int py = findset(st, y);

  if (px == py)
    return;
  if (st->size[px] < st->size[py]) {
    int t = px;
    px = py;
    py = t;
  }

  st->p[py] = px;
  st->size[px] += st->size[py];
}

int main(void) {
  int v, j;
  scanf("%d %d", &v, &j);

  int x, y;
  dsu *st = create(v);
  while (scanf("%d %d", &x, &y) == 2) {
    unionset(st, x, y);
  }

  int sizejao = st->size[findset(st, j)];
  int bestsize = 0;
  int ans = -1;
  for (int i = 0; i <= v; ++i) {
    if (i == j)
      continue;
    int cursize = st->size[findset(st, i)];
    if (cursize > bestsize) {
      bestsize = cursize;
      ans = i;
    }
  }

  if (sizejao >= bestsize) {
    if (sizejao == 1)
      printf("Fique em casa\n");
    else
      printf("Bora pra estrada\n");
  } else {
    printf("Vamos para %d\n", ans);
  }
}

// AC, componentes conexos, dsu
