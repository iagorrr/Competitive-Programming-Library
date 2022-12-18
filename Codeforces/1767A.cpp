// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio
    ll t;
    cin >> t;

    string buf;
    while(t--){
        getline(cin, buf); cin.ignore();
        set<ll> x;
        set<ll> y;

        ll equalx = 0;
        ll equaly = 0;
        vector<pair<ll,ll>> tri;
        bool ans = true;
        for(int i =0; i < 3; ++i){
            ll a, b;
            cin >> a >> b;
            if(x.count(a)) equalx++;
            if(y.count(b)) equaly++;

            x.insert(a); y.insert(b);
        }   

        if(equalx >= 1 and equaly >= 1) cout << "NO" << '\n';
        else cout << "YES\n";

    }
    return 0;
}
//AC.
