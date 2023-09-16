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

const int maxn = 2 * 1e5;
int n, m;
using adj = vector<vector<array<ll, 3>>>;
vc vis(maxn);
vector<pll> pos(maxn, {-oo, -oo});
adj g(maxn);

void dfs(int u, ll x, ll y) {
  pos[u] = {x, y};
  vis[u] = true;
  for (auto [v, dx, dy] : g[u]) {
    if (vis[v]) continue;

    dfs(v, x + dx, y + dy);
  }
}
void run() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    ll x, y;
    cin >> a >> b >> x >> y;
    a--, b--;
    g[a].push_back({b, x, y});
    g[b].push_back({a, -x, -y});
  }

  dfs(0, 0, 0);

  for (int i = 0; i < n; i++) {
    if (pos[i].fst == -oo and pos[i].snd == -oo) {
      cout << "undecidable\n";
    } else {
      cout << pos[i].fst << ' ' << pos[i].snd << endl;
    }
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graphs, dfs
