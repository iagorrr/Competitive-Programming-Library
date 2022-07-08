#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int lower_bound(vector <int> A, int x, int n);

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
    printf("Looking for lower bound of %d, is in the position %i.\n", x, lower_bound(A,x,A.size()));


    return 0;
}

/* 
    Is just to find the index of the of the first element lower or equal to 'x', in a 'vector', of size 'n'
*/
int lower_bound(vector <int> A, int x, int n){
    int l, r, mid;
    int ans;
    l = 0;
    r = n-1;

    while(l+1 < r){
        mid = (l+r)/2;

        if(A[mid] >= x){// Is a valid number, let's look if there is other in a lower index.
            r = mid;
        }
        else{// Isn't a valid number, so let's look into bigger elements, in higher positions.
            l = mid+1;
        }
    }

    // Getting the lower value possible.
    ans = r;
    if(A[l] >= x) ans = l;

    if(A[ans] >= x) return ans;
    else return -1;

}