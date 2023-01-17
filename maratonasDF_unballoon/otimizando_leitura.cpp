// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;

    ll n; cin >> n;


    vll a(n); for(auto &x : a) cin >> x;

    vll psum(n+1,0);
    for(int i = 1 ; i <= n; ++i) psum[i] += psum[i-1] + a[i-1];

    ll ans = LONG_MAX;
    ll l = 1, r = n;
    while(l < r){
        ll vl = psum[l];
        ll vr = psum[n] - psum[r-1];
        ll vm = psum[n] - vl - vr;

        ll cur = max({vl, vr, vm});
        ans = min(ans, cur);
        
        if(psum[l+1] < psum[n]-psum[r-2]) l++;
        else r--;
    }
    if(n == 1) ans = a.back();
    cout << ans << '\n';
    return 0;
}
