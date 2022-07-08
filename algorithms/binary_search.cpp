#include <bits/stdc++.h>
#include <ctime>

using namespace std;
int binary_search(vector <int> array, int n, int query);

int main(){
    srand(time(NULL));

    vector <int> A;

    for(int i = 0; i < 100; i++){
        A.push_back(rand()%100);
    }

    sort(A.begin(), A.end());
    for(int i = 0; i < 100; i++){
        printf("A[%i] = %i\n", i, A[i]);
    }

    int query = rand()%100;
    printf("Looking for the element %i\n", query);
    printf("First appear in the position %i\n", binary_search(A, A.size(), query));
    return 0;
}

/*
    This specific function is to return the position of the element, (if is in the array.)
*/
int binary_search(vector <int> array, int n, int query){
    int l = 0;
    int r = n -1;
    int mid;

    while(l < r){
        mid = (l + r)/2;

        if(array[mid] == query)
            return mid;
        
        if(array[mid] < query)
            l = mid + 1;
        else
            r = mid;
    }

    return -1;
}