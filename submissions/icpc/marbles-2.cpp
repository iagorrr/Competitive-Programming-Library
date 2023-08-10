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
const ll oo = 1e18;

vll2d sg(101, vll(101, -1));
ll cmax = 1e4;
ll maxcord = 100;
void precompute() {
        for (ll x = 0; x <= maxcord; ++x) {
                for (ll y = 0; y <= maxcord; ++y) {
                        if (x == y or x == 0 or y == 0) {
                                sg[x][y] = cmax;
                                continue;
                        }
                        if ((x - 1 == y or x - 1 == 0) and
                            (y - 1 == 0 or y - 1 == x)) {
                                sg[x][y] = 0;
                                continue;
                        }
                        vc seen(cmax + 1);
                        for (ll d = 1; d <= x; ++d) seen[sg[x - d][y]] = true;
                        for (ll d = 1; d <= y; ++d) seen[sg[x][y - d]] = true;
                        for (ll d = 1; d <= min(x, y); ++d)
                                seen[sg[x - d][y - d]] = true;
                        ll mex = 0;
                        while (seen[mex]) mex++;
                        sg[x][y] = mex;
                }
        }
}
void run() {
        ll n;
        cin >> n;
        ll thexor = 0;
        precompute();
        for (int i = 0; i < n; ++i) {
                ll x, y;
                cin >> x >> y;
                ll csg = sg[x][y];
                thexor ^= csg;
        }

        cout << (thexor != 0 ? "Y" : "N") << endl;
}
int32_t main(void) {
        fastio;
        int t;
        t = 1;
        // cin >> t;
        while (t--) run();
}

// AC, game theory
