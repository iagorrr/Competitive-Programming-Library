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

void run() {
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        vll as(n);
        INV(as);

        ll sum = 0;
        for (auto &ai : as) sum += ai;

        vector<priority_queue<ll>> available(k);
        for (auto &ai : as) {
                available[ai % k].push(ai);
        }

        ll ans = 0;
        for (int i = 0; i < k; ++i) {
                for (int j = 0; j < k; ++j) {
                        if (i == j) continue;
                        if (available[i].empty()) break;
                        if (available[j].empty()) continue;
                        if (i + j < k) continue;

                        ll tot = min(available[i].size(), available[j].size());
                        while (tot > 0) {
                                tot--;
                                auto v1 = available[i].top();
                                available[i].pop();
                                auto v2 = available[j].top();
                                available[j].pop();
                                ans += ((v1 + v2) / k);
                        }
                }
        }

        // pegar dois as dois dos que sobraram na moda caralha e dar na ans kkk
        vll modacaralha;
        for (int i = 0; i < k; ++i) {
                while (!available[i].empty()) {
                        modacaralha.pb(available[i].top());
                        available[i].pop();
                }
        }
        if (modacaralha.size()) {
                for (int i = 0; i < modacaralha.size() - 1; i += 2) {
                        ans += ((modacaralha[i] + modacaralha[i + 1]) / k);
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

// AC, data structures, math
