
/*
 * iagorrr ;)
 * pq implementation based in the Algorithms in C - Sedgewick
 *
 *  Construct a priority queue given N items.
 *  Insert a new item.
 *  Remove the largest item.
 *  Replace the largest item with a new.
 *  Change the priority of an item.
 *  Delete an arbitrary specified item.
 *  Join two priority queues into one large one. 
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
  int prior_min;
} pq_st;

pq_st *pq_construct(int size) {
  /* Simply allocate the structre and heap */
  pq_st *pq = (pq_st*) malloc(sizeof(pq_st)); 
  pq->heap = (Item_st*) malloc(sizeof(Item_st)*(size+1));
  pq->last = 1; 
  pq->n = size;
  pq->prior_min = 0;
  return pq;
}

void pq_upheap(pq_st *pq, int k) {
  if(k <= 1) return;

  if(lessp(pq->heap[k/2], pq->heap[k])) {
    exch(pq->heap[k/2], pq->heap[k]);
    pq_upheap(pq, k/2);
  }
}

void pq_push(pq_st *pq, Item_st item) {
  /* 
    insert at the first free position
    increment the free position
    calls upheap
  */
  if(pq->last == pq->n+1){
    if(lessp(item, pq->heap[pq->prior_min])) return;
  }
  if(!pq->prior_min || lessp(item, pq->heap[pq->prior_min])) pq->prior_min = pq->last;

  pq->heap[pq->last++]  = item;
  pq_upheap(pq, pq->last-1);
}

Item_st *pq_front(pq_st *pq){
  /*Simply return the 'greatest value'*/
  return &(pq->heap[1]);
}

void pq_downheap(pq_st *pq) {
  /*
   * goes from root to leaf fixing the heap. 
  */
  int k = 1;
  int n = pq->last -1;
  while(k <= n/2) { // until the parent of the last
    int j = k*2;
    if(j < n  && lessp(pq->heap[j], pq->heap[j+1])) ++j;
    if(!lessp(pq->heap[k], pq->heap[j])) break;
    exch(pq->heap[k], pq->heap[j]);
    k = j;
  }
}
char pq_empty(pq_st *pq) {
  return pq->last == 1;
}
void pq_pop(pq_st *pq) {
  exch(pq->heap[pq->last-1], pq->heap[1]);
  pq->last--;
  pq_downheap(pq);
}

void pq_debug(pq_st *pq) {
  for(int i = 1; i <= pq->last-1; ++i) {
    printf("(%d, %d), ", i, pq->heap[i].value);
  }
}
int main(void) {
  int o, p;
  pq_st *pq = pq_construct((int)1e7+1);
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
// TLE.
