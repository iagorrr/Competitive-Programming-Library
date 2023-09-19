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

const int maxn(2 * 1e5);
vll xs(maxn);
int n;
ll c;
ll check(ll k) {
  ll s = c;

  for (int i = 0; i < n; i++) {
    ll xi = (xs[i] + 2 * k);
    s -= (xi * xi);
    if (s < 0) return -1;
  }
  // cout << "k : " << k << " s: " << s << endl;
  return s;
}
void run() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  ll l = 1;
  ll r = 1e9;

  while (l <= r) {
    ll mid = (l + r) / 2;
    ;

    // cout << "l : " << l << " r: " << r << " mid: " << mid << endl;
    auto d = check(mid);
    if (d == 0) {
      cout << mid << endl;
      return;
    }

    if (d < 0)
      r = mid - 1;
    else
      l = mid + 1;
  }
}

int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) run();
}

// AC, binary search
