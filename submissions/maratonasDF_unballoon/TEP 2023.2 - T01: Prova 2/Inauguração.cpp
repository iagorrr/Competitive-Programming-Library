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
const int MAXN(500);
int T(1);
int N;
vector<vector<pair<ll, int>>> G(MAXN), G2(MAXN);

ll prim(int g) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                 greater<pair<ll, int>>>
    pq;
  vector<char> ingraph(MAXN);
  int ingraphcnt(1);
  ingraph[0] = 1;
  ll mstcost = 0;

  for (auto [w, v] : (g ? G2[0] : G[0])) {
    pq.emplace(w, v);
  }

  while (ingraphcnt < N and not pq.empty()) {
    ll w;
    int v;

    do {
      tie(w, v) = pq.top();
      pq.pop();
    } while (not pq.empty() and ingraph[v]);
    mstcost += w, ingraph[v] = true, ingraphcnt++;

    for (auto &[w2, v2] : (g ? G2[v] : G[v])) {
      pq.emplace(w2, v2);
    }
  }

  return ingraphcnt == N ? mstcost : oo;
}

auto solve() {
  cin >> N;
  for (int i = 0; i < (N * (N - 1)) / 2; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    int p;
    cin >> p;
    if (p == 100) {
      G[a].emplace_back(0, b);
      G[b].emplace_back(0, a);
      G2[a].emplace_back(0, b);
      G2[b].emplace_back(0, a);
    } else {
      ll c, t;
      cin >> c >> t;
      G[a].emplace_back(c, b);
      G[b].emplace_back(c, a);
      G2[a].emplace_back(t, b);
      G2[b].emplace_back(t, a);
    }
  }

  ll c1 = prim(0);
  ll c2 = prim(1);
  if (c1 == 0 and c2 == 0) {
    cout << "Sim\n";
  } else {
    cout << "Nao\n";
    cout << c1 << ' ' << c2 << '\n';
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

// AC, graphs, mst
