// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
#define all(b) b.begin(), b.end()
#define maxx 11
map<ll, ll> sets;
ll n ,m;
ll ans;
ll goal;
set<ll> check;
void solve(ll c, ll b){
    if(b==goal) ans++;
    for(int i = 1; i <= m; ++i){
        if( check.count((c|(1<<i)))) continue;

        check.insert(c|(1<<i));
        solve((c|(1<<i)), (b|sets[i]));
    } 
}
int32_t main(void){ fastio;
    ans = 0;
    goal = 0;
    cin >> n >> m;

    for(int i = 1; i <= m; ++i){
        int c; cin >> c;
        ll b = 0;
        while(c--){
            ll a; cin >> a;
            b += (1<<a);
        }
        sets[i] = b;
    }
    
    for(int i = 1; i <= n; ++i)
        goal = (goal|(1<<i));

    solve(0, 0);

    cout << ans << '\n';
}

// AC.
