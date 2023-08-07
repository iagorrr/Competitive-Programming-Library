// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                            \
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
using pii = pair<int, int>;
using vii = vector<pii>;
using vchar = vector<char>;
#define all(a) a.begin(), a.end()
#define INV(xxxx) \
        for (auto &xxx : xxxx) cin >> xxx;
#define PRINTV(___x)                                                  \
        for_each(all(___x), [](ll &____x) { cout << ____x << ' '; }), \
                cout << '\n';
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
void dfs(ll u, vchar &visited, const vll2d &g, vll &scc, bool buildScc, ll id,
         vll &sccid) {
        visited[u] = true;
        sccid[u] = id;
        for (auto &v : g[u])
                if (!visited[v]) dfs(v, visited, g, scc, buildScc, id, sccid);

        // if it's the first pass, add the node to the scc
        if (buildScc) scc.eb(u);
}

pair<ll, vll> kosajaru(vll2d &g) {
        ll n = len(g);
        vll scc;
        vchar vis(n);
        vll sccid(n);
        for (ll i = 0; i < n; i++)
                if (!vis[i]) dfs(i, vis, g, scc, true, 0, sccid);

        // build the transposed graph
        vll2d gt(n);
        for (int i = 0; i < n; ++i)
                for (auto &v : g[i]) gt[v].eb(i);

        // run the dfs on the previous scc order
        ll id = 0;
        vis.assign(n, false);
        for (ll i = len(scc) - 1; i >= 0; i--)
                if (!vis[scc[i]]) {
                        dfs(scc[i], vis, gt, scc, false, id++, sccid);
                }
        return {id - 1, sccid};
}

// ans2 = max(ans2, dpsolve(i, g2, coins2, dpmemo));
ll dpsolve(ll v, const vector<set<ll>> &g, const vll &pts, vll &dpmemo) {
        if (dpmemo[v] != 0) return dpmemo[v];
        ll ans = pts[v];
        for (auto &u : g[v]) {
                ans = max(ans, pts[v] + dpsolve(u, g, pts, dpmemo));
        }
        return dpmemo[v] = ans;
}
int32_t main() {
        fastio;
        ll n, m;
        cin >> n >> m;
        vll coins(n);
        INV(coins);
        vll2d g(n);
        for (int i = 0; i < m; ++i) {
                ll u, v;
                cin >> u >> v;
                u--, v--;
                g[u].eb(v);
        }
        auto ans = kosajaru(g);
        vll coins2(n, 0);                 // total points in each SCC
        vector<set<ll>> g2(ans.fst + 1);  //  new graph, sse each SCC as a node
        for (int i = 0; i < n; ++i) {
                ll cscc = ans.snd[i];
                for (auto &v : g[i]) {
                        ll vscc = ans.snd[v];
                        if (cscc != vscc) {
                                g2[cscc].insert(vscc);
                        }
                }

                coins2[cscc] += coins[i];
        }

        vll dpmemo(ans.fst + 1, 0);
        ll ans2 = 0;
        for (int i = 0; i < ans.fst; ++i) {
                ans2 = max(ans2, dpsolve(i, g2, coins2, dpmemo));
        }
        cout << ans2 << '\n';
}

// AC, graphs, SCC, kosajaru
