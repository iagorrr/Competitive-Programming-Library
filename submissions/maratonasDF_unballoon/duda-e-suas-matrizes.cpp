#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                        \
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

ll arithmeticProgressionSum(ll start, ll delta, ll n) {
	return (start + (start+delta*(n-1)))*n/2ll;
}
ll calc(ll i, ll j, ll n) {
	 ll delta = i;
	 ll k = max(i, j) + 1;
	 ll start = k * i + (j+1);
	 ll l = max(i, j);
	 ll qtd = n-l;
	 ll ans = arithmeticProgressionSum(start, delta, qtd);
	 return ans;
}
void run() {
  ll n, q;
  cin >> n >> q;
  while(q--) {
	  ll i, j;
	  cin >> i >> j;
	  i--, j--;
	  cout << calc(i, j, n) << endl;
  }

}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    // cin >> t;
    while (t--) run();
}

// AC, math
