// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
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

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) {
    cerr << ' ' << h;
    dbg_out(t...);
}
#define dbg(...)                     \
    {                                \
        cerr << #__VA_ARGS__ << ':'; \
        dbg_out(__VA_ARGS__);        \
    }
const ll INF = 1e18;

struct node {
    ll ai, bi, li, ri;
    bool operator<(node &b) { return ai != b.ai ? ai < b.ai : bi < b.bi; }
};

vector<node> unisaporra(const vector<node> &portals) {
    vector<node> ans;
    ans.pb(portals[0]);
    ll n = portals.size();
    for (int i = 1; i < n; ++i) {
        if (portals[i].li <= ans.back().bi) {
            ans.back().bi = max(ans.back().bi, portals[i].bi);
            ans.back().li = min(ans.back().li, portals[i].li);
            ans.back().ri = max(ans.back().ri, portals[i].ri);
            ans.back().ai = min(ans.back().ai, portals[i].ai);
        } else {
            ans.push_back(portals[i]);
        }
    }

    return ans;
}
void run() {
    ll n;
    cin >> n;
    //  li, ri, ai, bi,
    vector<node> portals(n);
    for (int i = 0; i < n; ++i) {
        cin >> portals[i].li >> portals[i].ri >> portals[i].ai >> portals[i].bi;
    }
    sort(all(portals), [](node &a, node &b) {
        return a.li != b.li ? a.li < b.li : a.bi < b.bi;
    });
    portals = unisaporra(portals);

    ll q;
    cin >> q;

    vll starts(q);
    for (int i = 0; i < q; ++i) cin >> starts[i];

    for (const auto &qi : starts) {
        ll ans = qi;
        ll l = 0, r = len(portals) - 1;
        while (l <= r) {
            ll mid = (r - l) / 2 + l;
            if (portals[mid].li <= qi and qi <= portals[mid].ri) {
                ans = max(ans, portals[mid].bi);
            }
            if (qi < portals[mid].li) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    cin >> t;
    while (t--) run();
}

// AC, binary search, greedy
