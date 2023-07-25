// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                            \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
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

ll calc(ll n, ll k) {
        // dbg(k, n);
        ll m = n - k+1;
        return (m * (m + 1)) / 2;
}
void run() {
        ll n, k, q;
        cin >> n >> k >> q;
        vll as(n);
        for (int i = 0; i < n; i++) cin >> as[i];

        ll l = 0;
        ll r = 0;
        ll ans = 0;
        while (l < n and r < n) {
                if (as[r] > q) {  // too hot
                        // long enought
                        if (r - l >= k) {
                                // dbg(q, r, l);
                                ans += calc(r - l, k);
                        }
                        r++;
                        l = r;

                } else if (r == n - 1) {
                        if(r-l+1 >= k)
                                ans += calc(r - l + 1, k);
                        r++;
                } else
                        r++;
        }
        // dbg(ans);
        cout << ans << '\n';
}
int32_t main(void) {
        fastio;
        int t;
        t = 1;
        cin >> t;
        while (t--) run();
}
// AC, two pointers
