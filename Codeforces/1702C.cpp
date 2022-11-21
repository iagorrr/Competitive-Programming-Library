// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

void solve(const vector<ll> &U, const ll &n, const ll k){
    
    map<ll, ll> fpos; // store the first position.
    for(ll i = n-1; i >= 0; --i){
        fpos[U[i]] = i;
    }

    ll ui, uj;
    for(ll i = 0; i < k; ++i){
        cin >> ui >> uj;

        // look from the first appearing of ui and foward to find uj.
        set<ll> range (U.begin()+fpos[ui], U.end());
        cout << (range.count(uj) ? "YES" : "NO") << '\n';
    }
}
int main(){ 
    fastio
    ll t;
    cin >> t;
    string temp;
    while(t--){
        cin.ignore();
        getline(cin, temp);
        ll n, k;
        cin >> n >> k;

        vector<ll> U(n);
        for(auto &x : U)
            cin >> x;

        solve(U, n, k);
    }
    return 0;
}

// AC
