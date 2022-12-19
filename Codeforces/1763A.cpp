// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

ll solve(vector<ll> a, ll n){
    sort(a.begin(), a.end());
    ll max=a.back();

    for(int i = 0; i < n-1; ++i){
        ll temp = a[i];
        a[i] = (a[i]&max);
        max |= temp;
    }

    sort(a.begin(), a.end());

    ll min = a[0];
    for(int i = 1; i < n; ++i){
        min = min&a[i];
    }
    
    min = min < 0 ? 0 : min;
    // cout << min << ' ' << max << '\n';
    return max-min;
}
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for(auto &x : a) cin >> x;

        cout << solve(a, n) << '\n';
    }
    return 0;
}
// AC.
