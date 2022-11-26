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

    set<ll> a;
    while(n--){
        ll x;
        cin >> x;
        a.insert(x);
    }

    cout << a.size() <<'\n';
    return 0;
}
