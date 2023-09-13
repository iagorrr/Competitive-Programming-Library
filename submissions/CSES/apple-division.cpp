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

void run() {
  int n;
  cin >> n;

  vll xs(n);
  for (auto &ai : xs) cin >> ai;
  ll ans = 1e9 * 20;

  for (ll i = 0; i < (1ll << n); i++) {
    ll qtda = 0, qtdb = 0;
    for (ll j = 0; (1ll << j) < (1ll << n); j++) {
      if (i & (1ll << j))
        qtda += xs[j];
      else
        qtdb += xs[j];
    }

    ans = min(ans, abs(qtda - qtdb));
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

// AC, brute force, bitmask
