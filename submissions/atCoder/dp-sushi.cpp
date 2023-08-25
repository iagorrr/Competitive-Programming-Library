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
using ld = long double;
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

ld memo[300 + 1][300 + 1][300 + 1];
bool vis[300 + 1][300 + 1][300 + 1];
int n;
ld solve(int q1, int q2, int q3) {
    if (q1 < 0 or q2 < 0 or q3 < 0) return 0;
    if (q1 == 0 and q2 == 0 and q3 == 0) return 0;
    if (vis[q1][q2][q3]) return memo[q1][q2][q3];
    auto t1 = solve(q1 - 1, q2, q3) * (ld)q1;
    auto t2 = solve(q1 + 1, q2 - 1, q3) * (ld)q2;
    auto t3 = solve(q1, q2 + 1, q3 - 1) * (ld)q3;
    vis[q1][q2][q3] = true;
    return memo[q1][q2][q3] = (t1 + t2 + t3 + (ld)n) / (n - (n - q1 - q2 - q3));
}

void run() {
    cin >> n;
    vi qtd(4);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        qtd[ai]++;
    }
    cout << fixed << setprecision(10);
    cout << solve(qtd[1], qtd[2], qtd[3]) << endl;
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    // cin >> t;
    while (t--) run();
}

// AC, expected value, dynamic programming
