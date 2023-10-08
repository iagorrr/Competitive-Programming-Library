#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
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

auto solve() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  S = '#' + S;
  int Q;
  cin >> Q;
  vi2d xss(N + 1);
  while (Q--) {
    int K;
    cin >> K;
    if (len(xss[K]))
      xss[K].pop_back();
    else
      xss[K].emplace_back(K);
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (len(xss[i]) & 1) {
      S[i] = '1' - S[i] + '0';
    }

    if (S[i] == '1') {
      ans++;
      xss[i].emplace_back(i);
      S[i] = '0';
    }

    while (not xss[i].empty()) {
      auto ki = xss[i].back();
      if (i + ki <= N) xss[i + ki].emplace_back(ki);
      xss[i].pop_back();
    }
  }

  cout << ans;
}
int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  int t;
  t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
    cout << endl;
  }
}

// AC, ad-hoc
