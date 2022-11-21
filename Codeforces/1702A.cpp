// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

vector<ll> p10 {1, 10, 100, 1000, (ll)1e4, (ll)1e5, (ll)1e6, (ll)1e7, (ll)1e8, (ll)1e9, (ll)1e10};
ll solve(ll x){
    ll ans;
    for(auto p1 : p10){
        if(p1 > x) break;
        ans = x-p1;
    }
    return ans;
}
int main(){ 
    fastio
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i){
        ll n;
        cin >> n;

        cout << solve(n) << '\n';
    }
    return 0;
}

// AC.
