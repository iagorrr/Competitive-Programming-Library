// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                            \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);
#define rep(__i, __x, __y) \
        for (ll i = (__x); i != (__y); i += 1 * ((__x) < (__y) ? 1 : -1))
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx) \
        for (auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

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
void run() {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;
        ll qtd0 = 0;
        ll qtd1 = 0;
        for(auto &c : s) {
                bool isone = c == '1';
                if(isone) {
                        swap(qtd0, qtd1);
                        qtd1++;
                }
                else {
                        qtd1 += qtd0;
                        qtd0 = 1;
                }
                ans += qtd1;
        }
        cout << ans << '\n';
}
int32_t main(void) {
        fastio;
        int t;
        t = 1;
        // cin >> t;
        while (t--) run();
}

// AC, strings, bitwise operations
