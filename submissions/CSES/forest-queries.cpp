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

struct psum2d {
  vll2d s;
  vll2d psum;
  psum2d(vll2d &grid, int n, int m)
    : s(n + 1, vll(m + 1)), psum(n + 1, vll(m + 1)) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) s[i][j] = s[i][j - 1] + grid[i][j];

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) psum[i][j] = psum[i - 1][j] + s[i][j];
  }

  ll query(int x1, int y1, int x2, int y2) {
    ll ans = psum[x2][y2] + psum[x1 - 1][y1 - 1];
    ans -= psum[x2][y1 - 1] + psum[x1 - 1][y2];
    return ans;
  }
};
void run() {
  int n, q;
  cin >> n >> q;

  vll2d grid(n + 1, vll(n + 1));
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    s = "#" + s;
    for (int j = 1; j <= n; j++) {
      grid[i][j] = s[j] == '*';
    }
  }

  psum2d st(grid, n, n);

  while (q--) {
    int y1, x1, y2, x2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << st.query(x1, y1, x2, y2) << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, data structures, prefix sum 2d
