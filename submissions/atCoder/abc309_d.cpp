// iagorrr ;)
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)


void dbg_out() { cerr << endl; }
template <typename H, typename... T> void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                                                               \
  {                                                                            \
    cerr << #__VA_ARGS__ << ':';                                               \
    dbg_out(__VA_ARGS__);                                                      \
  }

ll maxdistance(vector<vll> adj, ll root, ll n) {
        vector<char> vis(n+1);
        vis[root] = true;
        ll dist = 0;
        queue<pair<ll, ll>> q;
        q.emplace(root, 0);
        while(!q.empty()){
                auto [u, d] = q.front(); q.pop();
                dist = max(dist, d);

                for(auto v : adj[u]){
                        if(!vis[v]) {
                                vis[v] = true;
                                q.emplace(v, d+1);
                        }
                }
        }
        return dist;
}
void run() {
        ll n1, n2, m; cin >> n1 >> n2 >> m;
        vector<vll> adj(n1+n2+1);
        for(int i = 0; i < m; ++i) {
                ll u, v; cin >> u  >> v;
                adj[u].pb(v);
                adj[v].pb(u);
        }

        auto d1 = maxdistance(adj, 1, n1+n2+1);
        auto d2 = maxdistance(adj, n1+n2, n1+n2+1);
        cout << d1 + 1 + d2 << '\n';
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	while (t--)
		run();
}

// AC, bfs, max distance
