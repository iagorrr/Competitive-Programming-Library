#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
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
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);
const int MAXN(2'00'000);
int N, M, S, D, C;
vi2d G(MAXN);

char vis[MAXN];
ll bfs() {
  queue<pii> q;
  q.emplace(1, S);
  vis[S] = true;
  while (not q.empty()) {
    auto [d, u] = q.front();
    q.pop();
    if (u == D) return d;

    for (auto v : G[u]) {
      if (vis[v]) continue;
      vis[v] = true;
      q.emplace(d + 1, v);
    }
  }

  return oo;
}
auto solve() {
  cin >> N >> M;
  cin >> S >> D >> C;
  S--, D--;

  while (M--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
  }

  ll find = bfs();
  if (find == oo) {
    cout << "Arquivada\n";
  } else if (find <= C) {
    cout << "Aceita\n";
    cout << find << endl;
  } else {
    cout << "Devolvida\n";
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}
