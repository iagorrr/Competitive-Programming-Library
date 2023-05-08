
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
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

ll solve(ll n){
  // bottom up.
  vll dp(1e6+10, LLONG_MAX);
  dp[0] = 0;
  for(int d = 1; d <= 9; ++d) {
      dp[d] = 1; 
  }

  for(int i = 1; i <= n; ++i) {
    for(int d = 1; d <= 9; ++d) {
      if(to_string(i+d).find(d+'0') != string::npos) {
        dp[i+d] = min(dp[i+d], dp[i]+1);
      }
    }
  }
  
  return dp[n];
}
void run(){
  ll n; cin >> n;
  cout << solve(n) << '\n';
   
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, dp bottom up 
