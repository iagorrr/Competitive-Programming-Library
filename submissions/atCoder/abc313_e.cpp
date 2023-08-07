// iagorrr ;)
#include <bits/stdc++.h>
#include <atcoder/modint>
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
const ll INF = 1e18;
const ll mod = 998244353;

using mint = atcoder::modint998244353;
void run() {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        for (int i = 0; i < n - 1; ++i) {
                if (s[i] != '1' and s[i + 1] != '1') {
                        cout << -1 << endl;
                        return;
                }
        }

        reverse(all(s));
        mint totoperations = 0;
        s.back() = '1';
        for (int i = 0; i < n - 1; ++i) {
                while (i < n - 1 and s[i] == '1') {
                        totoperations++;
                        i++;
                }
                if (i == n - 1) {
                        continue;
                }
                mint k = s[i] - '0';
                mint essecaracolocou = (k - 1) * (totoperations + 1);
                totoperations++;
                totoperations += essecaracolocou;
        }
        cout << totoperations.val() << '\n';
}
int32_t main(void) {
        fastio;
        int t;
        t = 1;
        // cin >> t;
        while (t--) run();
}
