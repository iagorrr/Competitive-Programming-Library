// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    fastio
    int n;
    cin >> n;

    ll s = 0;
    while(n--){
        ll x;
        cin >> x;
        s+=x;
    }

    cout << s << '\n';
    return 0;
}

// AC.
