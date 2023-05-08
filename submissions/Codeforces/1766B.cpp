// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
struct Node {
    int x = -1;
};
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
string solve(string s, ll n){   
    if(n <= 3) return "NO";

    map<string, Node> posis;
    bool ans = false;
    for(int i = 0; i < (int)s.size()-1; ++i){
        string a  {s[i],s[i+1]};
        if(posis[a].x != -1)
            if(posis[a].x != i-1) return "YES";
        posis[a].x = posis[a].x == -1 ? i : min((int)i,(int) posis[a].x);
     }
         
    
    return ans ? "YES" : "NO";
}
int main(){ 
    fastio
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
