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
void dfs(ll u, vector<char> &visited, const vector<vll> &g, vll &scc,
         bool pass) {
        visited[u] = true;
        for (auto &v : g[u])
                if (!visited[v]) dfs(v, visited, g, scc, pass);
 
        // if it's the first pass, add the node to the scc
        if (pass) scc.eb(u);
}
 
vll kosajaru(vector<vll> &g) {
        ll n = len(g);
        vll scc;
        vector<char> visited(n);
        for (ll i = 0; i < n; i++)
                if (!visited[i]) dfs(i, visited, g, scc, true);
 
        // build the transposed graph
        vector<vll> gt(n);
        for (int i = 0; i < n; ++i)
                for (auto &v : g[i]) gt[v].eb(i);
 
        // run the dfs on the previous scc order
        ll scccnt = 0;
        visited.assign(n, false);
        reverse(all(scc));
        vll scc_e;
        for (auto &scc_i : scc) {
                if (!visited[scc_i]) {
                        dfs(scc_i, visited, gt, scc, false), scccnt++;
                        scc_e.eb(scc_i);
                }
        }
        return scc_e;
}
 
int32_t main() {
        ll n, m;
        cin >> n >> m;
        vector<vll> g(n);
        for (int i = 0; i < m; ++i) {
                ll u, v;
                cin >> u >> v;
                u--, v--;
                g[u].eb(v);
        }
        auto ans = kosajaru(g);
 
        if (len(ans) == 1)
                cout << "YES\n";
        else {
                cout << "NO\n";
                cout << ans.back() << ' ' << ans.front() << '\n';
        }
}

// AC, graphs, scc, kosajaru
