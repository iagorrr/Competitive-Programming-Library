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

ll run() {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        if (n & 1) return -1;
        ll ans = 0;
        map<char, ll> tochange;
        map<char, ll> hist;
        for (int i = 0, j = n - 1; i <= j; ++i, --j) {
                if (s[i] == s[j]) {
                        tochange[s[i]]++;
                }
                hist[s[i]]++;
                hist[s[j]]++;
                if (hist[s[i]] > n / 2) return -1;
                if (hist[s[j]] > n / 2) return -1;
        }
        ll maxzao = 0;
        ll sum = 0;
        for (auto [v, q] : tochange) {
                sum += q;
                maxzao = max(q, maxzao);
        }

        ans = max(maxzao, (sum+1)/2);

        return ans;
}
int32_t main(void) {
        fastio;
        int t;
        t = 1;
        cin >> t;
        while (t--) {
                cout << run() << '\n';
        }
}

// AC, strings, palindrome, greedy
