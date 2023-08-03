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

bool make(ll v, const vector<vll> &depends, vll &order, vector<char> &done,
          vector<char> &doing) {
        doing[v] = true;
        for (auto &u : depends[v]) {
                if (doing[u]) return false;
                if (not done[u])
                        if (not make(u, depends, order, done, doing))
                                return false;
        }
        doing[v] = false;
        done[v] = true;
        order.pb(v);
        return true;
}
vll topologicalSorting(const vector<vll> &adj) {
        ll n = len(adj);
        vll order;
        vector<char> done(n);
        vector<char> doing(n);
        for (int i = 0; i < n; ++i)
                if (not done[i])
                        if (not make(i, adj, order, done, doing)) return {};
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
                adj[v].pb(u);
        }
        auto ans = topologicalSorting(adj);
        if (ans.empty())
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
