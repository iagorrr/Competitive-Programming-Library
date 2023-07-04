// iagorrr ;)
#include <bits/stdc++.h>
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

void run() {
  ll n, k;
  cin >> n >> k;
  ll xc, yc;
  cin >> xc >> yc;

  vector<pair<ll, ll>> ds(n);
  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    ll di = abs(x - xc) * abs(x - xc) + abs(y - yc) * abs(y - yc);
    // guarda o id negativo pra ordenação padrão funcionar
    ds[i] = {di, -(i+1)};
  }

  sort(all(ds));

  cout << -ds[0].second << ' ' << -ds[k-1].second << '\n';
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}
