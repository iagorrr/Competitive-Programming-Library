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
const ll mn = 30;
ll dp[mn + 1][mn + 1][mn + 1];
ll fsg(ll x, ll y, ll z) {  // precompute
        if (dp[x][y][z] != -1) return dp[x][y][z];
        if (x < 1 or y < 1 or z < 1) return 0;

        vc seen(mn * mn * mn + 1);
        for (int i = 0; i <= x / 2; i++)
                for (int j = 0; j <= y / 2; j++)
                        for (int k = 0; k <= z / 2; k++) {
                                ll sg = 
                                        fsg(i, j, k) ^
                                        fsg(i, j, z-k-1) ^
                                        fsg(i, y-j-1, k) ^
                                        fsg(i, y-j-1, z-k-1) ^
                                        fsg(x-i-1, j, k) ^
                                        fsg(x-i-1, j, z-k-1) ^
                                        fsg(x-i-1, y-j-1, k) ^
                                        fsg(x-i-1, y-j-1, z-k-1);
                                seen[sg] = true;
                        }

        ll mex = 0;
        while (seen[mex]) mex++;
        return dp[x][y][z] = mex;
}
void run() {
        for (int i = 0; i <= mn; i++)
                for (int j = 0; j <= mn; j++)
                        for (int k = 0; k <= mn; k++) dp[i][j][k] = -1;
        vector<string> names({"RUBEN", "ALBERT"});
        string s;
        cin >> s;
        if (names[0] != s) reverse(all(names));

        ll n;
        cin >> n;
        vll p;
        ll fxor = 0;
        for (int i = 0; i < n; ++i) {
                ll x, y, z;
                cin >> x >> y >> z;
                ll sg = fsg(x, y, z);
                fxor ^= sg;
        }
        auto ans = fxor == 0;
        cout << names[ans] << endl;
}
int32_t main(void) {
        fastio;
        int t;
        t = 1;
        // cin >> t;
        while (t--) run();
}

// AC, game theory, Groundy
