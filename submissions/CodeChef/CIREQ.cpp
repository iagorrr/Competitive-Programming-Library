// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

ll solve(vector<ll> a, ll n){
    vector<vector<ll>> b;
    
    sort(a.begin(), a.end());

    for(int i = 0; i < n; ++i){
        bool f = false;
        for(int j = 0; j < (int)b.size(); ++j){
            if(b[j].size() < a[i]){
                f = true;
                b[j].push_back(a[i]);
                break;
            }
        }

        if(!f){
            b.push_back({a[i]});
        }
    }

    return (ll) b.size();
}

int main(){ 
    fastio
    ll T;
    cin >> T;
    
    while(T--){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for(auto &x : a) cin >> x;

        cout << solve(a, n) << '\n';
    }

    return 0;
}

// AC.
