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
  ll ax, ay;
  cin >> ax >> ay;
  ll bx, by;
  cin >> bx >> by;
  ll cx, cy;
  cin >> cx >> cy;

  ll ans = 1;

  bool vertb = (by > ay);
  bool horinb = (bx > ax);
  bool vertc = (cy > ay);
  bool horinc = (cx > ax);

  // same horizontal same vertical
  if (horinb == horinc and vertb == vertc)
    ans = min(abs(ax - bx), abs(ax - cx)) + min(abs(ay - by), abs(ay - cy)) + 1;
  // same horizontal different vertical
  if (horinb == horinc and vertb != vertc)
    ans = 1 + min(abs(ax - bx), abs(ax - cx));
  // different horizontal same vertical
  if (horinb != horinc and vertb == vertc)
    ans = 1 + min(abs(ay - by), abs(ay - cy));
  // different horizontal different vertical
  if (horinb != horinc and vertb != vertc)
    ans = 1;

  cout << ans << '\n';
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--)
    run();
}

// AC, math, grid
