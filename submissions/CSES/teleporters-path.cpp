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

vector<int> euler_cycle_directed(vector<vector<int>> &g, int u) {
  vector<int> res;

  stack<int> st;
  st.push(u);
  while (!st.empty()) {
    auto cur = st.top();
    if (g[cur].empty()) {
      res.push_back(cur);
      st.pop();
    } else {
      auto next = g[cur].back();
      st.push(next);

      g[cur].pop_back();
    }
  }

  for (auto &x : g)
    if (!x.empty()) return {};

  return res;
}

// Directed Edges
vector<int> euler_path_directed(vector<vector<int>> &g, int first) {
  {
    int n = (int)g.size();
    vector<int> in(n), out(n);
    for (int i = 0; i < n; i++)
      for (auto x : g[i]) in[x]++, out[i]++;

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++)
      if (in[i] == out[i])
        c++;
      else if (in[i] - out[i] == 1)
        b++;
      else if (in[i] - out[i] == -1)
        a++;

    if (c != n - 2 or a != 1 or b != 1) return {};
  }

  auto res = euler_cycle_directed(g, first);
  if (res.empty()) return res;

  reverse(all(res));
  return res;
}
void run() {
  int n, m;
  cin >> n >> m;

  vi2d g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].eb(b);
  }

  auto ans = euler_path_directed(g, 0);
  if (ans.empty() or ans.front() != 0 or ans.back() != n - 1) {
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

// AC, graphs, euler path
