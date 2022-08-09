// iagorrr O(N)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll k){
    ll ans = 0;
    for(ll i = 0; i < (2<<n); ++i){
        ll cnt = 0;
        for(ll j = 1; j < n; ++j){
            if((1<<j) & i) cnt ++;
            if(cnt > 4) break;
        }
        if(cnt < k)
    }
}

int main(){
    ll n, k;

    cin >> n >> k;

    cout << solve(n, k) << endl;
    return 0;
}

// Accepted.
