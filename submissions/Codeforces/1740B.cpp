// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(deque <pair<ll,ll>> a, const ll n){
    sort(a.begin(), a.end());

    ll ans = 0;
    for(auto [x, y] : a)
        ans += 2*y;

    ans += a.back().first*2;

    return ans;
}
int main(){
    ll t;

    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        deque <pair<ll, ll>> a(n);
        for(int i = 0; i < n; ++i){
            ll x, y;
            cin >> x >> y;

            a[i].second = min(x, y);
            a[i].first = max(x, y);
        }

        cout << solve(a, n) << '\n';
    }
    return 0;
}

// Accepted. 