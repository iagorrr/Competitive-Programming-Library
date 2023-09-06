#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
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

const ll oo = 1e18;

bool run() {
  int a, b;
  cin >> a >> b;

  if (a == 0 and b == 0) return true;

  if (a > b) swap(a, b);
  if (a * 2 < b) return false;
  if (a == 0 or b == 0) return false;

  int k = b - a - 1;
  if ((a - k) % 3 == 1 and (b - k*2) % 3 == 2) return true;
  if ((a - k) % 3 == 2 and (b - k*2) % 3 == 1) return true;
  if ((a - k) % 3 == 0 and (b - k*2) % 3 == 0) return true;

  return false;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    if (run())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

// AC, ad-hoc, math
