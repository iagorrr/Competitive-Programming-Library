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
  ll x;
  cin >> n;
  cin >> x;
  vi xs(n);
  for (auto &xi : xs) cin >> xi;

  vll psum(n + 1);
  for (int i = 1; i <= n; i++) {
    psum[i] = psum[i - 1] + xs[i - 1];
  }

  int l = 0;
  int r = 0;
  int ans = 0;
  while (l <= n and r <= n) {
    ll cur = psum[r] - psum[l];
    if (cur >= x) {
      ans += cur == x;
      l++;
    } else if (cur < x) {
      r++;
    }
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

// AC, prefix sum, two pointers
