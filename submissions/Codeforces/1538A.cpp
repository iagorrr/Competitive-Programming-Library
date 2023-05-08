// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector <ll> a, ll n){
    ll minpos = 1;
    ll maxpos = 1;
    for(ll i =1; i <= n; ++i){
        if(a[i] > a[maxpos]) maxpos = i;
        if(a[i] < a[minpos]) minpos = i;
    }

    ll ans;
    ll ap = min(minpos, maxpos);
    ll bp = max(minpos, maxpos);
    // cout << "ap: " << ap << " bp: " << bp << endl;

    // goes full from left to right, or right to left.
    ans = min(bp, n-ap+1);

    // goes from borders.
    ans = min(ans, ap+n-bp+1);
    return ans;
}
int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        vector <ll> a(n+1);
        for(ll i = 1; i <= n; ++i) cin >> a[i];

        cout << solve(a, n) << endl;
    }
    return 0;
}

// AC.
