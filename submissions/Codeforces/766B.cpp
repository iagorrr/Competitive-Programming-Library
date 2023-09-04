#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int) __x.size()
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

const ll INF = 1e18;

bool check(int a, int b, int c) {
	return a + b > c and a + c > b and b + c > a;
}
void run() {
	int n;
	cin >> n;
	vector<int> xs(n);
	for (int i = 0; i < n; i++) cin >> xs[i];
	sort(all(xs));
	
	for (int i = 0; i < n-2; i++) {
		if (check(xs[i], xs[i+1], xs[i+2])) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

	// AC, geometry, greedy
