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

/*
	 Divide graph into strongly connected components and you will get a DAG. Number of edges you need to add is a maximum of numbers of vertices with 0 indegree and 0 outdegree (vertices = SCCs). That is a trivial lower bound, but to show that it is sufficient it is significantly harder :P.
 */

struct SCC {
  ll N;
  int totscc;
  vll2d adj, tadj;
  vll todo, comps, comp;
  vector<set<ll>> sccadj;
  vc vis;
	int id;
  SCC(ll _N)
    : N(_N), totscc(0), adj(_N), tadj(_N), comp(_N, -1), sccadj(_N), vis(_N), id(0) {}

  void add_edge(ll x, ll y) { adj[x].eb(y), tadj[y].eb(x); }

  void dfs(ll x) {
    vis[x] = 1;
    for (auto &y : adj[x])
      if (!vis[y]) dfs(y);
    todo.pb(x);
  }
  void dfs2(ll x, ll v) {
    comp[x] = v;
    for (auto &y : tadj[x])
      if (comp[y] == -1) dfs2(y, v);
  }
  void gen() {
    for (ll i = 0; i < N; ++i)
      if (!vis[i]) dfs(i);
    reverse(all(todo));
    for (auto &x : todo)
      if (comp[x] == -1) {
        dfs2(x, id);
				id++;
        comps.pb(x);
        totscc++;
      }
  }

  void genSCCGraph() {
    for (ll i = 0; i < N; ++i) {
      for (auto &j : adj[i]) {
        if (comp[i] != comp[j]) {
          sccadj[comp[i]].insert(comp[j]);
        }
      }
    }
  }
	int calc() {
		if(id == 1) return 0;
		vi indegree(id);
		vi outdegree(id);
		for(int i = 0; i < id; i++) {
			for(auto &u : sccadj[i]) {
				outdegree[i]++;
				indegree[u]++;
			}
		}

		int cntout = 0;
		int cntin = 0;
		for (int i = 0; i < id; i++) {
			cntout += outdegree[i] == 0;
			cntin += indegree[i] == 0;
		}

		return max(cntout, cntin);
	}
};


void run() {
	int n, m;
	cin >> n >> m;
	if(m == 0){
		cout << n << endl;
		return;
	}
	SCC scc(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		scc.add_edge(u, v);
	}
	
	scc.gen();
	scc.genSCCGraph();

	cout << scc.calc() << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}
