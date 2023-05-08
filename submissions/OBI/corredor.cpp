// iagorrr ;) O(N)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

// kadane algorithm.
ll solve(vll a , ll n){
    ll maxans = a[0];
    ll currmax = a[0];

    for(ll i = 1; i < n; ++i){
        currmax = max(a[i], currmax+a[i]);
        maxans = max(currmax, maxans);
    }

    return maxans;
}
int main(){
    ll n;
    cin >> n;

    vll a(n);
    for(auto &x : a) cin >> x;

    cout << solve(a, n) << endl;

    return 0;
}

// AC.