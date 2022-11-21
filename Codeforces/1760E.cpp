// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

ll solve(vector<ll> ba, ll n){

    // regular psum..
    vector<ll> psumzero(n+2, 0);
    vector<ll> psumum(n+2, 0);

    for(ll i =0; i < n; ++i){
        if(ba[i] == 1)
            psumum[i+1] ++;
        else
            psumzero[i+1]++;
    }

    for(ll i = 1; i < n+2; ++i){
        psumum[i] += psumum[i-1];
        psumzero[i] += psumzero[i-1];
    }
    // find the total inverstions in the regular one.
    ll tinver = 0;
    for(ll i = 0; i < n; ++i){
        if(ba[i] == 1){
            tinver += psumzero[n+1] - psumzero[i];
        }
    }
    // cout << "tinver: " << tinver << '\n';

    // calcule for each position the one that gains the most.
    ll ans = -LLONG_MAX;
    for(ll i = 0; i < n; ++i){
        ll gain;
        ll lose;
        if(ba[i] == 1){
            // flip to zero, gain every um until i.
            gain = psumum[i];

            // flip zero, loose every zero that comes after.
            lose = psumzero[n+1] - psumzero[i+1];
        }
        else{
            // flip to 1, gain every zero after it.
            gain = psumzero[n+1] - psumzero[i+1];

            // filip to 1, loose every one before it.
            lose = psumum[i];
        }

        ll fgain = gain-lose;
        // cout << "i: " << i << " g: " << gain << " p: " << lose << " f: " << fgain << '\n';
        ans = max(ans, fgain);
    }

    return ans > 0 ? tinver + ans : tinver;
}
int main(){ 
    fastio

    ll t;
    cin >>t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> ba(n);
        for(auto &x : ba)
            cin >> x;

        cout << solve(ba, n) << '\n';
    }
    return 0;
}

// AC.