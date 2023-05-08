// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
vll p;
ll conv(vll a){
    ll ans = 0;
    for(int i = 0; i < (int)a.size(); ++i)
    {
        ans += a[i]*p[i];
    }
    return ans;
}
ll cont(vll a, ll n){
    set<ll> t;
    ll ans = 0 ;
    do
    {
        auto x = conv(a);
        
        if(!t.count(x) and x <= n) ans++;

        t.insert(x);
    } while (next_permutation(a.begin(), a.end()));
     
     return ans;
}
int main(){ 
    fastio;
    for(ll i = 0, x = 1; i < 14; ++i, x*= 10) p.push_back(x);
    ll n; cin >> n;

    vll perm;
    for(int i = 0; i < 10; ++i)
    {
        ll x;
        cin >> x;

        while(x--) perm.push_back(i);
    }

    cout << cont(perm, n) << '\n';

    return 0;
}

// AC.