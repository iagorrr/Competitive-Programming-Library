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

vll2d prod(vll2d &a, vll2d &b, ll n) {
  vll2d c(n, vll(n, 0));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      c[i][j] += a[i][j] * b[j][i];
    }
  }
  return c;
}
void run() {
  ll n;
  cin >> n;
  vll2d a(n, vll(n));
  vll2d b(n, vll(n));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> b[i][j];
    }
  }
  vll2d ab = prod(a, b, n);
  vll2d ba = prod(b, a, n);

  // if( eq(ab, ba, n)) {
  if (ab == ba) {
    cout << "comutam\n";
  } else {
    cout << "deu ruim\n";
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, implementation
