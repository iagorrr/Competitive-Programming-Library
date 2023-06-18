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

// grid fechado em n, m
ll grid[1002][1002];
ll n, m;
void put(ll x, ll y, ll z) {
  ll u, d, l, r;
  u = max(0ll, x - z);
  d = min(n, x + z);
  l = max(0ll, y - z);
  r = min(m, y + z);

  for (int i = u; i <= d; ++i) {
    grid[i][l]++;
    grid[i][r + 1]--;
  }
}

void evaluate() {
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      grid[i][j] += grid[i][j - 1];
    }
  }
}
void run() {
  cin >> n >> m;
  n--;
  m--;
  ll s;
  cin >> s;

  for (ll i = 0; i < s; ++i) {
    ll x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    put(x, y, z);
  }
  ll ans = 0;
  evaluate();
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      ans += grid[i][j];
      // cout << grid[i][j] << ' ';
    }
    // cout << '\n';
  }
  // cout << ans/double((n + 1) * (m + 1)) << '\n';
  ans /= (n + 1) * (m + 1);
  cout << ans << '\n';
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}
