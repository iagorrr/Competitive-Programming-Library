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
const ll maxn(1000);
const ll maxm(2000);
ll N, M;
vll2d g(maxn + 1);
vll2d gt(maxn + 1);

vc vis(maxn + 1);
vll indg(maxn + 1);
vll outdg(maxn + 1);
vc incycle(maxn + 1);
int s;

bool update(int u, int i) {
  bool ok = true;
  for (auto v : g[u]) {
    if (incycle[v]) {
      outdg[u] += i;
      indg[v] += i;

      ok &= (outdg[u] <= 1);
      ok &= (indg[v] <= 1);
    }
  }

  for (auto v : gt[u]) {
    if (incycle[v]) {
      indg[u] += i;
      outdg[v] += i;
      ok &= (indg[u] <= 1);
      ok &= (outdg[v] <= 1);
    }
  }
  return ok;
}
bool dfs(int u) {
  incycle[u] = true;
  vis[u] = true;
  bool ok = update(u, 1);

  if (not ok) {
    incycle[u] = false;
    update(u, -1);
    return false;
  }

  if (indg[s] == 1 and outdg[s] == 1) {
    return true;
  }

  for (auto v : g[u]) {
    if (vis[v]) continue;
    if (dfs(v) and indg[s] == 1 and outdg[s] == 1) return true;
  }

  incycle[u] = false;
  update(u, -1);
  return false;
}

auto solve() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    g[a].eb(b);
    gt[b].eb(a);
  }

  for (int i = 1; i <= N; i++) {
    vis = vc(N + 1);
    indg = vll(N + 1);
    outdg = vll(N + 1);
    incycle = vc(N + 1);
    s = i;
    if (dfs(i)) {
      vi ans;
      for (int j = 1; j <= N; j++) {
        if (incycle[j]) ans.eb(j);
      }

      cout << len(ans) << endl;
      for (int j = 0; j < len(ans); j++) {
        cout << ans[j] << endl;
      }
      return;
    }
  }

  cout << -1 << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) solve();
}

// AC, graphs, cycle detection
