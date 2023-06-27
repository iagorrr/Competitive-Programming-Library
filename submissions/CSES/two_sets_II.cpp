// iagorrr ;)
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
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

vector<vll> memo(501, vll((501 * 501)/2, -1));
const ll mod = 1e9 + 7;
ll dp(ll d, ll s) {
  if (s < 0)
    return 0;
  if (d < 0)
    return 0;
  if (d == 0)
    return 0;
  if (s == 0)
    return 1;
  if (memo[d][s] != -1) {
    return memo[d][s];
  }

  return memo[d][s] = (dp(d - 1, s - d) + dp(d - 1, s)) % mod;
}
void run() {
  ll N;
  cin >> N;

  // total of ways to sum maxsum/2;
  ll sum = (N * (N + 1) / 2);
  if (sum & 1) {
    cout << 0 << '\n';
    return;
  }
  sum /= 2;
  if (N <= 2)
    cout << 0 << '\n';
  else
    cout << dp(N, sum) << '\n';
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}
// AC, dp, math
