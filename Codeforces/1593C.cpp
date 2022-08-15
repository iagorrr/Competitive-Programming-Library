// iagorrr
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll solve(vector <ll> vmices, ll b, ll n){
    ll ans = 0;
    sort(vmices.begin(), vmices.end());
    
    list <ll> mices;
    for(ll i = 0; i < n; ++i){
        mices.push_back(vmices[i]);
    }

    ll cat = 0;
    ll increment;
    while(!mices.empty()){
        increment = max(b-mices.back(), 0ll);
        mices.pop_back();
        ans++;

        cat += increment;
        while(mices.front() <= cat && !mices.empty()){
            mices.pop_front();
        }
    }
    
    return ans;
}


int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n, b;
        cin >> b >> n;

        vector<ll> mices;
        for(ll i = 0; i < n; ++i){
            ll x;
            cin >> x;
            mices.push_back(x);
        }

        cout << solve(mices, b, n) << endl;
    }

    return 0;
    
}

// AC.
