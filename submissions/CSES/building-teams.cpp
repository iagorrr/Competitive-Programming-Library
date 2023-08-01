// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                            \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx) \
        for (auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) {
        cerr << ' ' << h;
        dbg_out(t...);
}
#define dbg(...)                             \
        {                                    \
                cerr << #__VA_ARGS__ << ':'; \
                dbg_out(__VA_ARGS__);        \
        }
const ll INF = 1e18;

// O(V)
pair<bool, vll> checkBipartite(const ll n, const vector<vll> &adj) {
        queue<ll> q;
        vll color(n, INF);
        bool isBipartite = true;
        for (int i = 0; i < n; ++i) {
                if(color[i] != INF) continue;
                q.push(i);
                color[i] = 0;
                while (!q.empty() && isBipartite) {
                        ll u = q.front();
                        q.pop();
                        for (auto &v : adj[u]) {
                                if (color[v] == INF) {
                                        color[v] = 1 - color[u];
                                        q.push(v);
                                } else if (color[v] == color[u]) {
                                        return {false, vll()};
                                }
                        }
                }
        }
        return {true, color};
}
void run() {
        ll n, m;
        cin >> n >> m;
        vector<vll> adj(n);
        for (int i = 0; i < m; ++i) {
                ll u, v;
                cin >> u >> v;
                --u, --v;
                adj[u].pb(v);
                adj[v].pb(u);
        }

        auto ans = checkBipartite(n, adj);
        if (!ans.fst) {
                cout << "IMPOSSIBLE\n";
                return;
        }
        for (int i = 0; i < n; ++i) {
                cout << ans.snd[i] + 1 << ' ';
        }
        cout << endl;
        return;
}
int32_t main(void) {
        // fastio;
        int t;
        t = 1;
        while (t--) run();
}

// AC, graph, bipartite
