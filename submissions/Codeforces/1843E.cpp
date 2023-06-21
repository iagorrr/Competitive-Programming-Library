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

/*
 *
 * chuta se até a x-śeima alguem conseguiu
 * e faz um lower bound pra achar a que deu primeiro
 * */

bool check(ll x, ll n, const vll &qs, const vector<pll> segs) {
  vll psum(n + 1);
  for (int i = 0; i < x; ++i)
    psum[qs[i]+1] = 1;

  for (int i = 1; i <= n; ++i)
    psum[i] += psum[i - 1];

  for (auto &[l, r] : segs) {
    ll t = r - l + 1;
    ll q1 = psum[r + 1] - psum[l];
    if (q1 > t / 2)
      return true;
  }
  return false;
}
void run() {
  ll n, m;
  cin >> n >> m;
  vector<pll> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i].first >> b[i].second;
    b[i].first--;
    b[i].second--;
  }

  ll q;
  cin >> q;
  vll qs(q);
  for (int i = 0; i < q; ++i) {
    cin >> qs[i];
    qs[i]--;
  }
  ll ans = -1;

  ll l = 0, r = q;
  while (l <= r) {
    ll mid = (r - l) / 2 + l;
    if (check(mid, n, qs, b)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
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
// AC, binary search
