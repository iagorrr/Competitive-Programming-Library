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

// Undirected Edges
vector<int> euler_cycle(vector<set<int>> &g, int u) {
  vector<int> res;

  stack<int> st;
  st.push(u);
  while (!st.empty()) {
    auto cur = st.top();
    if (g[cur].empty()) {
      res.push_back(cur);
      st.pop();
    } else {
      auto next = *g[cur].begin();
      st.push(next);

      g[cur].erase(next);
      g[next].erase(cur);
    }
  }

  for (auto &x : g)
    if (!x.empty()) return {};

  return res;
}

// Undirected edges
vector<int> euler_path(vector<set<int>> &g, int first) {
  int n = (int)g.size();
  int v1 = -1, v2 = -1;
  {
    bool bad = false;
    for (int i = 0; i < n; i++)
      if (g[i].size() & 1) {
        if (v1 == -1)
          v1 = i;
        else if (v2 == -1)
          v2 = i;
        else
          bad = true;
      }

    if (bad or (v1 != -1 and v2 == -1)) return {};
  }

  if (v1 != -1) {
    // insert cycle
    g[v1].insert(v2);
    g[v2].insert(v1);
  }

  auto res = euler_cycle(g, first);
  if (res.empty()) return res;

  if (v1 != -1) {
    for (int i = 0; i + 1 < (int)res.size(); i++) {
      if ((res[i] == v1 and res[i + 1] == v2) ||
          (res[i] == v2 and res[i + 1] == v1)) {
        vector<int> res2;
        for (int j = i + 1; j < (int)res.size(); j++) res2.push_back(res[j]);
        for (int j = 1; j <= i; j++) res2.push_back(res[j]);
        res = res2;
        break;
      }
    }
  }

  reverse(all(res));
  return res;
}
void run() {
  int n, m;
  cin >> n >> m;

  vector<set<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].insert(b);
    g[b].insert(a);
  }
  auto ans = euler_path(g, 0);
  if (len(ans) < m + 1 or ans.back() != ans.front()) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (auto &ai : ans) cout << ai + 1 << ' ';
    cout << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graph, euler path
