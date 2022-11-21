// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

ll solve(string s){
    set<char> tot;

    ll ans = 1;
    for(int i = 0; i < (int)s.size(); ++i){
        if(tot.count(s[i]) == 0){
            if(tot.size() < 3){
                tot.insert(s[i]);
            }
            else{
                tot.clear();
                tot.insert(s[i]);
                ans++;
            }
        }
    }

    return ans;
}
int main(){ 
    fastio
    int t;
    
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
    return 0;
}

// AC.