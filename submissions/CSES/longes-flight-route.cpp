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

void run() {
        ll n, m;
        cin >> n >> m;
        vector<vll> adj(n);
        for (int i = 0; i < m; ++i) {
                ll u, v;
                cin >> u >> v, u--, v--;
                adj[u].pb(v);
        }

        vll dists(n, -1);
        vll parent(n);
        iota(all(parent), 0);
        dists[0] = 0;
        queue<pll> q;
        q.emplace(0ll, 0ll);
        while (!q.empty()) {
                auto [city, dist] = q.front();
                q.pop();
                if (dist < dists[city]) continue;
                for (auto &neighboor : adj[city]) {
                        if (dists[neighboor] < dist + 1) {
                                q.emplace(neighboor, dist + 1);
                                parent[neighboor] = city;
                                dists[neighboor] = dist + 1;
                        }
                }
        }
        if (dists[n - 1] == -1)
                cout << "IMPOSSIBLE\n";
        else {
                ll cur = n - 1;
                vll path;
                while (cur != 0) {
                        path.eb(cur + 1);
                        cur = parent[cur];
                }
                path.eb(1);
                cout << path.size() << endl;
                for (int i = path.size() - 1; i >= 0; i--) {
                        cout << path[i] << ' ';
                }
                cout << endl;
        }
}
int32_t main(void) {
        fastio;
        int t;
        t = 1;
        while (t--) run();
}

// TLE in two cases
