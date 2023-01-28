// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
string pi = "3141592653589793238462643383279502884197169399375105820974944";
int main(){ 
    fastio;
    
    ll t;
    cin >> t;
 
    while(t--)
    {
        string s; cin >> s;
 
        int i = 0;
        for(i = 0; i < pi.size(); ++i)
            if(s[i] != pi[i]) break;
 
        cout << i << '\n';
    }   
}
// AC.
