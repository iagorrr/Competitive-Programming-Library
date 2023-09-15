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
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll oo = 1e18;
pair<bool, ll> check(const vll &xs, int k, ll x) {
  ll cursum = 0;
  int ck = 1;
  ll maxsum = 0;
  for (auto &xi : xs) {
    if (cursum + xi > x) {
      maxsum = max(maxsum, cursum);
      ck++;
      cursum = 0;
    }
    cursum += xi;
  }

  maxsum = max(maxsum, cursum);
  return {ck <= k, maxsum};
}
void run() {
  int n, k;
  cin >> n >> k;

  vll xs(n);
  for (auto &xi : xs){
cin >> xi;
  } 

  ll l = *min_element(all(xs));
  ll r = accumulate(all(xs), 0ll);
  ll ans = r;
  while (l <= r) {
    ll mid = (l + r) / 2;
    auto [b, v] = check(xs, k, mid);
    if (b) {
      ans = min(ans, v);
      r = mid - 1;
    } else {
      l = mid + 1;
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

// AC, binary search
