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

void run() {
        ll n;
        cin >> n;
        if (n == 1) {
                cout << 1 << '\n';
                return;
        }
        if (n & 1) {
                cout << -1 << '\n';
                return;
        }

        ll x = 0;
        ll y = n - 1;
        vll b(n);
        for (int i = 0; i < n; ++i) {
                if (i & 1)
                        b[i] = y--;
                else
                        b[i] = x++;
        }
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
                ll desired = b[i];

                ll curans = 8;
                ll curmod = sum % n;
                //  tenho que dar a volta
                if (curmod > desired) {
                        ll volta = n - curmod;
                        curans = volta + desired;
                } else {  // aumenta um cadin
                        curans = desired - curmod;
                }

                sum += curans;
                if (i == 0) curans = n;
                cout << curans << ' ';
        }
        cout << '\n';
}
int32_t main(void) {
        // fastio;
        int t;
        t = 1;
        cin >> t;
        while (t--) run();
}
// AC, math, permutation
