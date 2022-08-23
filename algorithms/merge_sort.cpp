/*
    Merge sort : Merge sort

    O(NlogN)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    first half : [l, (l+r)/2]
    second half : [(l+r)/2+1, r]
*/
void merge(ll left, ll right, vector <ll> &values){
    ll middle = (left+right)/2;
    vector <ll> aux;

    ll p1 = left;
    ll p2 = middle+1;

    while(p1 <= middle && p2 <= right){
        if(values[p1] <= values[p2]){
            aux.push_back(values[p1]);
            p1++;
        }
        else{
            aux.push_back(values[p2]);
            p2++;
        }
    }   

    // If there is still elements in the first half.
    while(p1 <= middle){
        aux.push_back(values[p1]);
        p1++;
    }

    // If there is still elements in the second half.
    while(p2 <= right){
        aux.push_back(values[p2]);
        p2++;
    }

    // Change the values in the original vector.
    for(ll i = 0; i < aux.size(); ++i) values[left+i] = aux[i];
}

/*
    Inclusive interal of values = [vleft........vright]
*/
void mergeSort(ll left, ll right, vector <ll> &values){
    ll middle;

    if(left < right){// size != 1
        middle = (left+right)/2;
        
        // first half.
        mergeSort(left, middle, values);
        
        // second half.
        mergeSort(middle+1, right, values);

        merge(left, right, values);
    }
}

int main(){
    ll n;
    cin >> n;
    
    vector <ll> values(n);
    for(ll i = 0; i < n; ++i) cin >> values[i];

    mergeSort(0, n-1, values);

    for(ll i = 0; i < n; ++i) cout << values[i] << " ";
    cout << endl;
}
