// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

vll dp(1e4+1, -1);
vll xs;
ll solve(ll n) {
  // dp[i] = how much a player can get starting at i.
  dp[0] = 0;
  for(int i = 0 ; i <= n; ++i) {
    for(auto xi : xs) {
      if(i-xi < 0) continue;
      dp[i] = max(dp[i], i-dp[i-xi]);
    }
  }
  return dp[n];
}
void run(){
  ll n, k; cin >> n >> k;

  for(int i = 0; i < k; ++i) {
    ll x; cin >> x;
    xs.push_back(x);
  }
  ll ans = solve(n);

  cout << ans << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
// AC.
