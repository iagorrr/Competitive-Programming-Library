// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
string solve(vector<pll> a, ll n, ll k){
    sort(a.begin(), a.end());
    

    ll pos = 0;
    ll total_damage = 0;
    while(pos < n and k > 0){
        // increase the damage.
        total_damage += k;

        // remove every that should be already dead and killed now.
        while(pos < n and a[pos].second <= total_damage) pos++;

        // decrease by the weakest.
        k -= a[pos].first;
    }

    
    return pos >= n ? "YES" : "NO";
}
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
    ll t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        vector<pair<ll,ll>> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i].second;
        }
        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
        }

        cout << solve(a, n, k) << '\n';
    }
    return 0;
}
// AC.
