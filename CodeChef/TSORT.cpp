// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    fastio
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(auto &x : a)
         cin >> x;

    sort(a.begin(), a.end());

    for(auto x : a) cout << x << '\n';

    return 0;
}

// AC.
