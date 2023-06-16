// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct dsu {
  int n;
  int *size;
  int *p;
} dsu;

dsu *create(int n) {
  dsu *new = malloc(sizeof(dsu));
  new->n = n;
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

int getmaxsize(dsu *st) {
  int ans = 1;
  for (int i = 0; i < st->n; ++i) {
    if (ans < st->size[i])
      ans = st->size[i];
  }
  return ans;
}

int main(){

}
