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
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define rsz resize

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
ll dpsolve(ll v, const vector<set<ll>> &g, const vll &pts, vll &dpmemo) {
        if (dpmemo[v] != 0) return dpmemo[v];
        ll ans = pts[v];
        for (auto &u : g[v]) {
                ans = max(ans, pts[v] + dpsolve(u, g, pts, dpmemo));
        }
        return dpmemo[v] = ans;
}

struct SCC {
        ll N;
        vll2d adj, tadj;
        vll todo, comps, comp;
        vector<set<ll>> sccadj;
        vchar vis;
        SCC(ll _N)
                : N(_N), adj(_N), tadj(_N), comp(_N, -1), sccadj(_N), vis(_N) {}

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
                                dfs2(x, x);
                                comps.pb(x);
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
};

int32_t main() {
        // fastio;
        ll n, m;
        cin >> n >> m;
        vll coins(n);
        INV(coins);
        SCC scc(n);
        for (int i = 0; i < m; ++i) {
                ll u, v;
                cin >> u >> v;
                scc.add_edge(u - 1, v - 1);
        }

        scc.gen();

        vll coins2(n);
        for (int i = 0; i < n; ++i) {
                coins2[scc.comp[i]] += coins[i];
        }

        scc.genSCCGraph();

        ll ans = 0;
        vll dpmemo(n, 0);
        for (int i = 0; i < n; ++i) {
                ans = max(ans, dpsolve(i, scc.sccadj, coins2, dpmemo));
        }
        cout << ans << endl;
}

// AC, graph, SCC
