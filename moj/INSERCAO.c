// iagorrr ;)
#include <stdio.h>
int v[(int)1e4*5+666];

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void print_array(int *v, int l, int r){// [l, r[
    for(int i = l; i < r; ++i)
        printf("%d%s", v[i], i == r-1 ? "\n": " ");
}

void insertion_sort(int *v, int l, int r){// [l , r[
    // put the lowest one at beginning.
    for(int i = r-1; i > l; --i)
        if(v[i] > v[i-1]) swap(&v[i], &v[i-1]);

    for(int i = l+1; i < r; ++i){
        int j = i;
        int t = v[j];
        // find the position to insert v[i].
        while(t <= v[j-1]){
            v[j] = v[j-1];
            --j;
        }
        v[j] = t;
    }
    
}
int main(){
    int n = -1;
    while(scanf("%d", &v[++n]) != EOF){}
    insertion_sort(&v[0], 0, n);
    print_array(&v[0], 0, n);
    return 0;
}

// AC.