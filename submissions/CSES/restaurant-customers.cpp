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
  vii xs;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    xs.emplace_back(a, 1);
    xs.emplace_back(b, -1);
  }
  sort(all(xs));
  int ans = 0;
  int cur = 0;
  for (auto &xi : xs) {
    cur += xi.snd;
    ans = max(cur, ans);
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
