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
    unsigned long long t;
    cin >> n >> t;

    unsigned long long one =0;
    vll A(n);
    for(auto &x : A){
        cin >> x;
        one += x;
    }

    // will rest r after some cicles
    ll r = t%one;
    ll c = 0;
    ll ans=1;
    ll tr=0;
    for(int i = 0; i < n; ++i){
        if(c + A[i] > r) {
            ans = i+1;
            tr = r-c;
            break;
        }
        c+= A[i];
    }

    cout << ans << ' ' << tr << '\n';
    return 0;
}

// AC.
