// iagorrr ;)
#include <stdio.h>
int v[(int)1e3+666];
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
    for(int i = l; i < r; ++i){
        int min = i;
        for(int j = i +1; j < r; ++j)
            min = v[j] < v[min] ? j : min;
        

        swap(&v[i], &v[min]);
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