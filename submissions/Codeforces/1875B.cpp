#include <bits/stdc++.h>

#include <numeric>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ll oo = 1e18;

void simula(multiset<ll> &sty, multiset<ll> &stx, ll n) {
  for (ll i = 1; i <= n; i++) {
    ll miny = *sty.begin();
    ll maxy = *sty.rbegin();

    ll minx = *stx.begin();
    ll maxx = *stx.rbegin();

    if (i & 1) {
      if (minx >= maxy) continue;
      stx.erase(stx.find(minx));
      stx.insert(maxy);
      sty.erase(sty.find(maxy));
      sty.insert(minx);
    } else {
      if (miny >= maxx) continue;
      sty.erase(sty.find(miny));
      sty.insert(maxx);
      stx.erase(stx.find(maxx));
      stx.insert(miny);
    }
  }
}
auto solve() {
  ll N, M, K;
  cin >> N >> M >> K;
  vll XS(N);
  for (auto &xi : XS) cin >> xi;
  vll YS(M);
  for (auto &YI : YS) cin >> YI;

  multiset<ll> stx;
  for (auto &xi : XS) stx.insert(xi);

  multiset<ll> sty;
  for (auto &YI : YS) sty.insert(YI);

  ll minxs = *min_element(all(XS));
  ll minys = *min_element(all(YS));
  ll maxxs = *max_element(all(XS));
  ll maxys = *max_element(all(YS));
  if (K & 1) {
    if (K == 1) {
      ll a = accumulate(all(XS), 0ll) - minxs + maxys;
      ll b = accumulate(all(XS), 0ll);
      cout << max(a, b) << endl;
      return;
    }

    simula(sty, stx, 9);
    ll ans = 0;
    for (auto &xi : stx) ans += xi;
    cout << ans << endl;
  } else {
    simula(sty, stx, 4);

    ll ans = 0;
    for (auto &xi : stx) ans += xi;
    cout << ans << endl;
  }
}

int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
}

// AC, data structures, brute force
