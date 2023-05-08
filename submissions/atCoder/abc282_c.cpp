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

    string s;
    cin >> s;

    ll l = 0;
    ll r = 0;
    bool open = false;
    while(r < n){
        if(s[r] != '"'){ 
            if(s[r] == ',' and not open) s[r] = '.';
            r++;
        }
        else{
            if(open){
                open = false; // closed.
                l = r;
                r++;
            }
            else{
                l = r;
                r++;
                open = true;
            }
        }
    }

    cout << s << '\n';
    return 0;
}
