#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector <ll> a, ll n, ll s){
    vector <ll> psum(n+1);
    psum[0] = 0;
    for(ll i = 1; i <= n; ++i) psum[i] = psum[i-1] + a[i-1];
    if(psum[n] < s) return -1;
    
    // Linear for the term at left, and binary to the term at right.
    ll ans = LLONG_MAX;
    for(ll i = 0; i < n; ++i){

        /*
            - Trying to find psum[r] - psum[i-1] == s
            - As psum[i-1] and sis fixe we got:
                    psum[r] == s+psum[i-1]
            - So just look to the highest position that satisfy this condition.
        */
        auto itr = upper_bound(psum.begin(), psum.end(), s+psum[i]) -1;
        auto positionr = (int)(psum.end() - (itr+1));
        if(itr < psum.begin() || *itr - psum[i] != s) continue; //there is no possible combination for this left.
        ans = min(ans, i+positionr);
    }

    return ans;
}
int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n, s;
        cin >> n >> s;
        vector<ll> a(n);
        for(auto &x : a) cin >> x;
        

        cout << solve(a, n ,s) << endl;
    }
    return 0;
}

// AC
