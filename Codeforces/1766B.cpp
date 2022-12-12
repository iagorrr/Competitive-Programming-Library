// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
string solve(string s, ll n){   
    if(n <= 3) return "NO";

    map<string, vector<ll>> posis;
    bool ans = false;
    for(int i = 0; i < (int)s.size()-1; ++i){
        string a  {s[i],s[i+1]};
        for(auto pi : posis[a]){
            if(pi != i-1){ 
                ans = true;
            }
        }
        posis[a].push_back(i); 
    }
    
    return ans ? "YES" : "NO";
}
int main(){ 
    // fastio
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;

        cout << solve(s, n) << '\n';
    }
    return 0;
}

// AC.
