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

const ll oo = 1e18;

void run() {

  ll n;
  cin >> n;
  vector<pll> xs(n);
  for (auto &[xi, vi] : xs)
    cin >> xi >> vi;

  vector<vector<ll>> dp(2, vector<ll>(n, -oo));
  if (xs[0].fst) {
    dp[0][0] = 0;
    dp[1][0] = max(0ll, xs[0].snd);
  } else {
    dp[0][0] = max(0ll, xs[0].snd);
    dp[1][0] = 0;
  }

  for (int i = 1; i < n; ++i) {
    auto [xi, vi] = xs[i];
    if (xi == 0) {
      /*
       * curar de um fudidio anterior
       * nao comer vindo de um nao fudidio
       * comer vindo de um nao fudido
       * */
      dp[0][i] = max({dp[1][i - 1] + vi, dp[0][i - 1], dp[0][i - 1] + vi});

      /*
       * continuar fudidio de um anterior
       * */
      dp[1][i] = dp[1][i - 1];
    } else {
      /*ou se fode agora e come ou continua fudido do passado sem comer*/
      dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + vi);

      /* vem do anterior sem se fuder nao come */
      dp[0][i] = dp[0][i - 1];
    }
  }

  cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, dynamic programming
