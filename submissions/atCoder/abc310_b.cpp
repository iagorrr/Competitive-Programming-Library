// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                            \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
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
struct prod {
        ll p, c;
        set<ll> fs;
};
void run() {
        ll n, m;
        cin >> n >> m;
        vector<tuple<ll, ll, set<ll>>> prods;
        for (int i = 0; i < n; ++i) {
                ll p, c;
                cin >> p >> c;
                set<ll> st;
                for (int j = 0; j < c; ++j) {
                        ll fi;
                        cin >> fi;
                        st.insert(fi);
                }
                prods.push_back({p, c, st});
        }

        sort(all(prods), greater<tuple<ll, ll, set<ll>>>());

        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        if (i == j) continue;
                        auto [pi, ci, ai] = prods[i];
                        auto [pj, cj, aj] = prods[j];
                        if(pi < pj) continue;
                        bool possible = true;
                        for (auto aii : ai) {
                                if (!aj.count(aii)) {
                                        possible = false;
                                        break;
                                }
                                aj.erase(aii);
                        }
                        if (!possible) continue;

                        if (aj.empty() and pi > pj) {
                                cout << "Yes\n";
                                return;
                        }
                        if (!aj.empty()) {
                                cout << "Yes\n";
                                return;
                        }
                }
        }
        cout << "No\n";
}
int32_t main(void) {
        fastio;
        int t;
        t = 1;
        // cin >> t;
        while (t--) run();
}

// AC, implementation
