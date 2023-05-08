// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int32_t main() {
    ll n, x; cin >> n >> x;
    vector<pair<int, int>> stage(n);
    ll ans = LLONG_MAX; 
    ll curtime = 0;
    for(int i = 0; i < n; ++i) {
        cin >> stage[i].first >> stage[i].second;
        curtime += stage[i].second + stage[i].first;
        x--;
        ans = min(ans, curtime + x*stage[i].second);
        if(x==0) break;
    }
    cout << ans << '\n';
}
// AC, greedy.
