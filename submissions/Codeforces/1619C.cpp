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

void run() {
    string a, b;
    cin >> a >> b;
    ll n = len(a) - 1, m = len(b) - 1;
    string g;
    for (;;) {
        if (a[n] > b[m]) {
            if (m == 0 or b[m - 1] != '1') {
                cout << -1 << endl;
                return;
            }
            ll ia = a[n] - '0';
            ll ib = b[m] - '0' + 10;
            ll d = ib - ia;
            g.pb(d + '0');
            n--;
            m -= 2;
        } else {
            ll ia = a[n] - '0';
            ll ib = b[m] - '0';
            ll d = ib - ia;
            g.pb(d + '0');
            m--;
            n--;
        }

        if ((m < 0 and n >= 0)) {
            cout << -1 << endl;
            return;
        }

        if (n < 0 and m >= 0) {
            while (m >= 0) {
                g.pb(b[m]);
                m--;
            }
        }

        if (m < 0 and n < 0) break;
    }
    while (not g.empty() and g.back() == '0') g.pop_back();
    reverse(all(g));
    cout << g << endl;
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    cin >> t;
    while (t--) run();
}

// AC, strings, implementation
