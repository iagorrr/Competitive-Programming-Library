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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
// int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e9;

vi2d G;
int N, M;

bool check() {
  vi side(N + 1, -1);
  queue<int> q;
  for (int st = 1; st <= N; st++) {
    if (side[st] == -1) {
      q.emplace(st);
      side[st] = 0;
      while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : G[u]) {
          if (side[v] == -1) {
            side[v] = side[u] ^ 1;
            q.push(v);
          } else if (side[u] == side[v])
            return false;
        }
      }
    }
  }
  return true;
}

auto solve() {
  cin >> N >> M;
  vi XS(M), YS(M);
  for (auto &xi : XS) cin >> xi;
  for (auto &yi : YS) cin >> yi;

  G.resize(N + 1);
  for (int i = 0; i < M; i++) {
    G[XS[i]].emplace_back(YS[i]);
    G[YS[i]].emplace_back(XS[i]);
  }

  cout << (check() ? "Yes" : "No") << endl;
}
int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  int t;
  t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

// AC, graphs, check bipartite
