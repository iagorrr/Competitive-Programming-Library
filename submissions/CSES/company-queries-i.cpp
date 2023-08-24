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

const ll INF = 1e18;
/*
 * far[h][i] = the node that are 2^h upper from i
 */
const int maxlog = 20;
const int maxn = 2 * 1e5;
void run() {
    int n, m;
    cin >> n >> m;
    // one indexed, so zero is a invalid part
    vi2d far(20 + 1, vi(maxn + 1));
    for (int i = 2; i <= n; i++) {
        cin >> far[0][i];
    }

    for (int h = 1; h <= maxlog; h++) {
        for (int i = 1; i <= n; i++) {
            far[h][i] = far[h - 1][far[h - 1][i]];
        }
    }
    for (int i = 0; i < m; i++) {
        int x, k;
        cin >> x >> k;
        for (int hi = maxlog; hi >= 0; hi--) {
            if ((1 << hi) <= k) {
                x = far[hi][x];
                k -= (1 << hi);
            }
        }
        cout << (x == 0 ? -1 : x) << endl;
    }
}
int32_t main(void) {
    // fastio;
    int t;
    t = 1;
    // cin >> t;
    while (t--) run();
}

// AC, binary lifting
