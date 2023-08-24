// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 666
#endif
#define endl '\n'
#define fastio                        \
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
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define INV(xxxx) \
    for (auto &xxx : xxxx) cin >> xxx;
#define PRINTV(___x) \
    for_each(all(___x), [](ll &____x) { cout << ____x << ' '; }), cout << '\n';
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
#define rsz(___x, ___n) resize(___x, ___n)

const ll INF = 1e18;

void dfsfoda(int u, int h, const vi2d &g, vi &vis, const vi &hs) {
    h = max(h, hs[u]);
    vis[u] = h;
    if (h == 0) return;

    for (auto &v : g[u])
        if (vis[v] < h - 1) {
            dfsfoda(v, h - 1, g, vis, hs);
        }
}
void run() {
    int n, m, k;
    cin >> n >> m >> k;

    vi2d g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    vi hs(n);
    vii ps;
    for (int i = 0; i < k; i++) {
        int p, h;
        cin >> p >> h;
        p--;
        hs[p] = h;
        ps.emplace_back(h, p);
    }
    sort(all(ps), greater<pii>());

    vi vis(n, -1);
    for (auto &[s, p] : ps) {
        if (hs[p] < vis[p]) continue;
        dfsfoda(p, hs[p], g, vis, hs);
    }

    vi ans;
    for (int i = 0; i < n; i++)
        if (vis[i] >= 0) ans.pb(i + 1);

    cout << ans.size() << endl;
    for (auto &ai : ans) cout << ai << ' ';
    cout << endl;
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    // cin >> t;
    while (t--) run();
}

// AC, graphs, bfs/dfs
