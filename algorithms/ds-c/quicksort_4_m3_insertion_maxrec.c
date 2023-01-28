/*
 * iagorrr ;)
 * quicksort optimization to avoid worst cases, using '3 pivots'.
 * and using insertion sort to arrays shorter than 32 elements.
 */
#include <stdio.h>
#include <stdlib.h>

#define less(a, b) a < b 
#define lessexchange(a, b) {if(less(a,b)) exchange(a, b);}
#define greater(a, b) a > b
#define greaterexchange(a,b) {if(greater(a,b)) exchange(a, b);}
#define exchange(a, b) {Item t = a; a = b; b = t;}

typedef int Item;

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

void merge_sort(Item *v, int l , int r){// [l, r]
    if(l >= r) return;

    int mid = l + (r-l)/2;

    merge_sort(v, l, mid);
    merge_sort(v, mid+1 ,r);

    merge(v, l, r);
}

void insertion_sort(Item *v, int l, int r){// [l , r]
    for(int i = r; i > l; --i)
        if(v[i] > v[i-1]) exchange(v[i], v[i-1]);

    for(int i = l+1; i <= r; ++i){
        int j = i;
        int pivot = v[j];
    
        while(less(pivot, v[j-1])){
            v[j] = v[j-1];
            --j;
        }

        v[j] = pivot;
    }
}
int partition(Item *v, int l, int r){ // [l, r]
    int i = l - 1; 
    int  j = r; 
    Item pivot = v[r];
    for(;;){
        while(less(v[++i], pivot)); 

        while(greater(v[--j], pivot));

        if(i >= j) break; 

        exchange(v[i], v[j]);
    }
	exchange(v[i], v[r]);
    return i; 
}

int mylog2(int x)
{
    int ans = 0;

    while(x <<= 1) ++ans;

    return 2;
}

int max_recursion_reached;
void quicksort_func(Item *v,int l, int r, int c_rec) // [l, r]
{

    if(r -l <= 32 || max_recursion_reached) return;
    
    if(c_rec == 0)
    {
        max_recursion_reached = 1;
        return;
    }

    int mid = l + (r-l)/2;

    lessexchange(v[mid], v[r]);
    greaterexchange(v[l], v[mid]);
    lessexchange(v[r], v[mid]);

    int i = partition(v, l, r);

    quicksort_func(v, l, i, c_rec-1);
    quicksort_func(v, i+1, r, c_rec-1);
}

void quicksort(Item*v ,int l, int r)
{
    int max_recursion = mylog2(r-l+1);

    quicksort_func(v, l, r, max_recursion);

    if(max_recursion_reached) merge_sort(v, l, r);
    else insertion_sort(v, l, r);
}

