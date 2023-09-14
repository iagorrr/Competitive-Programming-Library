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
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
const ll oo = 1e18;

struct Hash {
  const ll P = 31;
  const ll mod = 1e9 + 7;
  string s;
  int n;
  vll h, hi, p;
  Hash() {}
  Hash(string s) : s(s), n(len(s)), h(n), hi(n), p(n) {
    for (int i = 0; i < n; i++) p[i] = (i ? P * p[i - 1] : 1) % mod;
    for (int i = 0; i < n; i++) h[i] = (s[i] + (i ? h[i - 1] : 0) * P) % mod;
    for (int i = n - 1; i >= 0; i--)
      hi[i] = (s[i] + (i + 1 < n ? hi[i + 1] : 0) * P) % mod;
  }
  ll query(int l, int r) {
    ll hash = (h[r] - (l ? h[l - 1] * p[r - l + 1] % mod : 0));
    return hash < 0 ? hash + mod : hash;
  }
  ll query_inv(int l, int r) {
    ll hash = (hi[l] - (r + 1 < n ? hi[r + 1] * p[r - l + 1] % mod : 0));
    return hash < 0 ? hash + mod : hash;
  }
};
void run() {
  string s;
  cin >> s;

  Hash hs(s);
  vi ans;
  for (int i = 0; i < len(s) - 1; i++) {
    if (hs.query(0, i) == hs.query(len(s) - i - 1, len(s) - 1)) ans.eb(i + 1);
  }
  for (auto ai : ans) cout << ai << ' ';
  cout << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, strings, hashing
