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
  vector<multiset<ll>> st(2);
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    st[i & 1].insert(x);
  }
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    auto it = st[i & 1].find(x);
    if (it == st[i & 1].end()) {
      cout << "Nao\n";
      return;
    }
    st[i & 1].erase(it);
  }
  cout << "Sim\n";
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}
