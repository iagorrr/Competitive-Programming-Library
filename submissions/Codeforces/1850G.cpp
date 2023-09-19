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

void run() {
  int n;
  cin >> n;
  map<ll, ll> ls;
  map<ll, ll> cs;
  map<ll, ll> d1s;
  map<ll, ll> d2s;

  vector<pll> xs(n);
  for (auto &[a, b] : xs) {
    cin >> a >> b;

    ls[a]++;
    cs[b]++;

    // d1 pra cima
    if (b <= 0) {
      d1s[a + abs(b)]++;
      d2s[a - abs(b)]++;
    } else {  // d1 pra baixo
      d1s[a - abs(b)]++;
      d2s[a + abs(b)]++;
    }
  }

  ll ans = 0;
  for (auto &[a, b] : xs) {
    auto l = a;
    auto c = b;

    // d1 pra cima
    ll d1, d2;
    if (b <= 0) {
      d1 = a + abs(b);
      d2 = a - abs(b);
    } else {  // d1 pra baixo
      d1 = a - abs(b);
      d2 = a + abs(b);
    }

    ans += ls[l] - 1;
    ans += cs[c] - 1;
    ans += d1s[d1] - 1;
    ans += d2s[d2] - 1;
  }
  cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) run();
}

// AC, geometry, data structures
