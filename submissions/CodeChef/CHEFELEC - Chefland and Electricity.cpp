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

const int MAXN(1'00'000);
int N;
string hs;
vll xs(MAXN);

vector<pair<ll, int>> G[MAXN];
ll prim(vi s = vi(1, 0)) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                 greater<pair<ll, int>>>
    pq;
  vector<char> ingraph(MAXN);
  int ingraphcnt(0);
  for (auto si : s) {
    ingraphcnt++;
    ingraph[si] = true;
    for (auto &[w, v] : G[si]) pq.emplace(w, v);
  }

  ll mstcost = 0;
  while (ingraphcnt < N) {
    ll w;
    int v;

    do {
      tie(w, v) = pq.top();
      pq.pop();
    } while (not pq.empty() and ingraph[v]);

    mstcost += w, ingraph[v] = true, ingraphcnt++;

    for (auto &[w2, v2] : G[v]) {
      pq.emplace(w2, v2);
    }
  }

  return ingraphcnt == N ? mstcost : oo;
}

auto solve() {
  cin >> N;
  cin >> hs;

  vector<pii> vs;
  for (int i = 0; i < N; i++) {
    G[i].clear();
    int pos;
    cin >> pos;
    vs.emplace_back(pos, i);
  }
  sort(all(vs));

  for (int i = 0; i < N - 1; i++) {
    auto [pos, u] = vs[i];
    auto [pos2, u2] = vs[i + 1];
    ll dist = pos2 - pos;
    G[u].emplace_back(dist, u2);
    G[u2].emplace_back(dist, u);
  }

  vi sources;
  for (int i = 0; i < N; i++) {
    if (hs[i] == '1') sources.emplace_back(i);
  }

  cout << prim(sources) << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}

/*
 * AC
 * graphs
 * greedy
 * prim
 * https://www.codechef.com/JULY16/problems-old/CHEFELEC
 * */
