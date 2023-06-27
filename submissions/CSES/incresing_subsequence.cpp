
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
  ll n;
  cin >> n;
  vll xs(n);
  for (int i = 0; i < n; ++i) {
    cin >> xs[i];
  }

  vll dp;
  for (int i = 0; i < n; ++i) {
    /* for (auto xi : dp)
      cout << xi << ' ';
    cout << '\n'; */
    auto it = lower_bound(dp.begin(), dp.end(), xs[i]);
    if (it == dp.end()) {
      dp.push_back(xs[i]);
    } else {
      *it = xs[i];
    }
  }
  cout << dp.size() << '\n';
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, dp, lis
