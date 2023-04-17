/*
 * iagorrr ;)
 *
 * -    initialize:
 *          alloc the hash table with a given size, and sets size and mod.
 *
 *
 *
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int id;
    char *str;
} Item_st;

typedef struct ht_t
{
    int mod;
    int size;
    int (*hash_func)(Item_st);
    Item_st *ht;
} ht_st;

int foo_hash(Item_st x)
{
    printf("%d %s\n", x.id, x.str);
    return 0;
}
void ht_init(ht_st *ht, int mod, int (*hash_func)(Item_st))
{
    ht->mod = mod;
    ht->size = 0;
    ht->hash_func = hash_func;
    ht->ht = (Item_st *)malloc(sizeof(Item_st) * mod);
}

int main(void)
{
    ht_st myht;
    ht_init(&myht, 1e5 + 7, foo_hash);
    Item_st myit = {10, "iagorrr\0"};
    myht.hash_func(myit);
}