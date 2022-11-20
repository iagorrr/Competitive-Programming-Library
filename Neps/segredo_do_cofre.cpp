#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector <ll> ans(10, 0);


int main(){
    ll n, m;
    cin >> n >> m;

    vector <ll> v(n+2);
    for(ll i = 1; i < n+1; ++i) cin >> v[i];

    vector <vector<ll>> psa(10, vector<ll>(n+2, 0));

    for(ll i = 1;  i < n+1; ++i) psa[v[i]][i] = 1;



    for(ll i = 0; i < 10; ++i){
        for(ll j = 1; j < n+2; ++j){
            psa[i][j] += psa[i][j-1];
        }
    }

    vector <pair<ll,ll>> q;
    ll x;
    cin >> x;
    ans[v[1]]++;
    ll prev = x;
    for(ll i = 0; i < m; ++i){
        cin >> x;
        
        ll l = min(x, prev);
        ll r = max(x, prev);

        if(prev > x){ r--; l--;}
        q.push_back({l, r});
        prev = x;
    }


    for(ll i = 0; i < q.size(); ++i){
        ll l = q[i].first;
        ll r = q[i].second;

        for(ll j = 0; j < 10; ++j){
            ans[j] += psa[j][r] - psa[j][l];
        }
        
    }

    cout << ans[0];
    for(ll i = 1; i < 10; ++i) cout << " " << ans[i];
    cout << endl;
    return 0;
}

// Aceito !