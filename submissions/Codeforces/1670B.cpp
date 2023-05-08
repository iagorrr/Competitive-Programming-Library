// iagorrr;
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;

int main(){
    fastio;
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        string s;
        cin >> s;

        ll m;
        cin >> m;
        set<char> e;
        while(m--){
            char c;
            cin >> c;
            e.insert(c);
        }
        while(not s.empty() and not e.count(s.back())) s.pop_back();
        ll ans = 0;
        ll d = 0;
        for(auto c : s){
            ans = max(ans, d);
            if(not e.count(c)) d++;
            else d=1;
        }
        cout << ans << '\n';

    }
                
           

    return 0;
}
// AC
