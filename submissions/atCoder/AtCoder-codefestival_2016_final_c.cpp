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

int ans;
void dfsfoda(int u, vll2d &g, vc &vis, int n, int m) {
    if (u < n) ans++;
    vis[u] = true;
    for (auto &v : g[u]) {
        if (vis[v]) continue;
        dfsfoda(v, g, vis, n, m);
    }
}
void run() {
    ll n, m;
    cin >> n >> m;

    // 0 -> n-1 é pessoa
    // n -> n+m-1 é lingua
    vll2d g(n + m);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int l;
            cin >> l, l--;
            g[i].pb(l + n);
            g[l + n].pb(i);
        }
    }

    vc vis(n + m);
    dfsfoda(0, g, vis, n, m);
    if (ans < n) {
        cout << "NO\n";
    } else
        cout << "YES\n";
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    while (t--) run();
}

// AC, graph, bfs/dfs
