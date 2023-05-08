// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    fastio
    ll x, y, z;
    cin >> x >> y >> z;
    map<char, ll> cv;
    cv['A'] = y;
    cv['F'] = x;
    cv['R'] = z;

    ll m, n;
    cin >> m >> n;

    string o;
    cin >> o;

    vector<ll> c;
    c.push_back(m);

    for(int i = 0; i < o.size(); ++i){
        ll pos = -1;
        for(int j = 0; j < c.size(); ++j){
            if(c[j] >= cv[o[i]]){
                pos = j;
                c[j] -= cv[o[i]];
                break;
            }
        }

        if(pos == -1){
            c.push_back(m-cv[o[i]]);
        }
    }

    cout << c.size() << '\n';
    return 0;
}
