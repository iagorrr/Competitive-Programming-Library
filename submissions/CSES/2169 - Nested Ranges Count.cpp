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
// #define int long long
//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
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

auto run() {
  int N;
  cin >> N;
  vector<tuple<ll, ll, ll>> XS(N);

  int cid = 0;
  for (auto &[a, b, id] : XS) {
    cin >> a >> b;
    b = -b;
    id = cid++;
  }

  sort(all(XS));

  vi contains(N), contained(N);

  dbg(XS);
  ordered_set<pll> st;
  ll fk = 0;
  for (int i = 0; i < N; i++) {
    auto [l, r, id] = XS[i];
    dbg(i, st, l, r, id);

    int containme = len(st) - st.order_of_key({-r, --fk});
    contained[id] = containme;

    st.insert({-r, --fk});
  }

  st.clear();
  fk = 0;
  for (int i = N - 1; i >= 0; i--) {
    auto [l, r, id] = XS[i];
    contains[id] = st.order_of_key({-r, ++fk});
    st.insert({-r, ++fk});
  }

  for (int i = 0; i < N; i++) {
    cout << contains[i] << " \n"[i == N - 1];
  }
  for (int i = 0; i < N; i++) {
    cout << contained[i] << " \n"[i == N - 1];
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, sortings, data structures
