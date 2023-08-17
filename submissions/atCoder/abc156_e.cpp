// iagorrr ;)
#include <bits/stdc++.h>

#include <atcoder/modint.hpp>
#include <atcoder/modint>

using namespace std;
// #ifdef DEBUG
// #include "debug.cpp"
// #else
// #define dbg(...) 666
// #endif
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

const ll INF = 1e18;
using mint = atcoder::modint1000000007;

ll mod = 1e9 + 7;
ll fexp(ll a, int n) {
    if (n == 0) return 1ll;
    if (n == 1) return a % mod;
    ll x = fexp(a, n / 2ll) % mod;
    return (x * x * (n & 1ll ? a : 1ll)) % mod;
}

mint binom(ll n, ll k) {
    mint up = 1;
    mint down = 1;

    for(ll i = 0; i < k; ++i) {
        up *= (n-i);
        down *= (i+1);
    }
    return up/down;
}
void run() {
    ll n, a, b;
    cin >> n >> a >> b;
    mint ans = fexp(2, n);

    auto cs1 = binom(n, a);
    ans -= cs1;
    auto cs2 = binom(n, b);
    ans -= cs2;
    ans -= 1;

    cout << ans.val() << endl;
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    // cin >> t;
    while (t--) run();
}

// AC, math, combinatorics
