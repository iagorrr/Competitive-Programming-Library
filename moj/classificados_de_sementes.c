// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>
typedef struct pair {
  int fst;
  int snd;
} pair;

typedef pair Item;
// #define less(a, b) a.fst == b.fst ? a.snd < b.snd : a.fst < b.fst
int less(Item a, Item b) {
  return a.fst == b.fst ? a.snd < b.snd : a.fst < b.fst; 
}

#define lessmerge(a, b) a.snd < b.snd
#define exchange(a, b)                                                         \
  Item t = a;                                                                  \
  a = b;                                                                       \
  b = t;

int partition(Item *v, int l, int r) {
  int i = l - 1;
  int j = r;
  Item pivot = v[r];
  for (;;) {
    while (less(v[++i], pivot));

    while (less(pivot, v[--j])) if(j==l) break;

    if (i >= j)
      break;

    exchange(v[i], v[j]);
  }
  exchange(v[i], v[r]);
  return i;
}

void quick_select(Item *v, int l, int r, int k) {
  if(l>=r) return;

  int i = partition(v, l, r);

  if (i > k)
    quick_select(v, l, i - 1, k);
  else if (i < k)
    quick_select(v, i+1, r, k);
}

void merge(Item *v, int l, int r){// [l,r]
    int mid = l + (r-l)/2;
    int pl = l;
    int pr = mid+1;
    int p = 0;
    Item *aux = malloc(sizeof(Item)*(r-l+1));

    while(pl <= mid && pr <= r){
        if(lessmerge(v[pl], v[pr]))
            aux[p++] = v[pl++];
        else
            aux[p++] = v[pr++];
    }

    while(pl <= mid)
        aux[p++] = v[pl++];

    while(pr <= r)
        aux[p++] = v[pr++];
    
    p = 0;
    for(int i = l; i <= r; ++i)
        v[i] = aux[p++];

    free(aux);
}

void merge_sort(Item *v, int l , int r){// [l, r]
    if(l >= r) return;

    int mid = l + (r-l)/2;

    merge_sort(v, l, mid);
    merge_sort(v, mid+1 ,r);

    merge(v, l, r);
}
int main(void) {
  // entrada.
  int k;
  scanf("%d", &k);
  Item *xs = (Item*) malloc(sizeof(Item)*((int)1e7+1));
  int cnt = 0;
  int n, s;
  while (scanf("%d %d", &s, &n) != EOF) {
    xs[cnt].fst = n;
    xs[cnt].snd = s;
    cnt++;
  }

  quick_select(xs, 0, cnt - 1, k);
  merge_sort(xs, 0, k-1);

  for (int i = 0; i < k; ++i) {
    printf("%d %d\n", xs[i].snd, xs[i].fst);
  }
}

// AC, quick select, sorting.
