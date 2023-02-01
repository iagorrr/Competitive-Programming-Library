typedef int Item;

#define less(a, b) (a < b)
#define eq(a, b) (a == b)

// naive implementation, returns a position where x appears.
int binary_search(Item *v, int l, int r, Item x){
    int mid;
    while(l <= r){
        mid = l + (r-l)/2;
        if(eq(v[mid], x)) return mid;
        else if(less(v[mid], x)) l = mid+1;
        else r = mid-1;
    }

    return -1;
}


