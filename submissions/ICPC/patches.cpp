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

const int inf = 1e9;

vi dp(1e3+1, inf);
int solve(int p, int n, int t1, int t2, const vi &v) {
	if (p == n) return 0;
	if(dp[p] != inf) return dp[p];

	// using the first tire
	int j = p + 1;
	int ans = inf;
	while (j < n and v[j] <= v[p] + t1) j++;
	ans = min(ans, t1+solve(j, n, t1, t2, v));

	// using the second tire
	j = p + 1;
	while (j < n and v[j] <= v[p] + t2) j++;
	ans = min(ans, t2+solve(j, n, t1, t2, v));

	return dp[p] = ans;
}
void run() {
	int n, c, t1, t2;
	cin >> n >> c >> t1 >> t2;

	vi xs(n);
	for (auto &xi : xs) cin >> xi;

	cout << solve(0, n, t1, t2, xs) << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, dynamic programming, (this question is with a poor statement)
