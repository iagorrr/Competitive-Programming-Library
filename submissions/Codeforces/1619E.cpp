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
    vll xs(n);
    vll ans(n + 1, -1);
    vll cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
        cnt[xs[i]]++;
    }

    sort(all(xs));
    stack<ll> st;

    ans[0] = cnt[0];
    vll need(n + 1, -1);
    need[0] = cnt[0] ? 0 : -1;
    ll j = 0;
    while (j < n and xs[j] == 0) {
        st.push(0);
        j++;
    }
    if (!st.empty()) st.pop();
    for (int i = 1; i <= n; ++i) {
        if (ans[i - 1] == -1 or need[i - 1] == -1) {
            ans[i] = -1;
            continue;
        }
        ll cur = need[i - 1] + cnt[i];    // need to have until i-1

        while (j < n and xs[j] <= i) {
            st.push(xs[j]);
            j++;
        }
        if (st.empty()) {
            need[i] = -1;
        } else {
            ll k = st.top();
            st.pop();
            need[i] = i - k + need[i - 1];
        }
        ans[i] = cur;
    }

    for (auto &ansi : ans) {
        cout << ansi << ' ';
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

// AC, greedy
