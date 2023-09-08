#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
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
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll oo = 1e18;
const ll MOD = 1e9 + 7;
const ll maxn = 2 * 1e5 + 10;
vll fats(maxn + 1, -1);
void precompute() {
  fats[0] = 1;
  for (ll i = 1; i <= maxn; i++) {
    fats[i] = (fats[i - 1] * i) % MOD;
  }
}

ll fpow(ll a, ll n, ll mod = LLONG_MAX) {
  if (n == 0ll) return 1ll;
  if (n == 1ll) return a;
  ll x = fpow(a, n / 2ll, mod) % mod;
  return ((x * x) % mod * (n & 1ll ? a : 1ll)) % mod;
}

ll binommod(ll n, ll k) {
  ll upper = fats[n];
  ll lower = (fats[k] * fats[n - k]) % MOD;
  return (upper * fpow(lower, MOD - 2ll, MOD)) % MOD;
}
void run() {
  string s;
  cin >> s;
  precompute();
  int n = len(s);

  ll qtdc = 0, qtdo = 0, ans = 0;
  for (auto c : s) qtdc += c == ')';

  for (int i = 0; i < n; i++) {
    qtdo += s[i] == '(';
    qtdc -= s[i] == ')';
    if (s[i] == ')' or qtdc == 0 or qtdo == 0) continue;
    ll k = min(qtdo, qtdc);
    // ll u = (binommod(qtdo, k) * binommod(qtdc, k)) % MOD;
    ll u = (binommod(qtdo + qtdc-1, qtdo)) % MOD;
    // ll u = (binommod(qtdo + qtdc-1, qtdo)) % MOD;
    // cout << i << ' ' << qtdo << ' ' << qtdc << ' ' << u << endl;
    ans = (ans + u) % MOD;
  }

  cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, math, combinatorics, prefix sum
