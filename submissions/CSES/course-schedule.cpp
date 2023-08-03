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

/*
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
        vector<state> states(n);
        for (int i = 0; i < n; ++i) {
                if (states[i] == state::not_visited) {
                        if (not dfs(adj, i, states, order)) return {};
                }
        }
        reverse(all(order));
        return order;
}
void run() {
        ll n, m;
        cin >> n >> m;
        vector<vll> adj(n);
        for (int i = 0; i < m; i++) {
                ll u, v;
                cin >> u >> v;
                u--, v--;
                adj[u].pb(v);
        }
        auto ans = topologicalSorting(adj);
        if (len(ans) == 0)
                cout << "IMPOSSIBLE\n";
        else
                for_each(all(ans), [](ll &x) { cout << x + 1 << ' '; }),
                        cout << '\n';
}
int32_t main(void) {
        fastio;
        int t;
        t = 1;
        // cin >> t;
        while (t--) run();
}

// AC, graphs, topological sorting
