// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;



ll fat(ll K){
    ll ans  = 1;

    for(ll i = 1; i <= K; ++i){
        ans*= i;
    }

    return ans;
}

ll solve(vector <long long> v, ll n){
    if(n == 1) return -1;
    ll ans = -1;
    bool f = true;
    map <ll, bool> check;
    map <ll, ll> laspos;
    for(ll i  = 0; i < n; ++i){
        if(f && check[v[i]]){
            ans = i - laspos[v[i]];
            f = false;
        }
        if(check[v[i]] && i - laspos[v[i]] < ans) ans = i-laspos[v[i]];
        laspos[v[i]] = i;
        check[v[i]] = true;
    }
    

    return ans  == -1 ? -1 : ans+1;
}

int main(){
    ll T;

    cin >> T;

    while(T--){
        ll N;
        cin >> N;

        vector<ll> v(N);
        for(ll i = 0;i  < N; ++i) cin >> v[i];

        cout << solve(v, N) << endl;
    }
    return 0;
}

// AC