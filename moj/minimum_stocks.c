/*
  iagorrr ;)
*/
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int N = 150;    // tamanho alfabeto
int M = 10;     // tamanho max str

typedef struct trie_node {
  int value;                // value asigned to the string.
  bool final;               // if is the end of some word
  struct trie_node **links; // the chars it can be linked.
} tn_st;

tn_st *trie_init() {
  tn_st *trie = (tn_st *)malloc(sizeof(tn_st));
  trie->value = -1;
  trie->final = false;
  trie->links = (tn_st**) calloc(sizeof(tn_st**), N);
  // trie->links = (tn_st **) malloc(sizeof(tn_st **) * N);
  return trie;
}

void trie_insert(tn_st *trie, char *str, int value) {
  int i = 0;
  tn_st *cur = trie; 
  do {
    if (cur->links[(int)str[i]] == NULL){
      cur->links[(int)str[i]] = trie_init();
      // fprintf(stderr, "needed to alocate a new position for %c\n", str[i]);
    }
    cur = cur->links[(int)str[i]];

    // fprintf(stderr, "insert at char : %c, cur adress: %p\n", str[i], (void*)cur);
    i++;

    if (str[i] == '\0') {
      cur->final = true;
      cur->value = value;
      break;
    }

  }while (cur && str[i]);
}

int trie_get(tn_st *trie, char *str) {
  // fprintf(stderr, "tryng to get : %s\n", str);
  int i = 0;
  tn_st *cur = trie; 
  do {
    if (cur->links[(int)str[i]] == NULL)
      return -1;
    cur = cur->links[(int)str[i]];

    // fprintf(stderr, "get at char : %c, cur adress: %p\n", str[i], (void*)cur);
    i++;

    if (str[i] == '\0') {
      if(cur->final) return cur->value;
      else return -1;
    }

  }while (cur && str[i]);
  return -1;
}

void trie_delete(tn_st *trie, char *str) {
  int i = 0;
  tn_st *cur = trie; 
  do {
    if (cur->links[(int)str[i]] == NULL)
      return;
    cur = cur->links[(int)str[i]];

    // fprintf(stderr, "delete at char : %c, cur adress: %p\n", str[i], (void*)cur);
    i++;

    if (str[i] == '\0') {
      cur->final = false;
      cur->value = -1;
      return;
    }

  }while (cur && str[i]);
}
#define lessp(a, b) (a.priority > b.priority)
#define greaterp(a, b) (a.priority < b.priority)
#define exch(a, b) \
  {                \
    Item_st c = a; \
    a = b;         \
    b = c;         \
  }
typedef struct Item_st
{
  char name[11];
  int priority;
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
  if (pq->last == pq->n + 1)
  {
    Item_st minvalue = pq->heap[pq->last - 1];
    int minpos = pq->last - 1;
    for (int i = pq->last - 1; i >= 1; --i)
    {
      if (i * 2 <= pq->last - 1)
        break;
      if (lessp(pq->heap[i], minvalue))
      {
        minpos = i;
        minvalue = pq->heap[i];
      }
    }

    if (lessp(item, minvalue))
      return;
    else
    {
      pq->heap[minpos] = item;
      pq_upheap(pq, minpos);
      return;
    }
  }

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

int main(void) {
  tn_st* trie = trie_init();
  pq_st *pq  = pq_construct(1e6+1);
  int q; scanf("%d", &q);
  for(int i = 1; i <= q; ++i){
    int op; scanf("%d", &op);
    // fprintf(stderr, "op: %d\n", op);
    if(op < 3) {
      char str[11];
      int value;
      scanf("%s %d", str, &value);
      // fprintf(stderr, "str: %s value: %d", str, value);
      trie_insert(trie, str, value);
      Item_st item;
      item.priority=value;
      strcpy(item.name, str);
      pq_push(pq, item);
    }
    else {
      scanf("%*s");
      while(true) {
        // fprintf(stderr, "truezn\n");
        Item_st front = *pq_front(pq);
        // fprintf(stderr, "front: %s\n", front.name);
        int value = trie_get(trie, front.name);
        if(value != front.priority) pq_pop(pq);
        else break;
      }
      Item_st front = *pq_front(pq);
      printf("%s %d\n", front.name, i);
      pq_pop(pq);
      trie_delete(trie, front.name);
    }
  }
}

// AC, priority queue, hash table, trie