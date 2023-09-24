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

auto solve() {
  int n;
  cin >> n;
  ll s1, e1;
  cin >> s1 >> e1;

  ll ans = s1;
  for (int i = 0; i < n-1; i++) {
    ll si, ei;
    cin >> si >> ei;
    if (si >= s1 and ei >= e1) ans = -1;
  }
  cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
}

// AC, greddy
