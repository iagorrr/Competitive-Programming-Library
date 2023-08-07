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
using vc = vector<char>;
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
#define rsz(___x, ___n) resize(___x, ___n)

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

struct SAT2 {
        ll n;
        vll2d adj, adj_t;
        vc used;
        vll order, comp;
        vc assignment;
        bool solvable;
        SAT2(ll _n)
                : n(2 * _n),
                  adj(n),
                  adj_t(n),
                  used(n),
                  order(n),
                  comp(n, -1),
                  assignment(n / 2) {}
        void dfs1(int v) {
                used[v] = true;
                for (int u : adj[v]) {
                        if (!used[u]) dfs1(u);
                }
                order.push_back(v);
        }

        void dfs2(int v, int cl) {
                comp[v] = cl;
                for (int u : adj_t[v]) {
                        if (comp[u] == -1) dfs2(u, cl);
                }
        }

        bool solve_2SAT() {
                // find and label each SCC
                for (int i = 0; i < n; ++i) {
                        if (!used[i]) dfs1(i);
                }
                reverse(all(order));
                ll j = 0;
                for (auto &v : order) {
                        if (comp[v] == -1) dfs2(v, j++);
                }

                assignment.assign(n / 2, false);
                for (int i = 0; i < n; i += 2) {
                        // x and !x belong to the same SCC
                        if (comp[i] == comp[i + 1]) {
                                solvable = false;
                                return false;
                        }

                        assignment[i / 2] = comp[i] > comp[i + 1];
                }
                solvable = true;
                return true;
        }

        void add_disjunction(int a, bool na, int b, bool nb) {
                // na and nb signify whether a and b are to be negated
                /* in the graph the vertices with indices  2k  and  2k+1  are
                 the two vertices corresponding to variable  k  with  2k+1 
                 corresponding to the negated variable.
                */
                a = (2 * a) ^ na;
                b = (2 * b) ^ nb;
                int neg_a = a ^ 1;
                int neg_b = b ^ 1;
                adj[neg_a].push_back(b);
                adj[neg_b].push_back(a);
                adj_t[b].push_back(neg_a);
                adj_t[a].push_back(neg_b);
        }
};

void run() {
        ll n, m;
        cin >> n >> m;
        SAT2 sat(m);
        for (int i = 0; i < n; ++i) {
                ll a, b;
                char na, nb;
                cin >> na >> a >> nb >> b;
                a--, b--;
                sat.add_disjunction(a, na == '-', b, nb == '-');
        }

        if (not sat.solve_2SAT()) {
                cout << "IMPOSSIBLE\n";
                return;
        }

        for (int i = 0; i < m; ++i) {
                cout << (sat.assignment[i] ? '+' : '-') << ' ';
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

// AC, graphs, 2SAT, SCC
