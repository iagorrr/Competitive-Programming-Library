// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>
typedef struct pair{
  int fst;
  int snd;
} pair;
typedef pair Item;

int less(Item a, Item b) {
  if(a.fst == b.fst) return a.snd < b.snd;
  return a.fst < b.fst;
}
#define exchange(a , B) {Item t = a; a = b; b = t;}

void merge(Item *v, int l, int r){// [l,r]
    int mid = l + (r-l)/2;
    int pl = l;
    int pr = mid+1;
    int p = 0;
    Item *aux = (Item*) malloc(sizeof(Item)*(r-l+1));

    while(pl <= mid && pr <= r){
        if(less(v[pl], v[pr]))
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

int main() {
  char *s = (char*) malloc(sizeof(char)*1e3*1 + 1);
  int n;
  while(scanf("%s%n", s, &n) != EOF) {
    int *h = (int*)calloc(257, sizeof(int));

    for(int i = 0; i < n; ++i) {
      h[(int)s[i]]++;
    }
    
    pair *v = (pair*) malloc(sizeof(pair)*257);
    for(int i = 0; i < 257; ++i) v[i].fst = 1003;

    for(int i = 1; i < 257; ++i) {
      v[i].snd = i;
      v[i].fst = (h[i] == 0 ? 1003 : h[i]);
    }

    merge_sort(v, 0, 257-1);

    for(int i = 0; i < 257; ++i) {
      if(v[i].fst == 1003) continue;
      printf("%d %d\n", v[i].snd, v[i].fst);
    }
    printf("\n");
  }
}

// AC.
