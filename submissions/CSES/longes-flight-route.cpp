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
using vi = vector<int>;
using pii = pair<int, int>;
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
/*
 * O(V)
 * assumes:
 *      * vertices have index [0, n-1]
 * if is a DAG:
 *     * returns a topological sorting
 * else:
 *    * returns an empty vector
 * */
enum class state { not_visited, processing, done };
bool dfs(const vector<vll> &adj, ll s, vector<state> &states, vll &order) {
        states[s] = state::processing;
        for (auto &v : adj[s]) {
                if (states[v] == state::not_visited) {
                        if (not dfs(adj, v, states, order)) return false;
                } else if (states[v] == state::processing)
                        return false;
        }
        states[s] = state::done;
        order.pb(s);
        return true;
}
vll topologicalSorting(const vector<vll> &adj) {
        ll n = len(adj);
        vll order;
        vector<state> states(n, state::not_visited);
        for (int i = 0; i < n; ++i) {
                if (states[i] == state::not_visited) {
                        if (not dfs(adj, i, states, order)) return {};
                }
        }
        // reverse(all(order));
        return order;
}
void run() {
        ll n, m;
        cin >> n >> m;
        vector<vll> adj(n);
        for (int i = 0; i < m; ++i) {
                ll u, v;
                cin >> u >> v, u--, v--;
                // v can be reached from u
                adj[v].pb(u);
        }

        // gets the possible order of visitation
        auto order = topologicalSorting(adj);

        /*
         * Sets the longest path from node_i to node 1
         * ans their respective parents
         * */
        vll parent(n, -1);
        vll dists(n, -1);
        dists[0] = 0;
        for (auto &u : order) {
                for (auto &v : adj[u]) {
                        if (dists[u] < dists[v] + 1 and dists[v] >= 0) {
                                dists[u] = dists[v] + 1;
                                parent[u] = v;
                        }
                }
        }

        // reconstruct the path based in each parent
        ll cur = n - 1;
        vll ans;
        while (cur > 0) {
                ans.eb(cur+1);
                cur = parent[cur];
                if(cur == 0) ans.pb(1);
        }
        if (ans.front() != n or ans.back() != 1) {
                cout << "IMPOSSIBLE\n";
                return;
        }
        cout << len(ans) << '\n';
        for (int i = len(ans) - 1; i >= 0; --i) {
                cout << ans[i] << ' ';
        }
        cout << endl;
}

int32_t main(void) {
        fastio;
        int t;
        t = 1;
        while (t--) run();
}

// AC, graphs, topological sorting
