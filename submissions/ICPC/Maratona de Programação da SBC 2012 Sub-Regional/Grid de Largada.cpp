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

const ll oo = 1e18;
int n;

auto solve() {
  vi pos(n + 1), final(n + 1), simul(n + 1);
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    cin >> simul[i];
    pos[simul[i]] = i;
  }

  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;

    if (pos[k] <= i) continue;

    while (pos[k] != i) {
      ans++;
      swap(simul[pos[k]], simul[pos[k] - 1]);
      pos[simul[pos[k]]]++;
      pos[k]--;
    }
  }

  cout << ans << endl;
}
int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif
  while (cin >> n) {
    solve();
  }
}

// AC, Ad-hoc, simulation, implementation
