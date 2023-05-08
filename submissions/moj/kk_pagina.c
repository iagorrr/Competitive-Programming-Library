// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>
typedef int Item;

#define less(a, b) a < b 
#define exchange(a, b) Item t = a; a = b; b = t;
#define min(a, b) (a > b ? a : b)
int partition(Item *v, int l, int r){
    int i = l - 1; 
    int  j = r; 
    Item pivot = v[r];
    for(;;){
        while(less(v[++i], pivot)); 

        while(less(pivot, v[--j])) if(j==l) break;

        if(i >= j) break; 

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
int main(void) {
  int n, p, x; scanf("%d %d %d", &n, &p, &x);
  Item *xs = (Item*) malloc(sizeof(Item)*n + 1);
  for(int i = 0; i < n; ++i) scanf("%d", &xs[i]);

  int s = (p+1)*x - 1; // ultima pagina que quero.
  if (s > n-1) s = n-1; 
  quick_select(xs, 0, n-1, s);

  int k = p*x; // primeira página que quero
  quick_select(xs, 0, s, k);

  merge_sort(xs, k, s);
  for(int i = k; i <= s; ++i) {
    printf("%d\n", xs[i]);
  }
}

// AC, quick select, sorting.
