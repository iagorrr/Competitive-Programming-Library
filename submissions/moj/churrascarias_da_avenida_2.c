// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define lessp(a, b) (a.priority > b.priority)
#define greaterp(a, b) (a.priority < b.priority)
#define exch(a, b) \
  {                \
    Item_st c = a; \
    a = b;         \
    b = c;         \
  }

typedef struct Item_st {
  int priority;
  int v;
  int t;
} Item_st;

typedef struct pq_st
{
  int n;
  int last;
  Item_st *heap;
} pq_st;

pq_st *pq_construct(int size)
{
  pq_st *pq = (pq_st *)malloc(sizeof(pq_st));
  pq->heap = (Item_st *)malloc(sizeof(Item_st) * (size + 1));
  pq->last = 1;
  pq->n = size;
  return pq;
}

void pq_upheap(pq_st *pq, int k)
{
  Item_st v;
  v = pq->heap[k];
  while (k > 1 && lessp(pq->heap[k / 2], v))
  {
    pq->heap[k] = pq->heap[k / 2];
    k /= 2;
  }
  pq->heap[k] = v;
}

void pq_push(pq_st *pq, Item_st item)
{
  pq->heap[pq->last++] = item;
  pq_upheap(pq, pq->last - 1);
}

Item_st *pq_front(pq_st *pq)
{
  return &(pq->heap[1]);
}

void pq_downheap(pq_st *pq)
{
  int k = 1;
  Item_st v = pq->heap[k];
  int n = pq->last - 1;
  while (k <= n / 2)
  {
    int j = k * 2;
    if (j < n && lessp(pq->heap[j], pq->heap[j + 1]))
      ++j;
    if (!lessp(v, pq->heap[j]))
      break;
    pq->heap[k] = pq->heap[j];
    k = j;
  }
  pq->heap[k] = v;
}
char pq_empty(pq_st *pq)
{
  return pq->last == 1;
}
void pq_pop(pq_st *pq)
{
  exch(pq->heap[pq->last - 1], pq->heap[1]);
  pq->last--;
  pq_downheap(pq);
}
void solve(int n, int k) {
  int *notas = (int*) malloc(sizeof(int)*n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &notas[i]);
  }

  // insere os k primeiros.
  pq_st *pq = pq_construct(1e5+1);
  for(int i = 0; i < k; ++i) {
    pq_push(pq, (Item_st){notas[i], notas[i], i});
  }

  int antigo = 0;
  int novo = k;
  while(novo <= n) {
    // remove quem for das antigas
    while(!pq_empty(pq) && pq_front(pq)->t < antigo){
      pq_pop(pq);
    }
    Item_st menor  = *pq_front(pq);
    printf("%d%c", menor.v, " \n"[novo ==n]);
    if(novo == n) break;
    pq_push(pq, (Item_st) {notas[novo], notas[novo], novo});
    antigo++;
    novo++;
  }
}
int main() {
  int n=1, k=1;
  while (n && k) {
    scanf("%d %d", &n, &k); 
    if(n && k)
      solve(n, k); 
  }
}

// AC, priority queue.
