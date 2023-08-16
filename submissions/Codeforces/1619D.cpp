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

bool check(const vll2d &shops, ll n, ll m, ll v) {
    vc ff(n);
    ll at2 = 0;
    ll at1 = 0;
    for (int i = 0; i < m; ++i) {
        ll at = 0;
        for (int j = 0; j < n; j++) {
            if (shops[i][j] >= v) {
                at++;
                ff[j] = true;
            }
        }
        at2 += at >= 2;
        at1 += at;
    }

    ll cnt = 0;
    for_each(all(ff), [&cnt](const bool &c) { cnt += c; });
    // dbg(v, cnt, t1, at2, n);
    return cnt == n and at1 >= n - 1 and at2 >= 1;
}

void run() {
    ll n, m;
    cin >> m >> n;
    map<ll, vll> isprefered;
    vll prefered(n);
    vll thebest(n);
    vll thesecondbest(n);
    ll optimal = LLONG_MAX;
    vll2d shops(m, vll(n));
    for (int i = 0; i < m; ++i) {
        for (ll j = 0; j < n; j++) {
            cin >> shops[i][j];
        }
    }

    ll ans = 0;
    ll l = 0;
    ll r = 1e9 + 1;
    while (l <= r) {
        ll mid = (r - l) / 2 + l;

        if (check(shops, n, m, mid)) {
            // dbg(mid);
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    cin >> t;
    while (t--) run();
}

// AC, binary search
