/*
    Second version using a 'check()' function, that can be changed according to the parameters you want,
    and also looking for the lower value possbile.
*/
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int binary_search3(vector <int> A, int query);

int main(){
    vector <int> A;
    srand(time(NULL));

    for(int i = 0; i < 100; i++){
        A.push_back(rand()%100);
        printf("A[%i] = %i\n", i, A[i]);
    }

    sort(A.begin(), A.end());
    for(int i = 0; i < 100; i++){
        printf("A[%i] = %i\n", i, A[i]);
    }

    int query = rand()%100;
    printf("Searching for values higher than %i\n", query);
    printf("Lower position at: %i\n", binary_search3(A, query));

    return 0;
}


int binary_search3(vector <int> A, int query){
    int l = 0;
    int r = A.size();
    int mid;

    while(l < r){
        mid = (l + r)/2;

        if(A[mid] > query){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }

    return l;
}

/*
    If is sure that the element is in the vector, can use l-1 to show the last appear of the element.
*/