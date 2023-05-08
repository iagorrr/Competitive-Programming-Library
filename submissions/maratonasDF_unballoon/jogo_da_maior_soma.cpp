// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long ;
using vll = vector<ll>;

int32_t main(void){ fastio;
    ll n; cin >> n;

    vll a(n); for(auto &x : a) cin >> x;
    vll psum(n+1, 0); 
    for(int i = 1; i <= n; ++i){
        psum[i] = psum[i-1]+a[i-1];
    }
    ll ans = LLONG_MIN;
    ll ansp=0;
    for(int i = 0; i <= n/2; ++i){

        ll l = psum[i];
        ll r = psum[n] - psum[n-(n/2-i)];

        // cout << "i: " << i << " l: " << l << "r: " << r << '\n';
        ll cur = l+r; 
        if(cur > ans){
            ans = cur;
            ansp = i;
        }
    }

    cout << ans << '\n';
    string L (ansp, 'L');
    string R (n/2-ansp, 'R');
    cout << L << R << '\n';
}

// AC.
