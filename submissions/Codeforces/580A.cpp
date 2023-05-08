// iagorr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    // longest non decreasing subsequece.
    ll current = 1;
    ll ans = 1;
    for(ll i = 1; i < n; ++i){
        if(a[i] >= a[i-1]) current++;
        else current = 1;

        ans = max(ans , current);
    }

    cout << ans << '\n';
    return 0;
}

// accepted.
