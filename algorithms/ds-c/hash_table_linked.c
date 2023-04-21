/*
 * iagorrr ;)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//                                          Item
#define eq(a, b) (strcmp(a->str, b->str) == 0)
#define less(a, b) (strcmp(a->str, b->str) < 0)
#define lesseq(a, b) (strcmp(a->str, b->str) <= 0)
#define greater(a, b) (strcmp(a->str, b->str) > 0)
#define greatereq(a, b) (strcmp(a->str, b->str) >= 0)

typedef struct Item_st
{
    int id;
    char *str;
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
    new->next = NULL;
    return new;
}
void ll_debug(ll_head *head)
{
    ll_node *cur = head->first;
    while (cur)
    {
        printf("%s -> ", cur->item->str);
        cur = cur->next;
    }
    printf("NULL\n");
}
void ll_push(ll_head *head, Item_st *x)
{
    ll_node *new = ll_node_init();
    new->item = x;
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
    int (*hash_func)(Item_st *);
    ll_head *ht;
} ht_st;

// polynomial rolling hash.
inline int f(char c) { return c + 1; }
int hash_str(Item_st *x)
{
    const int p = 257;
    const int q = 1e5 + 7;
    int h = 0;
    int i = 0;
    while (x->str[i++] != '\0')
    {
        h = (h * p) % q;
        h = (h + f(x->str[i])) % q;
    }
    return h;
}

ht_st *ht_init(int mod, int k, int (*hash_func)(Item_st *))
{
    ht_st *new = malloc(sizeof(ht_st));
    new->mod = mod;
    new->size = 0;
    new->hash_func = hash_func;
    new->ht = calloc(mod, sizeof(ll_head));
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

int main(void)
{
    ht_st *ht = ht_init(1e5 + 7, 257, hash_str);
    while (1)
    {
        printf("1: insert\n2: delete\n3: find\nopt: ");
        int opt;
        scanf("%d", &opt);

        Item_st *x = malloc(sizeof(Item_st));
        x->str = malloc(sizeof(char) * 20);
        printf("str: ");
        scanf("%s", x->str);
        switch (opt)
        {
        case 1:
            ht_insert(ht, x);
            break;
        case 2:
            ht_delete(ht, x);
            break;
        case 3:
            printf("find: %d\n", ht_find(ht, x));
            break;
        }
    }
}
