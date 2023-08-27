#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (ll) __x.size()
using ll = long long;
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

const ll INF = 1e18;

void run() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int m;
  cin >> m;
  vector<pair<int, int>> v(m);
  int i = 0;
  for (auto &[x, y] : v) {
    string a;
    cin >> a;
    for (int i = 0; i < n; i++) x += s[i] == a[i];
    y = --i;
  }

  sort(all(v), greater<pair<int, int>>());

  for (int i = 0; i < m; i++) cout << -v[i].second << " \n"[i == m - 1];
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, ad-hoc
