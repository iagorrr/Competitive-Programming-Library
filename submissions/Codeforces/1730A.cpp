// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio = ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0):
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

ll solve(vll a, ll n, ll c){
    map<ll, ll> o;

    for(auto x : a) o[x]++;

    ll ans = 0;
    for(auto x : o){
        if(x.second > c) ans+= c;
        else ans += x.second;
    }
    return ans;
}
int main(){ 
    ll t;
    cin >> t;

    while(t--){
        ll n, c;
        cin >> n >> c;

        vll a(n);
        for(auto &x : a) cin >> x;

        cout << solve(a, n , c) << '\n';
    }
    return 0;
}
