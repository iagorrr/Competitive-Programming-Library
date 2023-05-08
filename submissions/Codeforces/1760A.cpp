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
        vector<ll> a(3);
        cin >> a[0] >> a[1] >> a[2];

        sort(a.begin() ,a.end());
        cout << a[1] << '\n';
    }
    return 0;
}

// AC.
