#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
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
const int MAXN(1'000'000);

using a3 = array<ll, 3>;
auto run() {
  int n;
  cin >> n;

  vll atk(n + 2), def(n + 2);
  atk[0] = atk[n + 1] = 0;
  def[0] = def[n + 1] = 2'000'000'000 + 1;
  for (int i = 1; i <= n; i++) cin >> atk[i];
  for (int i = 1; i <= n; i++) cin >> def[i];

  set<int> rmv;
  set<ll> st;
  st.insert(0), st.insert(n + 1);
  for (int i = 1; i <= n; i++) {
    st.insert(i);
    if (atk[i + 1] + atk[i - 1] > def[i]) rmv.emplace(i);
  }

  for (int i = 1; i <= n; i++) {
    cout << len(rmv) << " \n"[i == n];

    set<int> maybe;
    for (auto rmvi : rmv) {
      auto it = st.find(rmvi);
      int l = *prev(it);
      int r = *next(it);
      if (l != 0) maybe.emplace(l);
      if (r != n + 1) maybe.emplace(r);
    }

    for (auto rmvi : rmv) st.erase(rmvi);
    rmv.clear();

    for (auto mi : maybe) {
      if (st.find(mi) == st.end()) continue;
      auto it = st.find(mi);
      int l = *prev(it);
      int r = *next(it);
      if (atk[l] + atk[r] > def[mi]) rmv.emplace(mi);
    }
  }
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

/*
 * AC
 * Data Structures
 * https://codeforces.com/contest/1922/problem/D
 * */
