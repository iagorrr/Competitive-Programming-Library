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

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ll oo = 1e18;
const ll MOD(998244353);
vll parse(string &s) {
  vll ans;
  ll cnt = 0;
  ll p = 0;
  for (int i = 0; i < len(s); i++) {
    cnt += s[i] == s[p];

    if (not(s[i] == s[p])) {
      ans.pb(cnt);
      cnt = 1;
      p = i;
    }
  }
  ans.pb(cnt);
  return ans;
}
vll memo(2 * 1e5 + 1);
void precompute() {
  memo[0] = 1;
  for (ll i = 1; i <= 2 * 1e5; i++) {
    memo[i] = (memo[i - 1] * i) % MOD;
  }
}
auto solve() {
  string s;
  cin >> s;
  vll bs = parse(s);

  ll m = 0;
  for (auto bi : bs) {
    if (bi <= 1) continue;
    m += bi - 1;
  }

  if (0 == 1)
    cout << 0 << ' ' << 1 << endl;
  else {
    ll ans = memo[m];
    for (auto bi : bs) {
      ans = (ans * (bi) % MOD);
    }
    cout << m << ' ' << ans << endl;
  }
}
int32_t main(void) {
  fastio;
  precompute();
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
}

// AC, combinatorics

