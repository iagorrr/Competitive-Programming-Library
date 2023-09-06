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

const ll maxn = 1e6;
vll fats(maxn + 1, -1);
const ll mod = 1e9 + 7;
void precompute() {
  fats[0] = 1;
  for (ll i = 1; i <= maxn; i++) {
    fats[i] = (fats[i - 1] * i) % mod;
  }
}

ll fpow(ll a, ll n, ll mod = LLONG_MAX) {
  if (n == 0) return 1;
  if (n == 1) return a;
  ll x = fpow(a, n / 2, mod) % mod;
  return ((x * x) % mod * (n & 1 ? a : 1ll)) % mod;
}

ll binommod(ll n, ll k) {
  ll upper = fats[n];
  ll lower = (fats[k] * fats[n - k]) % mod;
  return (upper * fpow(lower, mod - 2, mod)) % mod;
}
void run() {
  ll n, k;
  cin >> n >> k;
  cout << binommod(n, k) << endl;
}
int32_t main(void) {
  precompute();
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) run();
}

// AC, math, binomial
