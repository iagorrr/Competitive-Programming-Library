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

ll sumdigits(ll x) {
  ll ans = 0;

  while (x) {
    ans += (x%10);
    x /= 10;
  }

  return ans;
}
ll next(ll k) {
  return k - sumdigits(k);
}
vll hist(1e6 + 1);
void run() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    hist[x]++;
  }

  ll ans = 0;
  for (int i = 1e6; i >= 0; i--) {
    if (not hist[i]) continue;
    
    if (hist[i] < k) {
      hist[next(i)] += hist[i];
      k -= hist[i];
      hist[i] = 0;
    }
    else {
      ans = sumdigits(i);
      break;
    } 

  }

  cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, ad-hoc
