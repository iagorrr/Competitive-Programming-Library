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

bool check(vll &xs, ll w, ll m) {
  ll cm = 1;
  ll cll = 0;
  cll = xs[0];
  for (int i = 1; i < len(xs); i++) {
    if (cll + 1 + xs[i] <= w) {
      cll += 1 + xs[i];
    } else {
      cm++;
      cll = xs[i];
    }
  }

  // cout << "w: " << w << " cm: " << cm << endl;
  return cm <= m;
}
void run() {
  ll n, m;
  cin >> n >> m;

  vll xs(n);
  ll r = 0, l = 1;
  for (auto &xi : xs) {
    cin >> xi;
    r += xi + 1;
    l = max(l, xi);
  }

  ll ans = r;
  r *= 2;
  while (l <= r) {
    ll mid = (l+r) / 2;
    if (check(xs, mid, m)) {
      ans = min(mid, ans);
      r = mid - 1;
    } else
      l = mid + 1;
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

// AC, binary search
