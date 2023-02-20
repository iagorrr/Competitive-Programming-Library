// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int32_t main(void){
    ll n, d; cin >> n >> d;
    vector<ll> a(n); for(auto &x : a) cin >> x;


    ull ans = 0ULL;
    for(int i = 0; i < n; ++i){
        auto it = upper_bound(a.begin(), a.end(), a[i]+d);

        ll m = it - a.begin(); // last position that we can consider.
        m = m-i; // range considering our current positino.

        if(m >= 3)
            ans += ((m-1) * (m-2))/2; // combine the elements 2 by two.
    }

    cout << ans << '\n';
}

// AC.
