/*
 * iagorrr ;)
 * quicksort optimization to avoid worst cases, using '3 pivots'.
 * and using insertion sort to arrays shorter than 32 elements.
 */
#include <stdio.h>

#define less(a, b) a < b 
#define lessexchange(a, b) {if(less(a,b)) exchange(a, b);}
#define greater(a, b) a > b
#define greaterexchange(a,b) {if(greater(a,b)) exchange(a, b);}
#define exchange(a, b) {Item t = a; a = b; b = t;}

typedef int Item;

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

void quicksort_func(Item *v,int l, int r) // [l, r]
{
    if(r -l <= 32) return;

    int mid = l + (r-l)/2;

    lessexchange(v[mid], v[r]);
    greaterexchange(v[l], v[mid]);
    lessexchange(v[r], v[mid]);

    int i = partition(v, l, r);

    quicksort_func(v, l, i);
    quicksort_func(v, i+1, r);
}

void quicksort(Item*v ,int l, int r)
{
    quicksort_func(v, l, r);
    insertion_sort(v, l, r);
}
