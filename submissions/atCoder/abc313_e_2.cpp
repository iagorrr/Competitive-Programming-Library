// iagorrr ;)
#include <bits/stdc++.h>
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
        for (auto& xxx : xxxx) cin >> xxx;
#define PRINTV(___x)                                                  \
        for_each(all(___x), [](ll& ____x) { cout << ____x << ' '; }), \
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
template <ll MOD = mod>
struct Modular {
        int value;
        static const int MOD_value = MOD;

        Modular(ll v = 0) {
                value = v % MOD;
                if (value < 0) value += MOD;
        }
        Modular(ll a, ll b) : value(0) {
                *this += a;
                *this /= b;
        }

        Modular& operator+=(Modular const& b) {
                value += b.value;
                if (value >= MOD) value -= MOD;
                return *this;
        }
        Modular& operator-=(Modular const& b) {
                value -= b.value;
                if (value < 0) value += MOD;
                return *this;
        }
        Modular& operator*=(Modular const& b) {
                value = (ll)value * b.value % MOD;
                return *this;
        }

        friend Modular mexp(Modular a, ll e) {
                Modular res = 1;
                while (e) {
                        if (e & 1) res *= a;
                        a *= a;
                        e >>= 1;
                }
                return res;
        }
        friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

        Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
        friend Modular operator+(Modular a, Modular const b) { return a += b; }
        friend Modular operator-(Modular a, Modular const b) { return a -= b; }
        friend Modular operator-(Modular const a) { return 0 - a; }
        friend Modular operator*(Modular a, Modular const b) { return a *= b; }
        friend Modular operator/(Modular a, Modular const b) { return a /= b; }
        friend std::ostream& operator<<(std::ostream& os, Modular const& a) {
                return os << a.value;
        }
        friend bool operator==(Modular const& a, Modular const& b) {
                return a.value == b.value;
        }
        friend bool operator!=(Modular const& a, Modular const& b) {
                return a.value != b.value;
        }
};
using mint = Modular<>;
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
                        totoperations += 1;
                        i++;
                }
                if (i == n - 1) {
                        continue;
                }
                mint k = s[i] - '0';
                mint essecaracolocou = (k - 1) * (totoperations + 1);
                totoperations += 1;
                totoperations += essecaracolocou;
        }
        cout << totoperations << '\n';
}
int32_t main(void) {
        fastio;
        int t;
        t = 1;
        // cin >> t;
        while (t--) run();
}

// AC, strings, math, dp
