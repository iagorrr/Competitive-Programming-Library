// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


inline void solve(vector<ll> a, const ll n){
    if(n == 1){
        cout << 0 << '\n';
        return;
    }
    // make every value equal, or to a[n] or to a[1].
    vector<pair<ll,ll>> ans;


    ans.push_back({1, n});
    if(a[0]+a[n-1] % 2 == 0) a[0] = a[n-1];
    else a[n-1] = a[0];

    for(ll i = 1; i < n-1; ++i){
        if((a[i] += a[0]) % 2) {
            ans.push_back({1, i+1});
        }
        else {
            ans.push_back({i+1, n});
        }
    }

    cout << ans.size() << '\n';
    for(auto x : ans) cout << x.first << ' ' << x.second << '\n';
}
int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for(auto &x : a) cin >> x;

        solve(a, n);
    }

    return 0;
}

// Accepted