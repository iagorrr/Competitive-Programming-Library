// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Consider that if we choose 2, there will be only 1 and 0 at A.
*/
inline int solve(const vector<ll> &a, const ll &n){
    ll b = 0;

    for(ll i = 0; i < n-1; ++i) b = gcd(b, a[i+1]-a[i]);
    

    return b == 1 ? 2 : 1;
}
int main(){
    ll n;
    cin >> n;

    vector <ll> a(n);
    for(auto &x : a) cin >> x;

    cout << solve(a, n) << '\n';

    return 0;
}