#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rep(i, s, e) for(int i = s ; i < e; ++i)
#define all(x) x.begin(), x.end()
#define int long long
typedef vector<long long> vi;
void solve(){
    int n,x;
    cin>>n>>x;
    vi v(n);
    for(auto &x: v) cin >> x;
    sort(all(v));

    if(n == 1) {
        cout << 1 << '\n';
        return;
    }
    int ans = 0;
    if(n > 1) {
        if(v[0] + v[1] <= x) ans = 2;
    }
    
    for(int i = 2; i < n; ++i) {
        if(v[i]+v[i-1] > x) break;
        ans++;
    }
    

    cout << max(1LL,ans) << '\n';
}


int32_t main() {
    fastio;
    int t; t=  1;
    

    while(t--){
        solve();
    }

}

