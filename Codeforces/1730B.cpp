// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;

inline ld check(ld x, const vll a, const vll d){
    ld maxv = -1;
    for(ll i = 0; i < (ll)a.size(); ++i) maxv = max(maxv, d[i] + abs(a[i]-x));
    return maxv;
    
}

// our epsilon, needed to precion error problems.
ld EPS = 1e-8;
inline ld solve(const vll a, const vll d, const ll n){
    ld l = 0, r= 1e8;
    while(r-l >= EPS){// can't compare it directly.
        ld m = (l+r)/2;
        if(check(m, a , d) >= check(m+EPS, a, d)) l = m;
        else r = m;
    }
    return l;
}
int32_t main(){ 
    fastio
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vll a(n);
        vll d(n);
        for(auto &x : a) cin >> x;
        for(auto &x : d) cin >> x;

        cout.precision(7);
        cout << solve(a, d, n) << '\n';
    }

    return 0;
}

// Accepted.
