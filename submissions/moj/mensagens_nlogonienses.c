/*
 * iagorrr ;)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//                                          Item
#define eq(a, b) (a->id == b->id)
#define less(a, b) (a->id < b->id)
#define lesseq(a, b) (a->id <= b->id)
#define greater(a, b) (a->id > b->id)
#define greatereq(a, b) (a->id >= b->id)

typedef struct Item_st
{
  unsigned int id;
  char c;
} Item_st;

//                                         Linked list
typedef struct ll_node
{
  Item_st *item;
  struct ll_node *next;
} ll_node;
typedef struct ll_head
{
  int size;
  ll_node *first;
} ll_head;

ll_head *ll_head_init()
{
  ll_head *new = malloc(sizeof(ll_head));
  new->size = 0;
  new->first = NULL;
  return new;
}
ll_node *ll_node_init()
{
  ll_node *new = malloc(sizeof(ll_node));
  new->item = malloc(sizeof(Item_st));
  new->next = NULL;
  return new;
}

char ll_push(ll_head *head, Item_st *x)
{

  ll_node *cur = head->first;
  while (cur)
  {
    if (eq(cur->item, x))
      return 0;
    cur = cur->next;
  }

  ll_node *new = ll_node_init();
  *(new->item) = *x;
  new->next = head->first;
  head->first = new;
  return 1;
}

//                                        Hash Table
const unsigned MOD =1e5+7;
typedef struct ht_t
{
  ll_head *ht;
} ht_st;

#define hash_int(i) (i->id % MOD)

ht_st *ht_init()
{
  ht_st *new = malloc(sizeof(ht_st));
  new->ht = calloc(MOD, sizeof(ll_head));
  return new;
}

char ht_insert(ht_st *ht, Item_st *x)
{
  int hashit = hash_int(x);
  return ll_push(&(ht->ht[hashit]), x);
}

void merge(Item_st *v, int l, int r)
{ // [l,r]
  int mid = l + (r - l) / 2;
  int pl = l;
  int pr = mid + 1;
  int p = 0;
  Item_st *aux = (Item_st *)malloc(sizeof(Item_st) * (r - l + 1));

  while (pl <= mid && pr <= r)
  {
    if (less((v + pl), (v + pr)))
      aux[p++] = v[pl++];
    else
      aux[p++] = v[pr++];
  }

  while (pl <= mid)
    aux[p++] = v[pl++];

  while (pr <= r)
    aux[p++] = v[pr++];

  p = 0;
  for (int i = l; i <= r; ++i)
    v[i] = aux[p++];
}

void merge_sort(Item_st *v, int l, int r)
{ // [l, r]
  if (l >= r)
    return;

  int mid = l + (r - l) / 2;

  merge_sort(v, l, mid);
  merge_sort(v, mid + 1, r);

  merge(v, l, r);
}

int main(void)
{
  // insert only once.
  Item_st *ans = (Item_st *)malloc(sizeof(Item_st) * ((1 << 21) + 1));
  int anspos = 0;

  ht_st *ht = ht_init();
  unsigned id;
  char c;
  Item_st cur;
  while (scanf("%u %c", &id, &c) != EOF)
  {
    cur.id = id;
    cur.c = c;
    if(ht_insert(ht, &cur)){
      ans[anspos++] = cur;
    }
  }

  // sort message.
  merge_sort(ans, 0, anspos - 1);

  // output.
  char *fans = malloc(sizeof(char) * anspos);
  for (int i = 0; i < anspos; ++i)
    fans[i] = ans[i].c;
  fans[anspos] = '\0';
  printf("%s\n", fans);
}