// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ull = unsigned long long;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

ll mod = (int)1e9+7;
vll dp((int)1e6+1,0) ;

void run(){
  ll n; cin >> n;
  
  dp[0] = 1;
  for(ll i = 1; i <= n; ++i) {
    ll ans = 0;
    for(int d = 1; d <= 6; ++d) {
      if(i-d >= 0)
        ans = (ans+dp[i-d])%mod;
    }
    dp[i] = ans;
  }
  cout << dp[n] << '\n';
}
int32_t main(void){  //fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, dp, combinatorics.
