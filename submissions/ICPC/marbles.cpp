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

vll2d sgmemo(101, vll(101, -1));
ll cmax = 1e4;
ll sg(ll x, ll y) {
        if (x == 0 or y == 0 or x == y) return cmax;

        // must loose situation
        if ((x - 1 == 0 and x - 1 == y) and (y - 1 == 0 and y - 1 == x))
                return 0;

        if(sgmemo[x][y] != -1) return sgmemo[x][y];

        // can reacn siatuation bi in one move
        vc seen(cmax + 1);
        for (ll dx = 1; dx <= x; ++dx) seen[sg(x - dx, y)] = true;

        for (ll dy = 1; dy <= y; ++dy) seen[sg(x, y - dy)] = true;

        for (ll dxy = 1; dxy <= min(x, y); dxy++)
                seen[sg(x - dxy, y - dxy)] = true;

        ll mex = 0;
        while (seen[mex]) mex++;
        return sgmemo[x][y] = mex;
}
void run() {
        ll n;
        cin >> n;
        ll thexor = 0;

        for (int i = 0; i < n; ++i) {
                ll x, y;
                cin >> x >> y;
                ll csg = sg(x, y);
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
