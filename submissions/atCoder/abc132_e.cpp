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

const int maxn(1e5);
int n, m, s, t;
vi2d g(maxn);
vll2d dist(3, vll(maxn, -3));
void run() {
  cin >> n >> m;

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].eb(b);
  }

  cin >> s >> t;
  s--, t--;

  queue<pll> q;
  q.emplace(s, 0);
  dist[0][s] = 0;

  while (not q.empty()) {
    auto [u, mu] = q.front();
    q.pop();

    int mum = (mu + 1) % 3;

    for (auto v : g[u]) {
      if (dist[mum][v] != -3) continue;
      q.emplace(v, mum);
      dist[mum][v] = dist[mu][u] + 1;
    }
  }

  cout << dist[0][t] / 3ll << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// graphs, dfs/bfs, cycle
