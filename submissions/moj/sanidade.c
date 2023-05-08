/*
	iagorrr ;)
 */
#include <stdio.h>
#include <stdlib.h>
#define less(a, b) a.value < b.value
#define lesseq(a, b) a.value <= b.value
#define exchange(a , B) {Item t = a; a = b; b = t;}

typedef struct Item
{
    int value;
    int prev;
    int next;
} Item;

void merge(Item *v, int l, int r);

void merge_sort(Item *v, int l , int r);

int bb(Item *v, int l, int r, int x)
{
    while(l <= r)
    {
        int mid = l + (r-l)/2;
        if(v[mid].value == x) return mid;
        else if(v[mid].value > x) r = mid -1;
        else l = mid+1;
    }
    return -1; // 0-0
}
Item input[(int)1e5+666];
Item v[(int)1e5+666];
int main()
{
    int n, prev, next;
    int p = 0;
    while(scanf("%x %x %x", &input[p].value, &input[p].prev, &input[p].next) != EOF)
    {
        v[p] = input[p];
        ++p;
    }

    Item ptr1 = v[0]; Item ptr2 = v[1];

    merge_sort(&v[0], 0, p-1);


    int current = ptr1.value;
    int pt1 = 0, pt2 = 1;
    while(1)
    {
        if(current == ptr2.value)
        {
            pt1 = 1;
            break;
        }
        int cn = v[bb(&v[0], 0, p-1, current)].next; if (cn == 0) break;
        int npv = v[bb(&v[0], 0, p-1, cn)].prev;
        // printf("current: %x, next: %x, next.prev: %x\n", current, cn, npv);
        if(current != npv)
        {
            break;
        }
        current = cn;
    }

    /* 
    current = ptr2.value;
    while(1)
    {
        if(current == ptr1.value)
        {
            pt2 = 1;
            break;
        }
        int cp = v[bb(&v[0], 0, p-1, current)].prev; if (cp == 0) break;
        int ppn = v[bb(&v[0], 0, p-1, cp)].next;
        // printf("current: %x, previous: %x, previous next: %x\n", current, cp, ppn);
        if(current != ppn)
        {
            break;
        }
        current = cp;
    }
    */
    printf("%s\n", pt2 && pt1 ? "sana" : "insana");
}

void merge_sort(Item *v, int l , int r){// [l, r]
    if(l >= r) return;

    int mid = l + (r-l)/2;

    merge_sort(v, l, mid);
    merge_sort(v, mid+1 ,r);

    merge(v, l, r);
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

// AC.
