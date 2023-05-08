// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
ll powi(ll x, ll n){
    ll ans = 1;
    for(int i = 0; i < n; ++i){
        ans*= x;
    }
    return ans;
}
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){
    fastio
    ll t;
    cin >> t;
    map<ll,ll> mapa;
    mapa[10] = 9;
    mapa[100] = 18;
    mapa[1000] = 27;
    mapa[10000] = 36;
    mapa[100000] = 45;
    mapa[1000000] = 54;
    while(t--){
        ll x;
        cin >> x;

        ll ans = 0;
        ll maxpos = to_string(x).size()-1;
        ans += x/powi(10, maxpos);
        ans += mapa[powi(10, maxpos)];
        cout << ans << '\n';
    }    
    return 0;
}

// AC.
