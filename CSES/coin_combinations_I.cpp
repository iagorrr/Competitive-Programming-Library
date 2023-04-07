// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void run(){
  ll n, x; cin >> n >> x;
  vll cs(n); INV(cs);
  ll mod = 1e9+7; 
  vll dp(max(*max_element(all(cs)), x)+1, 0);
  for(auto &ci : cs) dp[ci] = 1; 
  for(ll i = 0; i <= x; ++i) {
    for(auto &ci : cs) {
      if(i-ci >= 0){
        ll k = dp[i-ci];
        dp[i] = (k+dp[i])%mod;
      }
    }
  }
  
  cout << dp[x] << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
