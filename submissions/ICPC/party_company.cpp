// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
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

const ll oo = 1e9;
struct SegTree {
    int N;
    vector<ll> ns, lazy;

    SegTree(const vector<ll> &xs) : N(xs.size()), ns(4 * N, 0), lazy(4 * N, 0) {
        for (size_t i = 0; i < xs.size(); ++i) update(i, i, xs[i]);
    }

    SegTree(int n) : N(n), ns(4 * N, 0), lazy(4 * N, 0) {}

    void update(int a, int b, ll value) { update(1, 0, N - 1, a, b, value); }

    void update(int node, int L, int R, int a, int b, ll value) {
        // Lazy propagation
        if (lazy[node]) {
            ns[node] += (R - L + 1) * lazy[node];

            if (L < R)  // Se o nó não é uma folha, propaga
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (a > R or b < L) return;

        if (a <= L and R <= b) {
            ns[node] += (R - L + 1) * value;

            if (L < R) {
                lazy[2 * node] += value;
                lazy[2 * node + 1] += value;
            }

            return;
        }

        update(2 * node, L, (L + R) / 2, a, b, value);
        update(2 * node + 1, (L + R) / 2 + 1, R, a, b, value);

        ns[node] = ns[2 * node] + ns[2 * node + 1];
    }

    ll RSQ(int a, int b) { return RSQ(1, 0, N - 1, a, b); }

    ll RSQ(int node, int L, int R, int a, int b) {
        if (lazy[node]) {
            ns[node] += (R - L + 1) * lazy[node];

            if (L < R) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (a > R or b < L) return 0;

        if (a <= L and R <= b) return ns[node];

        ll x = RSQ(2 * node, L, (L + R) / 2, a, b);
        ll y = RSQ(2 * node + 1, (L + R) / 2 + 1, R, a, b);

        return x + y;
    }
};
const int maxn = 1e5;
vi ans(maxn + 1);
vc vis(maxn + 1);
SegTree seg(maxn + 1);
void dfs(int u, const vi2d &g, const vi &ages, const vector<vii> &party) {
    vis[u] = true;
    // now everyone in the that age will be in the party
    for (auto &[l, r] : party[u]) seg.update(l, r, 1);

    // answer the query by the total party that u can be
    ans[u] += seg.RSQ(ages[u], ages[u]);

    // spread the party !
    for (auto &v : g[u])
        if (!vis[v]) {
            dfs(v, g, ages, party);
        }

    // remove this party so don't affect the others
    for (auto &[l, r] : party[u]) seg.update(l, r, -1);
}
void run() {
    int n, m;
    cin >> n >> m;

    vi ages(n + 1);
    ages[0] = oo;
    vi2d g(n + 1);
    const int maxlog = 20;
    vi2d far(maxlog + 1, vi(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> ages[i];
        int manager;
        cin >> manager;
        g[manager].pb(i);

        far[0][i] = manager;
    }

    // precompute far
    for (int h = 1; h <= maxlog; h++) {
        for (int i = 1; i <= n; i++) {
            far[h][i] = far[h - 1][far[h - 1][i]];
        }
    }

    // atribuite each query to the oldest invited possible
    vector<vector<pii>> queries(n + 1);
    for (int i = 0; i < m; i++) {
        int o, l, r;
        cin >> o >> l >> r;

        for (int h = maxlog; h >= 0; h--) {
            if (ages[far[h][o]] <= r) {
                o = far[h][o];
            }
        }
        queries[o].emplace_back(l, r);
    }

    // process the queries
    dfs(1, g, ages, queries);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    // cin >> t;
    while (t--) run();
}
