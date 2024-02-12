#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
#define endl '\n'
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
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
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define rep(i, begin, end)                              \
  for (__typeof(begin) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end));                  \
       i += 1 - 2 * ((begin) > (end)))

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
const int MAXN(1'50'000);

vi G[MAXN + 1];
ll ans[MAXN + 1][4];

int N, M;

int dist[MAXN + 1];
void calc(int s) {
  fill(dist, dist + N + 1, -1);
  queue<int> q;

  q.emplace(s);
  dist[s] = 0;

  for (auto u = q.front(); !q.empty();
       q.pop(), u = q.front()) {
    for (int i = dist[u]; i <= 3; i++) ans[s][i] += u;

    if (dist[u] == 3) continue;

    for (auto v : G[u]) {
      if (dist[v] == -1) {
        q.emplace(v);
        dist[v] = dist[u] + 1;
      }
    }
  }
}

auto run() {
  cin >> N >> M;

  for (int i = 1, a, b; i <= M; i++) {
    cin >> a >> b;
    G[a].eb(b), G[b].eb(a);
  }

  for (int i = 1; i <= N; i++) calc(i);

  int Q;
  cin >> Q;
  while (Q--) {
    int xi, ki;
    cin >> xi >> ki;

    cout << ans[xi][ki] << '\n';
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

// AC, graphs, bfs
