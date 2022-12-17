// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
string solve(string s, ll n){
    string ans;
    ll csum = 0;
    if(s[0] == '1') csum++;
    for(int i = 1; i < (int)s.size(); ++i){
        if(s[i]== '0') ans.push_back('+');
        else{
            if(csum >= 1){
                ans.push_back('-');
                csum--;
            }
            else{
                ans.push_back('+');
                csum++;
            }
        }
    }

    return ans;
}
int main(){ 
    fastio;
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
