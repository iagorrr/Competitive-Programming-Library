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

int N, M;
ll XS[300][300];

vector<pii> bbsort(vll &xs) {
  int n = len(xs);
  vector<pii> ans;
  for (int i = 0; i < n; i++) {
    int k = i;
    for (int j = i + 1; j < n; j++) {
      if (xs[j] < xs[k]) k = j;
    }
    if (i != k) {
      ans.emplace_back(i, k);
      swap(xs[i], xs[k]);
    }
  }

  return ans;
}

bool check() {
  int cur = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (XS[i][j] != cur++) return false;
    }
  }
  return true;
}

auto solve() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> XS[i][j];
    }
  }

  vll line;
  vll column;
  for (int i = 0; i < N; i++) column.emplace_back(XS[i][0]);
  for (int i = 0; i < M; i++) line.emplace_back(XS[0][i]);

  auto movesline = bbsort(line);
  auto movescolumn = bbsort(column);
  ll moves = len(movesline) + len(movescolumn);

  for (auto &[i, j] : movescolumn) {
    swap(XS[i], XS[j]);
  }

  for (int i = 0; i < N; i++) {
    for (auto &[a, b] : movesline) {
      swap(XS[i][a], XS[i][b]);
    }
  }

  if (!check()) {
    cout << "*\n";
    return;
  }

  cout << moves << endl;
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
 * sorting
 * */
