// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    fastio
    ll N;
    cin >> N;

    vector<ll> A(N);
    for(auto &x : A) cin >> x;
    

    ll M = -LLONG_MAX;
    ll m = LLONG_MAX;
    for(auto x : A){
        m = min(x, m);
        M = max(x, M);
    }

    cout << M - m << '\n';

    return 0;
}

// AC.
