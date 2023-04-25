
/*
 * iagorrr ;)
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define lessp(a, b) (a.priority > b.priority)
#define greaterp(a, b) (a.priority < b.priority)
#define exch(a, b)  {Item_st c = a; a = b; b = c;}
typedef struct Item_st {
  int value;
  int priority;
} Item_st;

typedef struct pq_st {
  int n;
  int last; // first free position.
  Item_st *heap;
} pq_st;

pq_st *pq_construct(int size) {
  /* Simply allocate the structre and heap */
  pq_st *pq = (pq_st*) malloc(sizeof(pq_st)); 
  pq->heap = (Item_st*) malloc(sizeof(Item_st)*(size+1));
  pq->last = 1; 
  pq->n = size;
  return pq;
}

void pq_upheap(pq_st *pq, int k) {
  Item_st v;
  v = pq->heap[k];
  while(k > 1 && lessp(pq->heap[k/2], v)){
    pq->heap[k] = pq->heap[k/2];
    k /= 2;
  }
  pq->heap[k] = v;

}

void pq_push(pq_st *pq, Item_st item) {
  // printf("push %d\n", pq->n);
  if(pq->last == pq->n+1){
      // find the leaf with lowest value.
    Item_st minvalue = pq->heap[pq->last-1];
    int minpos = pq->last-1;
    for(int i = pq->last-1; i >= 1; --i) {
      if(i*2 <= pq->last-1) break;
      if(lessp(pq->heap[i], minvalue)){
        minpos = i;
        minvalue = pq->heap[i];
      }
    }

    if(lessp(item, minvalue)) return;
    else {
      pq->heap[minpos] = item;
      pq_upheap(pq, minpos);
      return;
    }
  }
  
  pq->heap[pq->last++] = item;
  pq_upheap(pq, pq->last-1);
}

Item_st *pq_front(pq_st *pq){
  return &(pq->heap[1]);
}

void pq_downheap(pq_st *pq) {
  int k = 1;
  Item_st v = pq->heap[k];
  int n = pq->last -1;
  while(k <= n/2) { 
    int j = k*2;
    if(j < n  && lessp(pq->heap[j], pq->heap[j+1])) ++j;
    if(!lessp(v, pq->heap[j])) break;
    pq->heap[k] = pq->heap[j];
    k = j;
  }
  pq->heap[k] = v;
}
char pq_empty(pq_st *pq) {
  return pq->last == 1;
}
void pq_pop(pq_st *pq) {
  exch(pq->heap[pq->last-1], pq->heap[1]);
  pq->last--;
  pq_downheap(pq);
}

int main(void) {
  int o, p;
  pq_st *pq = pq_construct((int)1e2);
  int aux[100];
  int ap;
  while(scanf("%d %d", &o, &p)!= EOF) {
    if(o == 1) {
      pq_push(pq, (Item_st){p, p});
    } 
    else {
      ap = 0;
      while(ap < p && !pq_empty((pq))){
        printf("%d%c", pq_front(pq)->value, " \n"[ap==p-1]);
        aux[ap++] = pq_front(pq)->value;
        pq_pop(pq);
      }

      ap--;
      while(ap >= 0) {
        pq_push(pq, (Item_st){aux[ap], aux[ap]});
        ap--;
      }
    }
  }
}

// AC.
