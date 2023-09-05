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

const int oo = 1e9;

vi2d floyd_warshall(const vi2d &g) {
  int n = len(g);

  auto dist = g;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }

  return dist;
}
void run() {
  int n;
  cin >> n;

  vi2d g(n, vi(n));
  for (auto &gi : g) {
    for (auto &i : gi) {
      cin >> i;
    }
  }

  vi2d g2 = floyd_warshall(g);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g2[i][j] < g[i][j]) {
        cout << -1 << endl;
        return;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (i == k or j == k or i == j) continue;

        if (g[j][k] == g[j][i] + g[i][k]) {
          ans++;
          g[j][k] = oo;
          g[k][j] = oo;
        }
      }
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
