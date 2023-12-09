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

int N;
vi2d G;
vll XS;
vll HS;

void dfs(int u = 0, int h = 0) {
  HS[h] += XS[u];

  for (auto v : G[u]) {
    dfs(v, h + 1);
  }
}

auto solve() {
  cin >> N;
  G.resize(N);
  XS.resize(N);
  HS.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> XS[i];
  }

  for (int i = 1; i < N; i++) {
    int j;
    cin >> j;
    j--;
    G[j].emplace_back(i);
  }

  dfs();

  ll sum = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (HS[i] != 0) {
      sum = HS[i];
      break;
    }
  }
  if (sum == 0) {
    if (XS[0] == 0) {
      cout << 0 << endl;
    } else if (XS[0] > 0) {
      cout << '+' << endl;
    } else {
      cout << '-' << endl;
    }
  } else if (sum < 0) {
    cout << '-' << endl;
  } else {
    cout << '+' << endl;
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

/*
 * AC
 * Graphs
 * Math
 * BFS/DFS
 * https://atcoder.jp/contests/arc169/tasks/arc169_a
 * */
