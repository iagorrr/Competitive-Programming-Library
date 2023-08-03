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
#define len(__x) ((ll)__x.size())

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

/*
 * receives a permutation [0, n-1]
 * */
vector<vll> getPermutationCicles(const vll &ps) {
        ll n = len(ps);
        vector<char> visited(n);
        vector<vll> cicles;
        for (int i = 0; i < n; ++i) {
                if (visited[i]) continue;

                vll cicle;
                ll pos = i;
                while (!visited[pos]) {
                        cicle.pb(pos);
                        visited[pos] = true;
                        pos = ps[pos];
                }

                cicles.push_back(vll(all(cicle)));
        }
        return cicles;
}

void run() {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vll ps(n);
        for_each(all(ps), [](ll &x) { cin >> x, x--; });

        ll ans = 1;
        auto cicles = getPermutationCicles(ps);
        for (const auto &cicle : cicles) {
                string scicle;
                for (auto &i : cicle) {
                        scicle += s[i];
                }
                ll m = len(scicle);
                for (int i = 0; i < m; ++i) {
                        string cur = scicle.substr(0, i + 1);
                        string tmp = "";
                        while (len(tmp) < m) tmp += cur;
                        if (tmp == scicle) {
                                ans = lcm(ans, i+1);
                                break;
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

// AC,permutation, strings, graph
