/*
 * iagorrr ;)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//                                          Item
#define eq(a, b) (a.id == b.id)
#define less(a, b) (a.id < b.id)
#define lesseq(a, b) (a.id <= b.id)
#define greater(a, b) (a.id > b.id)
#define greatereq(a, b) (a.id >= b.id)
const int MOD = 1e5 + 7;
typedef struct Item_st
{
    int id;
    char fn[70];
    char ln[70];
    char bd[70];
    char pn[70];
} Item_st;

//                                         Linked list
typedef struct ll_node
{
    Item_st item;
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

// 0 se ok, 1 se inserir repetido.
int ll_push(ll_head *head, Item_st x)
{
    ll_node *new = ll_node_init();
    new->item = x;
    if (head->size == 0)
    {
        head->first = new;
        head->size++;
        return 0;
    }
    ll_node *cur = head->first;
    ll_node *prev = NULL;
    while (cur)
    {
        if (eq(cur->item, new->item))
            return 1;
        if (greater(cur->item, new->item))
            break;
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL)
    {
        new->next = cur;
        head->first = new;
        head->size++;
        return 0;
    }

    if (cur == NULL)
    {
        prev->next = new;
        head->size++;
        return 0;
    }

    prev->next = new;
    new->next = cur;

    head->size++;
    return 0;
}

// 0 se ok, 1 se deletar algo que não existe.
int ll_pop(ll_head *head, Item_st x)
{
    ll_node *cur = head->first;
    ll_node *prev = NULL;
    while (cur)
    {
        if (eq(cur->item, x))
            break;
        if (greater(cur->item, x))
            return 1;
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL)
        return 1;

    if (prev)
    {
        prev->next = cur->next;
        head->size--;
        return 0;
    }
    else
    {
        head->first = cur->next;
        head->size--;
        return 0;
    }
}
char ll_find(ll_head *head, Item_st x)
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

Item_st *ll_find_by_id(ll_head *head, int id)
{
    ll_node *cur = head->first;
    while (cur)
    {
        if (cur->item.id == id)
            return &(cur->item);
        cur = cur->next;
    }
    return NULL;
}

//                                        Hash Table
typedef struct ht_t
{
    int mod;
    int size;
    int k;
    int (*hash_func)(Item_st);
    ll_head *ht;
} ht_st;

// polynomial rolling hash.
int f(char c) { return c + 1; }
int hash_fn(Item_st x)
{
    const int p = 257;
    const int q = MOD;
    int h = 0;
    int i = 0;
    while (x.fn[i++] != '\0')
    {
        h = (h * p) % q;
        h = (h + f(x.fn[i])) % q;
    }
    return h;
}
int hash_ln(Item_st x)
{
    const int p = 257;
    const int q = MOD;
    int h = 0;
    int i = 0;
    while (x.ln[i++] != '\0')
    {
        h = (h * p) % q;
        h = (h + f(x.ln[i])) % q;
    }
    return h;
}
int hash_bd(Item_st x)
{
    const int p = 257;
    const int q = MOD;
    int h = 0;
    int i = 0;
    while (x.bd[i++] != '\0')
    {
        h = (h * p) % q;
        h = (h + f(x.bd[i])) % q;
    }
    return h;
}
int hash_pn(Item_st x)
{
    const int p = 257;
    const int q = MOD;
    int h = 0;
    int i = 0;
    while (x.pn[i++] != '\0')
    {
        h = (h * p) % q;
        h = (h + f(x.pn[i])) % q;
    }
    return h;
}
int hash_id(Item_st x)
{
    return x.id % MOD;
}

ht_st *ht_init(int mod, int k, int (*hash_func)(Item_st))
{
    ht_st *new = malloc(sizeof(ht_st));
    new->mod = mod;
    new->size = 0;
    new->hash_func = hash_func;
    new->ht = calloc(mod, sizeof(ll_head));
    return new;
}

// 0 se ok, 1 se inserir repetido
int ht_insert(ht_st *ht, Item_st x)
{
    int hashit = ht->hash_func(x);
    return ll_push(&(ht->ht[hashit]), x);
}

// 0 se ok, 1 se pedir pra deletar 1 que não existe.
int ht_delete(ht_st *ht, Item_st x)
{
    int hashit = ht->hash_func(x);
    return ll_pop(&(ht->ht[hashit]), x);
}

char ht_find(ht_st *ht, Item_st x)
{
    int hashit = ht->hash_func(x);
    return ll_find(&(ht->ht[hashit]), x);
}
Item_st *ht_find_by_id(ht_st *ht, Item_st x)
{
    int hashit = ht->hash_func(x);
    return ll_find_by_id(&(ht->ht[hashit]), x.id);
}
void ht_query(ht_st *ht, Item_st x)
{
    int pos = ht->hash_func(x);

    ll_node *cur = ht->ht[pos].first;
    int i = 0;
    int *ans = malloc(sizeof(int) * (int)MOD);
    while (cur)
    {

        // printf("%d %s %s %s %s\n", cur->item.id, cur->item.fn, cur->item.ln, cur->item.bd, cur->item.pn);
        int match = 1;
        if (x.id && cur->item.id != x.id)
        {
            match = 0;
            break;
        }
        if (x.fn[0] != 0 && strcmp(cur->item.fn, x.fn) != 0)
        {
            match = 0;
        }
        if (x.ln[0] != 0 && strcmp(cur->item.ln, x.ln) != 0)
        {
            match = 0;
        }
        if (x.bd[0] != 0 && strcmp(cur->item.bd, x.bd) != 0)
        {
            match = 0;
        }
        if (x.pn[0] != 0 && strcmp(cur->item.pn, x.pn) != 0)
        {
            match = 0;
        }

        if (match)
        {
            ans[i] = cur->item.id;
            ++i;
        }
        cur = cur->next;
    }

    if (i)
    {
        for (int j = 0; j < i; ++j)
            printf("%d ", ans[j]);
    }
    printf("\n");
    free(ans);
}

int main(void)
{
    char cmd[6];
    ht_st *ht_fn = ht_init(MOD, 257, hash_fn);
    ht_st *ht_ln = ht_init(MOD, 257, hash_ln);
    ht_st *ht_bd = ht_init(MOD, 257, hash_bd);
    ht_st *ht_pn = ht_init(MOD, 257, hash_pn);
    ht_st *ht_id = ht_init(MOD, 257, hash_id);

    while (scanf("%s", cmd) != EOF)
    {
        int id;
        Item_st cur;
        Item_st *found;
        switch (cmd[0])
        {
        case ('a'):
            scanf("%d %s %s %s %s", &cur.id, cur.fn, cur.ln, cur.bd, cur.pn);
            // printf("%d %s %s %s %s\n", cur.id, cur.fn, cur.ln, cur.bd, cur.pn);
            if (ht_find_by_id(ht_id, cur))
            {
                printf("ID %d ja cadastrado.\n", cur.id);
                break;
            }
            ht_insert(ht_fn, cur);
            ht_insert(ht_ln, cur);
            ht_insert(ht_bd, cur);
            ht_insert(ht_pn, cur);
            ht_insert(ht_id, cur);
            break;
        case 'd':
            scanf("%d", &id);
            cur.id = id;
            found = ht_find_by_id(ht_id, cur);
            if (found == NULL)
            {
                printf("ID %d nao existente.\n", id);
                break;
            }
            ht_delete(ht_fn, *found);
            ht_delete(ht_ln, *found);
            ht_delete(ht_bd, *found);
            ht_delete(ht_pn, *found);
            ht_delete(ht_id, *found);
            break;
        case 'i':
            scanf("%d", &id);
            cur.id = id;
            found = ht_find_by_id(ht_id, cur);
            if (found == NULL)
            {
                printf("ID %d nao existente.\n", id);
                break;
            }
            printf("%s %s %s %s\n", found->fn, found->ln, found->bd, found->pn);
            break;
        case 'q':
            scanf("%*c");
            char input[200];
            scanf("%[^\n]s", input);
            Item_st match = {0, {0}, {0}, {0}, {0}};
            // printf("fullcmd : [%s]\n", fullcmd);
            // printf("match: %s %s %s %s\n", match.fn, match.ln, match.bd, match.pn);
            char *cur = strtok(input, " ");
            while (cur != NULL)
            {
                if (cur[0] == 'b')
                {
                    strcpy(match.bd, &cur[3]);
                }
                else if (cur[0] == 'f')
                {
                    strcpy(match.fn, &cur[3]);
                }
                else if (cur[0] == 'l')
                {
                    strcpy(match.ln, &cur[3]);
                }
                else if (cur[0] == 'p')
                {
                    strcpy(match.pn, &cur[3]);
                }
                cur = strtok(NULL, " ");
            }

            // printf("match: [%s] [%s] [%s] [%s]\n", match.fn, match.ln, match.bd, match.pn);
            if (match.fn[0] != 0)
            {
                // printf("query fn\n");
                ht_query(ht_fn, match);
            }
            else if (match.ln[0] != 0)
            {
                // printf("query ln\n");
                ht_query(ht_ln, match);
            }
            else if (match.bd[0] != 0)
            {
                // printf("query bd\n");
                ht_query(ht_bd, match);
            }
            else if (match.pn[0] != 0)
            {
                // printf("query pn\n");
                ht_query(ht_pn, match);
            }
        default:
            break;
        }
    }
}

// AC, hash table.