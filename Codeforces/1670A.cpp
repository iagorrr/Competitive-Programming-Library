// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
string solve(vector<ll> a, ll n){
    ll neg = 0;
    for(auto &x : a){
        neg += x < 0 ? 1 : 0;
        x = abs(x);
    }

    for(int i = 0; i < neg; ++i)
        a[i] = -a[i];

    for(int i = 0; i < n-1; ++i)
        if(a[i] > a[i+1]) return "NO";
    
    return "YES";
}
int main(){ 
    fastio;
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for(auto &x :a) cin >> x;

        cout << solve(a, n) << '\n';
    }
    return 0;
}
// AC
