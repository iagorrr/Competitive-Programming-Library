#include <bits/stdc++.h>

#include <algorithm>
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
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
template <class T, class U>
inline void chmin(T &a, U b) {
  if (a > b) a = b;
}
template <class T, class U>
inline void chmax(T &a, U b) {
  if (a < b) a = b;
}

template <class T, class U>
auto &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.ff >> p.ss;
}
template <class T, class U>
auto &operator<<(ostream &os, pair<T, U> const &p) {
  return os << '{' << p.first << ' ' << p.second << '}';
}

const auto ES = "", SEP = " ";
template <class T>
auto &operator>>(istream &is, vector<T> &c) {
  for (auto &x : c) is >> x;
  return is;
}
template <class T>
auto &operator<<(ostream &os, vector<T> const &c) {
  auto sep = ES;
  for (auto x : c) os << sep << x, sep = SEP;
  return os;
}
template <class T>
auto &operator<<(ostream &os, set<T> const &c) {
  auto sep = ES;
  for (auto x : c) os << sep << x, sep = SEP;
  return os;
}
template <class T>
auto &operator<<(ostream &os, multiset<T> const &c) {
  auto sep = ES;
  for (auto x : c) os << sep << x, sep = SEP;
  return os;
}
template <class T>
auto &operator<<(ostream &os, unordered_set<T> const &c) {
  auto sep = ES;
  for (auto x : c) os << sep << x, sep = SEP;
  return os;
}
template <class T>
auto &operator<<(ostream &os, ordered_set<T> const &c) {
  auto sep = ES;
  for (auto x : c) os << sep << x, sep = SEP;
  return os;
}
template <class T>
auto &operator<<(ostream &os, deque<T> const &c) {
  auto sep = ES;
  for (auto x : c) os << sep << x, sep = SEP;
  return os;
}
template <class K, class V>
auto &operator<<(ostream &os, map<K, V> const &c) {
  auto sep = ES;
  for (auto x : c) os << sep << x, sep = SEP;
  return os;
}
template <class K, class V>
auto &operator<<(ostream &os,
                 unordered_map<K, V> const &c) {
  auto sep = ES;
  for (auto x : c) os << sep << x, sep = SEP;
  return os;
}

template <class... A>
void in(A &...a) {
  ((cin >> a), ...);
}
template <class... A>
void out(A const &...a) {
  auto sep = ES;
  ((cout << sep << a, sep = SEP), ...);
  cout << '\n';
}
template <class... A>
void print(A const &...a) {
  ((cout << a), ...);
}
#define var(x) "[", #x, " ", x, "] "
template <class... A>
void db(A const &...a) {
  ((cout << (a)), ...);
  cout << endl;
}
//}}}

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
const int MAXN(1'000'000);

struct SCC {
  int N, totscc;
  vi2d g, tg;
  vi todo, comp;
  vector<set<ll>> gscc;
  vc vis;
  SCC(int _N)
    : N(_N),
      totscc(0),
      g(_N),
      tg(_N),
      comp(_N, -1),
      gscc(_N),
      vis(_N) {}

  void add_edge(int x, int y) { g[x].eb(y), tg[y].eb(x); }

  void dfs(int x) {
    vis[x] = 1;
    for (auto y : g[x])
      if (!vis[y]) dfs(y);
    todo.pb(x);
  }
  void dfs2(ll x) {
    comp[x] = totscc;
    for (auto y : tg[x])
      if (comp[y] == -1) dfs2(y);
  }

  void build() {
    for (int i = 0; i < N; ++i)
      if (!vis[i]) dfs(i);
    reverse(all(todo));
    for (auto &x : todo)
      if (comp[x] == -1) {
        dfs2(x);
        totscc++;
      }

    for (int i = 0; i < N; ++i)
      for (auto j : g[i])
        if (comp[i] != comp[j])
          gscc[comp[i]].insert(comp[j]);
  }
};

auto run() {
  int n, m;
  cin >> n >> m;

  SCC scc(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a == b) continue;
    a--, b--;
    scc.add_edge(a, b);
  }

  scc.build();

  if (scc.totscc == 1) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
  auto g = scc.gscc;
  vi js, cs;

  for (int i = 0; i < n; i++) {
    if (len(g[scc.comp[i]])) continue;
    for (int j = 0; j < n; j++) {
      if (scc.comp[j] == scc.comp[i]) {
        js.eb(j + 1);
      } else
        cs.eb(j + 1);
    }
    break;
  }

  cout << len(js) << ' ' << len(cs) << '\n';
  out(js);
  out(cs);
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}
