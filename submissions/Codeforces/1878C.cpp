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

ll maxn = 2 * 1e5;
vll psum(maxn + 1, 0);

ll nfirst(ll n) { return (n * (n + 1ll)) / 2ll; }
auto solve() {
  ll n, k, x;
  cin >> n >> k >> x;

  if (x > nfirst(n)) return false;
  if (nfirst(k) > x) return false;
  if ((n - k + 1ll + n) * k / 2ll < x) return false;
  // // bb pra achar algum prefixo que dê.
  // ll l1 = 0, r1 = k;
  // while (l1 <= r1) {
  //   ll mid1 = (r1 - l1) / 2 + l1;
  //   if (psum[mid1] > x) {
  //     r1 = mid1 - 1;
  //   } else {
  //     // checar se completando com o sufixo da certo
  //     ll ck = k - mid1;
  //     ll finalzin = psum[n] - psum[n - ck];
  //     ll delta = psum[mid1] + finalzin - x;
  //     if (delta == 0) return true;
  //     l1 = mid1 + 1;
  //   }
  // }

  return true;
}
int32_t main(void) {
  fastio;
  for (ll i = 1; i <= maxn; i++) {
    psum[i] = psum[i - 1] + i;
  }
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

// AC, math
