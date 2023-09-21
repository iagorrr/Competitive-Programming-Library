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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s += "#";

    ll ck = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[i + 1] and s[i] == 'a') {
            ck++;
        } else {
            if(ck == 0) continue;
            ans += ck + 1;
            ck = 0;
        }

        // dbg(ck, ans);
    }
    cout << ans << endl;
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    // cin >> t;
    while (t--) run();
}

// AC, strings
