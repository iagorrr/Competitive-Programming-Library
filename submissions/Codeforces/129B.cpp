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

void run() {
	int n, m;
	cin >> n >> m;
	
	vector<set<int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].insert(b);
		g[b].insert(a);
	}

	int ans = 0;
	for (;;) {
		vi toerase;
		for (int i = 0; i < n; i++) {
			if (len(g[i]) == 1) {
				toerase.pb(i);
			}
		}

		if ( not toerase.empty() ) {
			ans ++;
			for (auto &i : toerase) {
				for (auto &j : g[i]) {
					g[j].erase(i);
				}
				g[i].clear();
			}

		}
		else break;
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

// graphs, bfs/dfs
