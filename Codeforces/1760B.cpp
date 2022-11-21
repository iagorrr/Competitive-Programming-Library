// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

string alpha{"abcdefghijklmnopqrstuvwxyz"};
int main(){ 
    fastio
    ll t;
    cin >> t;

    while(t--){
        ll ss;
        cin >> ss;

        string s;
        cin >> s;

        ll ans= -1;
        for(auto c : s){
            ans = max(ans, (ll)(alpha.find(c)));
        }   
        cout << ans +1<< '\n';
    }
    return 0;
}

// AC.
