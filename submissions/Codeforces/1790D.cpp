// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
    
    ll t; cin >> t;
 
    while(t--)
    {
        ll n; cin >> n;
        
        vector<ll> a(n); for(auto &x : a) cin >> x; sort(a.begin(), a.end());
 
        map<ll, set<ll>> precisa;
 
        int ans = 0;
        for(auto x : a)
        {
            if(precisa[x].empty()) // não se encaixa em nenhum
            {
                ans++;
                precisa[x+1].insert(ans);
            }
            else { // tem algum set que pode receber essa buneca.
                ll precisando_pos = *precisa[x].begin();
 
                precisa[x].erase(precisando_pos); // ele não precisa mais desse.
                
                // precisa do que acabou de pegar + 1.
                precisa[x+1].insert(precisando_pos);
            }
        }
 
        cout << ans << '\n';
    }
}
// AC.
