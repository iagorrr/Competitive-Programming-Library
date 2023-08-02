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
const ll INF = 1e18;

struct strPsum {
        ll n;
        ll k;
        vector<vll> psum;
        strPsum(const string &s) : n(s.size()), k(100), psum(k, vll(n + 1)) {
                for (ll i = 1; i <= n; ++i) {
                        for (ll j = 0; j < k; ++j) {
                                psum[j][i] = psum[j][i - 1];
                        }
                        psum[s[i - 1]][i]++;
                }
        }

        ll qtd(ll l, ll r, char c) {  // [0,n-1]
                return psum[c][r + 1] - psum[c][l];
        }
};
void run() {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        strPsum psum(s);
        ll ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
                ll l = i;
                ll r = n - 1;
                while (l <= r) {  // lower bound
                        ll mid = (r - l) / 2 + l;
                        ll totblack = psum.qtd(i, mid, 'B');
                        ll totwhite = psum.qtd(i, mid, 'W');
                        if (totblack + totwhite >= k) {
                                r = mid - 1;
                                ans = min(ans, totwhite);
                        } else {
                                l = mid + 1;
                        }
                }
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

// AC, prefix sum, data structures
