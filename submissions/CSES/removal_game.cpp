// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T> void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                                                               \
  {                                                                            \
    cerr << #__VA_ARGS__ << ':';                                               \
    dbg_out(__VA_ARGS__);                                                      \
  }

const ll MAX = 5'000;
ll dp[MAX][MAX];
vll xs(MAX);
ll tsum;
ll n;
void run() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> xs[i];
    tsum += xs[i];
  }

  for (ll l = n - 1; l >= 0; --l) {
    for (ll r = l; r <= n - 1; ++r) {
      if (l == r)
        dp[l][r] = xs[l];
      else {
        dp[l][r] = max(xs[l] - dp[l + 1][r], xs[r] - dp[l][r - 1]);
      }
    }
  }

  cout << (tsum + dp[0][n - 1]) / 2 << '\n';
}
int32_t main(void) { // fastio;
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, game theory, dynamic programming
