// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 666
#endif
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
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
#define INV(xxxx) \
    for (auto &xxx : xxxx) cin >> xxx;
#define PRINTV(___x) \
    for_each(all(___x), [](ll &____x) { cout << ____x << ' '; }), cout << '\n';
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
#define rsz(___x, ___n) resize(___x, ___n)

const ll INF = 1e18;


vll ans;
set<int> stl(int u, int p, vi &colors, vi2d &g) {
	set<int> st;
	st.insert(colors[u]);
	for(auto v : g[u]) if(v != p) {
		auto cst = stl(v, u, colors, g);
		if(len(cst) > len(st)) swap(st, cst);
		st.insert(all(cst));
	}
	ans[u] = len(st);
	return st;
}
void run() {
	int n; cin >> n;
	vi colors(n+1);
	for(int i = 0; i < n; i++) 
		cin >> colors[i], colors[i]--;

	vi2d g(n+1);
	for (int i = 0; i < n -1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	ans.resize(n+1);
	stl(0, -1, colors, g);

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;

}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    // cin >> t;
    while (t--) run();
}


// AC, trees, small to large
