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
 * Returns the number of ways to reach u
 * */
const ll mod = 1e9 + 7;
ll solve(const vector<vll> &adj, ll u, vll &ways) {
        if (ways[u] != -1) return ways[u];
        ll tmp = 0;
        for (auto &v : adj[u]) {
                ll wv = solve(adj, v, ways);
                tmp = (tmp + wv) % mod;
        }
        return ways[u] = tmp;
}
void run() {
        ll n, m;
        cin >> n >> m;
        vector<vll> adj(n);
        for (int i = 0; i < m; ++i) {
                ll u, v;
                cin >> u >> v, u--, v--;
                adj[v].pb(u);
        }

        vll ways(n, -1);
        ways[0] = 1;
        ll ans = solve(adj, n - 1, ways);
        cout << ans << '\n';
}

int32_t main(void) {
        fastio;
        int t;
        t = 1;
        while (t--) run();
}
// AC, graphs, dp
