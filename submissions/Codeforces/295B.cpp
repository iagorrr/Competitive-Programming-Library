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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
// int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1'000'000'000;

const int MAXN(500);
int N;
vll2d G(MAXN + 1, vll(MAXN + 1, oo));

auto solve() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> G[i][j];
    }
  }

  vi xs;
  for (int i = 1; i <= N; i++) {
    ll xi;
    cin >> xi;
    xs.emplace_back(xi);
  }

  vll ans;
  vc canuse(N + 1, 0);
  reverse(all(xs));
  for (auto xi : xs) {
    canuse[xi] = true;

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        G[i][j] = min(G[i][xi] + G[xi][j], G[i][j]);
      }
    }

    ll cur = 0;
    for (int i = 1; i <= N; i++) {
      if (not canuse[i]) continue;

      for (int j = 1; j <= N; j++) {
        if (not canuse[j] or i == j) continue;

        cur += G[i][j];
      }
    }
    ans.emplace_back(cur);
  }

  for (auto it = ans.rbegin(); it != ans.rend(); it++) cout << *it << ' ';
  cout << endl;
}
int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  int t;
  t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

// AC, grphs, shortest paths, floyd warshall
