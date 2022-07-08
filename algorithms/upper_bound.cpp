#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int upper_bound(vector <int> A, int x, int n);

int main(){
    srand(time(NULL));

    vector <int> A;
    for(int i = 0; i < 20; i++){
        A.push_back(rand()%10);
    }


    sort(A.begin(), A.end());
    for(int i = 0; i < 20; i++){
        printf("A[%i] : %d\n", i, A[i]);
    }

    int x = rand()%10;
    printf("Looking for upper bound of %d, is in the position %i.\n", x, upper_bound(A,x,A.size()));


    return 0;
}

/* 
    Is just to find the index of the of the last element bigger or equal to 'x', in a 'vector', of size 'n'
*/
int upper_bound(vector <int> A, int x, int n){
    int l, r, mid;

    l = 0;
    r = n-1;

    while(l < r){
        mid = (l+r)/2;

        if(x < A[mid]){// Is a valid number, let's look if there is other in a lower index.
            r = mid;
        }
        else{// Isn't a valid number, so let's look into bigger elements, in higher positions.
            l = mid+1;
        }
    }
    printf("l is %i\n", l);
    if(A[l] == x){// Extreme case.

        return l;
    }
    if(A[l-1] == x){// Is the higher value next to x, but maybe not x.
        return l-1;
    }
    else{
        return -1;
    }
}