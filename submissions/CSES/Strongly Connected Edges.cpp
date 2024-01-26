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

int N, M;
vi G[MAXN];
vector<pii> ans;

int tin[MAXN], clk, low[MAXN];
void build(int u = 0, int p = -1) {
  tin[u] = low[u] = ++clk;

  for (auto v : G[u]) {
    if (v == p) continue;

    if (!tin[v]) {
      ans.eb(u, v);
      build(v, u);

      if (low[v] > tin[u]) {
        cout << "IMPOSSIBLE\n";
        exit(0);
      }

      low[u] = min(low[u], low[v]);

    } else if (tin[v] < tin[u]) {
      ans.eb(u, v);
      low[u] = min(low[u], tin[v]);
    }
  }
}

auto run() {
  cin >> N >> M;

  for (int i = 0, a, b; i < M; i++) {
    cin >> a >> b;
    a--, b--;
    G[a].eb(b), G[b].eb(a);
  }

  build();

  for (int i = 0; i < N; i++) {
    if (!tin[i]) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }

  for (auto [a, b] : ans) {
    cout << a + 1 << ' ' << b + 1 << '\n';
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
