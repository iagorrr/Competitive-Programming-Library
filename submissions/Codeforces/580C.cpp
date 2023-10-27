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

void dfs(int u, int p, int cnt, vi2d &g, vi &iscat, int maxcat,  int &ans) {
	if (iscat[u] != 0) {
	 	cnt++;
	}
	else cnt = 0;

	if (cnt > maxcat) { return; }
	
	bool isleaf = true;
	for (auto &v : g[u]) if ( v != p ) {
		dfs(v, u, cnt, g, iscat, maxcat, ans);
		isleaf = false;
	}
	ans += isleaf;
}
void run() {
	int n, m;
	cin >> n >> m;

	vi iscat(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> iscat[i];
	}

	vi2d g(n+1);
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	int ans = 0;

	dfs(1, -1, 0, g, iscat, m, ans); 

	cout << ans << endl;
}
int32_t main(void) {
  // fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graphs, trees, dfs/bfs
