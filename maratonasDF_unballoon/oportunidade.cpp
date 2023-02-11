// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)

bool check(const vll &v, ll p){
    for(auto x : v){
        p += x;

        if(p < 0) return false;
    }
    return true;
}
int32_t main(void){ fastio;
    ll m, n;
    cin >> m >> n;

    vll v(n); for(auto &x : v) cin >> x;
    
    ll l = 0; ll r = m;
    ll ans = -1;
    while(l <= r){
        ll mid = l + (r-l)/2;

        if(check(v, mid)){ r = mid-1; ans = mid;}
        else  l = mid+1;

    }
    
    cout << ans << '\n';
}
// AC.
