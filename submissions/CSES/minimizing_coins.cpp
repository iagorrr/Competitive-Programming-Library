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
  // bottom up.
  ll n, x; cin >> n >> x;
  vll a(n); INV(a); sort(all(a));

  vll dp(max(x+1, *max_element(all(a))), LLONG_MAX);
  for(auto ai: a) {dp[ai] = 1;}
  dp[0] = 0;
  for(int i = 0; i <= x; ++i) {
    for(auto &ai : a) {
      if(i-ai >= 0 and dp[i-ai] != LLONG_MAX) {
        dp[i] = min(dp[i], dp[i-ai]+1);
      } 
    }
  }
  
  cout << (dp[x] == LLONG_MAX ? -1 : dp[x]) << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// dp, bottom up.
