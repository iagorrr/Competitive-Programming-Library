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

void ll_push(ll_head *head, Item_st *x)
{
  ll_node *new = ll_node_init();
  *(new->item) = *x;
  if (head->size == 0)
  {
    head->first = new;
    head->size++;
    return;
  }
  ll_node *cur = head->first;
  ll_node *prev = NULL;
  while (cur)
  {
    if (eq(cur->item, x))
      return;
    if (greater(cur->item, x))
      break;
    prev = cur;
    cur = cur->next;
  }
  if (prev == NULL)
  {
    new->next = cur;
    head->first = new;
    head->size++;
    return;
  }

  if (cur == NULL)
  {
    prev->next = new;
    head->size++;
    return;
  }

  prev->next = new;
  new->next = cur;

  head->size++;
}

void ll_pop(ll_head *head, Item_st *x)
{

  ll_node *cur = head->first;
  ll_node *prev = NULL;
  while (cur)
  {
    if (eq(cur->item, x))
      break;
    if (greater(cur->item, x))
      return;
    prev = cur;
    cur = cur->next;
  }

  if (cur == NULL)
    return;

  if (prev)
  {
    prev->next = cur->next;
    head->size--;
    return;
  }
  else
  {
    head->first = cur->next;
    head->size--;
    return;
  }
}
char ll_find(ll_head *head, Item_st *x)
{
  ll_node *cur = head->first;
  while (cur)
  {
    if (eq(cur->item, x))
      return 1;
    if (greater(cur->item, x))
      break;
    cur = cur->next;
  }
  return 0;
}
//                                        Hash Table
typedef struct ht_t
{
  int mod;
  int size;
  int k;
  unsigned int (*hash_func)(Item_st *);
  ll_head *ht;
} ht_st;

unsigned int hash_int(Item_st *i)
{
  return i->id % (unsigned int)(1e5 + 7);
}

ht_st *ht_init(int mod, int k, unsigned int (*hash_func)(Item_st *))
{
  ht_st *new = malloc(sizeof(ht_st));
  new->mod = mod;
  new->size = 0;
  new->hash_func = hash_func;
  new->ht = (ll_head *)malloc(sizeof(Item_st) * mod);
  return new;
}

void ht_insert(ht_st *ht, Item_st *x)
{
  int hashit = ht->hash_func(x);
  ll_push(&(ht->ht[hashit]), x);
}

void ht_delete(ht_st *ht, Item_st *x)
{
  int hashit = ht->hash_func(x);
  ll_pop(&(ht->ht[hashit]), x);
}

char ht_find(ht_st *ht, Item_st *x)
{
  int hashit = ht->hash_func(x);
  return ll_find(&(ht->ht[hashit]), x);
}

int cmp(const void *a, const void *b)
{
  Item_st *ait = (Item_st *)a;
  Item_st *bit = (Item_st *)b;
  return ait->id > bit->id;
}
int main(void)
{
  Item_st *ans = (Item_st *)malloc(sizeof(Item_st) * ((1 << 21)));
  int anspos = 0;

  ht_st *ht = ht_init(1e5 + 7, 257, hash_int);
  unsigned id;
  char c;
  Item_st cur;
  while (scanf("%u %c", &id, &c) != EOF)
  {
    cur.id = id;
    cur.c = c;
    if (!ht_find(ht, &cur)){
      ans[anspos++] = cur;
      ht_insert(ht, &cur);
    }
  }

  qsort(ans, anspos, sizeof(Item_st), cmp);

  for (int i = 0; i < anspos; ++i)
    printf("%c", ans[i].c);

  printf("\n");
}