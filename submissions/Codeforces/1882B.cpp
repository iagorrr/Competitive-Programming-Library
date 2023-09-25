#include <bits/stdc++.h>
using namespace std;
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
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ll oo = 1e18;
auto solve() {
  int n;
  cin >> n;
  vll hist(51, 0);
  vll es;
  vll2d tenho(n);
  vll2d quemtem(51);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    while (m--) {
      ll xi;
      cin >> xi;
      if (hist[xi] == 0) es.eb(xi);
      hist[xi]++;
      tenho[i].eb(xi);
      quemtem[xi].emplace_back(i);
    }
  }

  // quero remover pelo menos o ei
  ll ans = 0;
  for (auto ei : es) {
    for (auto qti : quemtem[ei]) {
      for (auto ti : tenho[qti]) {
        hist[ti]--;
      }
    }

    ll cnt = 0;
    for (int i = 0; i <= 50; i++) {
      cnt += hist[i] != 0;
    }
    // cout << "ei: " << ei << " cnt : " << cnt << endl;
    ans = max(ans, cnt);

    for (auto qti : quemtem[ei]) {
      for (auto ti : tenho[qti]) {
        hist[ti]++;
      }
    }
  }
  cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
}

// AC, bitmasks, brute force
