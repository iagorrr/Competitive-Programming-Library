// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
void solve(vector<pair<ll,ll>> a, ll n){
    sort(a.begin()+1, a.end());
    vector<pair<ll,ll>> ans; 
    for(int i = 1; i < n; ++i){
        auto [f, p] = a[i];
        auto [f2, p2] = a[i+1];
        
        // already satisfied.
        if(f2%f == 0) ans.push_back({p2, 0});
        
        // takes the first that satisfies.
        else{
            ans.push_back({p2, (f2/f + 1)*f - f2});
            a[i+1].first = (f2/f +1)*f;
        }

    }

    cout << n-1<< '\n';
    for(auto [p, v] : ans)
        cout << p << ' ' << v << '\n';
    
}

int main(){ 
    fastio;
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<pair<ll,ll>> a(n+1);
        for(int i = 1; i <= n; ++i){
            ll x;
            cin >> x;
            a[i] = {x, i};
        }
        solve(a, n);
    }
    return 0;
}
// AC.
