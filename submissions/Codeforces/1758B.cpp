// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

void solve(ll n){
    vector<ll> ans;
    if(n%2 == 0){
        ans.push_back(3);
        ans.push_back(1);
        while(ans.size() < n){
            ans.push_back(2);
        }

        ll sum = 0;
        for(int i = 0; i < n; ++i){
            cout << ans[i] << ' ';
            sum += ans[i];
        }
    }
    else{
        for(int i = 0; i < n; ++i){
            cout << 1 << ' ';
        }
    }
    // cout << "[" << n  << "] " << "[" << sum << ']' << " [" << sum/n << "] ";
    cout << '\n';
}
int main(){ 
    fastio

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}
// AC.
