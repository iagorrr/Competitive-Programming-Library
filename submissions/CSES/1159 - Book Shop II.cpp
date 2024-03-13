#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
// #define int long long
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define rep(i, begin, end)                                                                \
    for (__typeof(begin) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); \
         i += 1 - 2 * ((begin) > (end)))

int lg2(ll x) { return __builtin_clzll(1) - __builtin_clzll(x); }

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll OO = 1e18;
const int oo = 1e9;

int T(1);
ll knapsack(const vi &weight, const vll &value, const vi &qtd, int maxCost) {
    vi costs;
    vll values;
    for (int i = 0; i < len(weight); i++) {
        ll q = qtd[i];
        for (ll x = 1; x <= q; q -= x, x <<= 1) {
            costs.eb(x * weight[i]);
            values.eb(x * value[i]);
        }
        if (q) {
            costs.eb(q * weight[i]);
            values.eb(q * value[i]);
        }
    }

    vll dp(maxCost + 1);
    for (int i = 0; i < len(values); i++) {
        for (int j = maxCost; j > 0; j--) {
            if (j >= costs[i]) dp[j] = max(dp[j], values[i] + dp[j - costs[i]]);
        }
    }
    return dp[maxCost];
}

int n, x;
auto run() {
    cin >> n >> x;
    vi price(n);
    for (auto &xi : price) cin >> xi;
    vll value(n);
    for (auto &xi : value) cin >> xi;
    vi qtd(n);
    for (auto &xi : qtd) cin >> xi;

    cout << knapsack(price, value, qtd, x) << '\n';
}

int32_t main(void) {
#ifndef LOCAL
    fastio;
#endif

    // cin >> T;

    for (int t = 1; t <= T; t++) {
        run();
    }
}

// AC, knapsack with quantity
