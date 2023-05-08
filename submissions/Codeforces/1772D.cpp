// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)

ll solve(vector<ll> a, ll n){

    ll x = 0;
    bool foi = false;
    vector<ll> calcs;
    for(int i = 0; i < n-1; ++i){
        if(a[i]-x > a[i+1]-x){// increment x to satisfy it.
            ll calc = a[i+1] + (a[i]-a[i+1])/2 + (a[i]-x-a[i+1])%2; 
            calcs.push_back(calc);
        }   
    }

    if(calcs.empty()) return 0;

    // check if the x got is valid.
    sort(calcs.begin(), calcs.end());
    x = calcs.back();
    for(int i = 0; i < n-1; ++i){
        if(abs(a[i]-x) > abs(a[i+1]-x))
            return -1;
    }
    return x;
}
int main(){ 
    // fastio;
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