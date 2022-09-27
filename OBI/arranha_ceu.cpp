// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main(){
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for(auto &x : arr) cin >> x;

    while(q--){
        int op;
        cin >> op;

        if(op == 0){
            ll k, p;
            cin >> k >> p;

            arr[k-1] = p;
        }
        else{
            ll k;
            cin >> k;

            ll ans = 0;
            for(ll i = 0; i < k; ++i) ans += arr[i];

            cout << ans << '\n';
        }   
    }

    return 0;
}

// 20/100  TLE