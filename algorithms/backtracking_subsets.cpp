/*
    Backtracking basic algorithm to generate every subset of a vector.

    O(2^n)

    Because for each position of the vector there is two states possible choose or not.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void backtracking(ll i, ll n, vector<bool> choosed){
    if(i == n){// Already checked every position
        for(ll j = 0; j < n; ++j)
            if(choosed[j]) cout << j << " ";

        cout << endl;
        return;    
    }

    
    // Consider both cases and check.
    choosed[i] = false;
    backtracking(i +1, n, choosed);

    choosed[i] = true;
    backtracking(i+1, n, choosed);

}

int main(){
    ll n;
    cin >> n;

    vector <bool> choosed(n, false);

    backtracking(0, n, choosed);
}
