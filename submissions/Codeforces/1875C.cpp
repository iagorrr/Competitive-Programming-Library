#include <bits/stdc++.h>
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

auto solve() {
  ll n, m;
  cin >> n >> m;
  if (n % m == 0) {
    cout << 0 << endl;
    return;
  }

  n = n - ((n / m) * m);
  ll d = gcd(n, m);
  n /= d;
  m /= d;
  // precisa ser pow2
  bool ok = false;
  for (ll i = 0; (1ll << i) <= m; i++) {
    if ((1ll << i) == m) ok = true;
  }
  if (not ok) {
    cout << -1 << endl;
    return;
  }
  // cout << n << ' ' << m << endl;
  ll ans = 0;
  for (int i = 0; (1ll << i) <= n; i++) {
    ll p2 = (1ll << i);
    if (p2 & n) {
      ans += (m / p2 - 1) * p2;
    }
  }

  cout << ans * d << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
}

// AC, math, bit operation 
