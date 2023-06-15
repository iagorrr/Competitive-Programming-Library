// iagorrr ;)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxstr = 31;
const int maxn = 5000 + 1;

typedef struct pair {
  char str[31];
  int i;
} pair;

int paircmp(const void *a, const void *b) {
  return strcmp(((pair *)a)->str, ((pair *)b)->str);
}

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

int find(pair *vector, char *str, int n) { // [l, r]
  int l = 0, r = n;
  while (l <= r) {
    int mid = (r - l) / 2 + l;
    int cmp = strcmp(vector[mid].str, str);
    if (cmp == 0) {
      return vector[mid].i;
    } else if (cmp < 0) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return 0;
}
int main(void) {
  int n, c;
  pair vector[maxn];
  while (true) {
    scanf("%d %d", &n, &c);
    if (n == 0 && c == 0)
      break;

    char *str = malloc(sizeof(char) * 31);
    for (int i = 0; i < n; ++i) {
      scanf("%s", str);
      strcpy(vector[i].str, str);
      vector[i].i = i;
    }

    qsort(&vector[0], n, sizeof(pair), paircmp);
    // for (int i = 0; i < n; ++i) {
    //   printf("[%d] [%s]\n", vector[i].i, vector[i].str);
    // }

    char str2[31];
    dsu *st = create(n);
    for (int i = 0; i < c; ++i) {
      scanf("%s %s", str, str2);
      int id1 = find(vector, str, n - 1);
      int id2 = find(vector, str2, n - 1);
      unionset(st, id1, id2);
    }
    int ans = getmaxsize(st);
    printf("%d\n", ans);
  }
}

// AC, grafo, sort dsu
