// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
    ll n;
    cin >> n;

    unordered_map<ll, ll> fb;
    unordered_map<ll, ll> bf;
    for(ll i = 0; i < n; ++i){
        ll a, b;
        cin >> a >> b;
        fb[a] = b;
        bf[b] = a;
    }
   
    // first odd and firt even.
    ll fo = 0;
    ll fe = 0;
    if(1){
        // find the one that appears at second collum but not at first.
        set <ll> one;
        for(auto [k, v] : fb) 
            one.insert(k);
        for(auto [k, v] : fb)
            one.erase(v);
        for(auto x : one) fo = x;

    }
    fe = fb[0];
    while(true){
        cout << fo << ' ';
        fo = fb[fo];

        if(fe){
            cout << fe << ' ';
             fe = fb[fe];
        }
        if(fe == 0 and fo == 0) break;       
    }
    cout << '\n';
    return 0;
}
// AC
