#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define int long long
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

/*
 * - I guess that thre is a cycle in it and we can use it
 * - it's a functional graph with N vertices and N edges so
 * there is at least one cycle
 * - simulate until find one and than take it modulo K and
 * simulate the rest !
 *
 * */

ll N, K;
vi XS;
vector<pll> G;  // node and 'weight'

void build() {
  ll w = 0;

  set<ll> vis;
  for (;;) {
    ll u = w % N;
    if (vis.count(u)) break;
    ll v = (w + XS[w % N]) % N;
    G[u] = {v, XS[w % N]};
    vis.emplace(u);
    w = w + XS[w % N];
  }
}

int csize, fc = -1;
ll cw;
vll de;
vll dw;

void dfs(int u = 0, ll acc_w = 0, int d = 0) {
  dw[u] = acc_w;
  de[u] = d;
  auto [v, wv] = G[u];
  assert(wv);
  dbg(v);
  if (de[v] == -1)
    dfs(v, acc_w + wv, d + 1);
  else {
    csize = de[u] - de[v] + 1;
    cw = dw[u] - dw[v] + wv;
    fc = v;
  }
}

auto run() {
  cin >> N >> K;
  G.resize(N), de.resize(N, -1), dw.resize(N, 0);
  XS.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> XS[i];
  }

  build();
  dbg(G);

  dfs();

  dbg(fc, csize, cw, de[fc]);

  ll ans = 0;

  if (de[fc] < K) {
    ans += dw[fc];
    K -= de[fc];

    ll rounds = K / csize;
    ans += rounds * cw;
    K -= rounds * csize;
  } else
    fc = 0;

  for (int i = 0, u = fc; i < K; i++, u = G[u].first) {
    auto [v, wv] = G[u];
    ans += wv;
  }

  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (ll t = 1; t <= T; t++) {
    run();
  }
}

// AC, number theory, functional graph
