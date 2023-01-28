// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

void solve(){
    ll n, k;
    cin >> n >> k;

    vector<pair<string, ll>> drugs;
    for(ll i = 0; i < n; ++i){
        string s;
        ll t;
        cin >> s >>t;

        drugs.emplace_back(s, t);
    }
    
    ll t = 1;
    while(k){
        for(auto [s, t_] : drugs){
            if(t % t_ == 0 and t >= t_){
                cout << t << ' ' << s << '\n';
                k--;
                if(k==0) return;
            }
        }
        ++t;
    }
}
int main(){ 
    fastio
    ll T;
    cin >> T;

    while(T--){
        solve();
    }
    return 0;
}

// AC.
