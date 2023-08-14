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

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) {
    cerr << ' ' << h;
    dbg_out(t...);
}
#define dbg(...)                     \
    {                                \
        cerr << #__VA_ARGS__ << ':'; \
        dbg_out(__VA_ARGS__);        \
    }
const ll INF = 1e18;

ll cost(const vll &p) {
    ll ans = 0;
    ll n = p.size();
    ll k = -1;
    for (int i = 0; i < n; ++i) {
        ans += p[i] * (i + 1);
        k = max(k, p[i] * (i + 1));
    }
    ans -= k;
    return ans;
}
void run() {
    ll n;
    cin >> n;
    ll ans = -1;
    vll p(n);
    iota(all(p), 1);
    for (int i = 0; i < n; ++i) {
        vll p2 = p;
        reverse(p2.begin() + i, p2.end());
        ans = max(ans, cost(p2));
    }
    cout << ans << '\n';
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    cin >> t;
    while (t--) run();
}

// AC, brute force
