// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    fastio
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> a(n);
        ll mmax = -1;
        ll mmmax = -1;
        for(auto &x : a){
            cin >> x;

        }
        vector<ll> cp = a;
        sort(cp.begin(), cp.end(), greater<ll>());
        mmax = cp[0];
        mmmax = cp[1];

        for(auto xx :a){
            if(xx == mmax)
                cout << xx - mmmax << ' ';
            else
                cout << xx - mmax << ' ';
        }
        cout << '\n';

    }
    return 0;
}

// AC.
