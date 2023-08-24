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

const ll mod = 998244353;
template <ll MOD = mod>
struct Modular {
    ll value;
    static const ll MOD_value = MOD;

    Modular(ll v = 0) {
        value = v % MOD;
        if (value < 0) value += MOD;
    }
    Modular(ll a, ll b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular &operator+=(Modular const &b) {
        value += b.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    Modular &operator-=(Modular const &b) {
        value -= b.value;
        if (value < 0) value += MOD;
        return *this;
    }
    Modular &operator*=(Modular const &b) {
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

    Modular &operator/=(Modular const &b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    Modular operator++(int) { return this->value = (this->value + 1) % MOD; }
    Modular operator++() { return this->value = (this->value + 1) % MOD; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    Modular operator--(int) {
        return this->value = (this->value - 1 + MOD) % MOD;
    }

    Modular operator--() { return this->value = (this->value - 1 + MOD) % MOD; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream &operator<<(std::ostream &os, Modular const &a) {
        return os << a.value;
    }
    friend bool operator==(Modular const &a, Modular const &b) {
        return a.value == b.value;
    }
    friend bool operator!=(Modular const &a, Modular const &b) {
        return a.value != b.value;
    }
};

array<int, 3> fatora(ll n) {
    array<int, 3> podenao;
    podenao[0] = 0;
    podenao[1] = 0;
    podenao[2] = 0;
    while (n % 2 == 0) {
        podenao[0]++;
        n /= 2;
    }

    while (n % 3 == 0) {
        podenao[1]++;
        n /= 3;
    }

    while (n % 5 == 0) {
        podenao[2]++;
        n /= 5;
    }
    if (n != 1) {
        cout << 0 << endl;
        exit(0);
    }
    // cout <<"podenao: " <<  podenao[0] << ' '<< podenao[1] << ' ' <<
    // podenao[2] << endl;
    return podenao;
}
using mint = Modular<mod>;
ll n;
mint one;
mint onequinto;
mint dp[60][60][60] = {-1};
mint solve(ll f2, ll f3, ll f5) {
    if (f2 == 0ll and f3 == 0 and f5 == 0) return one;

    if (dp[f2][f3][f5].value != -1) {
        return dp[f2][f3][f5];
    }

    mint a2 = 0ll;
    if (f2 > 0ll) a2 = solve(f2 - 1ll, f3, f5) * onequinto;
    mint a3 = 0ll;
    if (f3 > 0ll) a3 = solve(f2, f3 - 1ll, f5) * onequinto;
    mint a4 = 0ll;
    if (f2 > 1ll) a4 = solve(f2 - 2ll, f3, f5) * onequinto;
    mint a5 = 0ll;
    if (f5 > 0ll) a5 = solve(f2, f3, f5 - 1ll) * onequinto;
    mint a6 = 0ll;
    if (f2 > 0ll and f3 > 0) a6 = solve(f2 - 1ll, f3 - 1, f5) * onequinto;

    mint ans = a2 + a3 + a4 + a5 + a6;
    // cout << ans << endl;
    return dp[f2][f3][f5] = ans;
}
void run() {
    cin >> n;
    auto ft = fatora(n);
    // cout << ft[0] << ' ' << ft[1] << ' ' << ft[2];
    cout << solve(ft[0], ft[1], ft[2]) << endl;
}
int32_t main(void) {
    fastio;
    memset(dp, -1, sizeof(dp));
    one = 1;
    onequinto = 1;
    onequinto /= 5;
    int t;
    t = 1;
    while (t--) run();
}

// AC, expected value
