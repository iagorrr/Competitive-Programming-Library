/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop while (1)
using ll = long long;
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define ef emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b) - 1ll) / (b)
using str = string;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vc = vector<char>;
using vs = vector<str>;

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
TT using pqmn = priority_queue<T, vector<T>, greater<T>>;
TT using pqmx = priority_queue<T, vector<T>>;

TTU inline bool chmax(T &a, U const &b) { return (a < b ? a = b, 1 : 0); }
TTU inline bool chmin(T &a, U const &b) { return (a > b ? a = b, 1 : 0); }

// read vector
// TODO: abstract this to any container.
TT std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
    for (auto &element : vec) {
        is >> element;
    }
    return is;
}

// print vector
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, vector<T> &xs) {
    rep(i, os.iword(0), xs.size()) os << xs[i] << (i == xs.size() ? "" : " ");
    os.iword(0) = 0;
    return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
TT T sumList(vector<T> &xs) { return accumulate(all(xs), T()); }

/*
 * verify if a `predicate` is valid for
 * values in range [l, r]
 *
 * TODO: put a type in predicate ??
 * */
// bool all_of_in_range(T l, T r, auto predicate) {
//     return ranges::all_of(views::iota(l, r + 1),
//                           [&](T v) { return predicate(v); });
// }

// checks if a  value v is the interval [l, r]
TT bool inline between(T v, T l, T r) { return clamp(v, l, r) == v; }

/*8<============~ END TEMPLATE ~============}>8*/
void __init();
void __run();
void __pre_run();

int32_t main() {
#ifndef LOCAL
    fastio;
#endif
    __init();

    int T = 1;

    rep(t, 0, T) {
        dbg(t);
        __pre_run();
        __run();
    }
}

/*
 *
 *
 *
 *
 *
 * */

void __init() {}

void __pre_run() {}
/*8<
  @Title:
    NTT integer convolution and exponentiation
  @Time:
    \begin{compactitem}
      \item Convolution $O(N \cdot \log{N})$,
      \item Exponentiation: $O(\log{K} \cdot N
      \cdot \log{N})$
  \end{compactitem}
>8*/
template <int _mod>
struct ntt_mint {
    ll expo(ll b, ll e) {
        ll ret = 1;
        while (e) {
            if (e % 2) ret = ret * b % _mod;
            e /= 2, b = b * b % _mod;
        }
        return ret;
    }
    ll inv(ll b) { return expo(b, _mod - 2); }

    using m = ntt_mint;
    ll v;
    ntt_mint() : v(0) {}
    ntt_mint(ll v_) {
        if (v_ >= _mod or v_ <= -_mod) v_ %= _mod;
        if (v_ < 0) v_ += _mod;
        v = v_;
    }
    m &operator+=(const m &a) {
        v += a.v;
        if (v >= _mod) v -= _mod;
        return *this;
    }
    m &operator-=(const m &a) {
        v -= a.v;
        if (v < 0) v += _mod;
        return *this;
    }
    m &operator*=(const m &a) {
        v = v * ll(a.v) % _mod;
        return *this;
    }
    m &operator/=(const m &a) {
        v = v * inv(a.v) % _mod;
        return *this;
    }
    m operator-() { return m(-v); }
    m &operator^=(ll e) {
        if (e < 0) {
            v = inv(v);
            e = -e;
        }
        v = expo(v, e);
        // possivel otimizacao:
        // cuidado com 0^0
        // v = expo(v, e%(p-1));
        return *this;
    }
    bool operator==(const m &a) { return v == a.v; }
    bool operator!=(const m &a) { return v != a.v; }

    friend istream &operator>>(istream &in, m &a) {
        ll val;
        in >> val;
        a = m(val);
        return in;
    }
    friend ostream &operator<<(ostream &out, m a) { return out << a.v; }
    friend m operator+(m a, m b) { return a += b; }
    friend m operator-(m a, m b) { return a -= b; }
    friend m operator*(m a, m b) { return a *= b; }
    friend m operator/(m a, m b) { return a /= b; }
    friend m operator^(m a, ll e) { return a ^= e; }
};

const ll MOD1 = 998244353;
const ll MOD2 = 754974721;
const ll MOD3 = 167772161;

template <int _mod>
void ntt(vector<ntt_mint<_mod>> &a, bool rev) {
    int n = len(a);
    auto b = a;
    assert(!(n & (n - 1)));
    ntt_mint<_mod> g = 1;
    while ((g ^ (_mod / 2)) == 1) g += 1;
    if (rev) g = 1 / g;

    for (int step = n / 2; step; step /= 2) {
        ntt_mint<_mod> w = g ^ (_mod / (n / step)), wn = 1;
        for (int i = 0; i < n / 2; i += step) {
            for (int j = 0; j < step; j++) {
                auto u = a[2 * i + j], v = wn * a[2 * i + j + step];
                b[i + j] = u + v;
                b[i + n / 2 + j] = u - v;
            }
            wn = wn * w;
        }
        swap(a, b);
    }
    if (rev) {
        auto n1 = ntt_mint<_mod>(1) / n;
        for (auto &x : a) x *= n1;
    }
}

template <ll _mod>
vector<ntt_mint<_mod>> convolution(const vector<ntt_mint<_mod>> &a,
                                   const vector<ntt_mint<_mod>> &b) {
    vector<ntt_mint<_mod>> l(all(a)), r(all(b));
    int N = len(l) + len(r) - 1, n = 1;
    while (n <= N) n *= 2;
    l.resize(n), r.resize(n);
    ntt(l, false), ntt(r, false);
    for (int i = 0; i < n; i++) l[i] *= r[i];
    ntt(l, true);
    l.resize(N);

    // Uncommnent for a boolean convolution :)
    /*

    for (auto& li : l) {
      li.v = min(li.v, 1ll);
    }
    */

    while (len(l) and l.back() == 0) l.ppb();

    return l;
}

template <ll _mod>
vector<ntt_mint<_mod>> poly_exp(const vector<ntt_mint<_mod>> &ps, int k) {
    vector<ntt_mint<_mod>> ret(len(ps));
    auto base = ps;
    ret[0] = 1;

    while (k) {
        if (k & 1) ret = convolution<MOD1>(ret, base);
        k >>= 1;
        base = convolution<MOD1>(base, base);
    }

    return ret;
}

using mint = ntt_mint<MOD1>;
using vmint = vector<mint>;

void clear_poly(vmint &p) {
    return;
    while (len(p) and p.back() == 0) p.ppb();
}

vmint poly_sum(vmint as, vmint bs) {
    if (len(as) < len(bs)) swap(as, bs);
    rep(i, 0, len(bs)) as[i] += bs[i];
    return as;
}

void dbg_poly(const vmint &l) {
    rep(i, 0, len(l)) cerr << l[i] << ' ';
    cerr << '\n';
}

vmint merge(vmint l, vmint r, vmint qs) {
    r = convolution<MOD1>(r, poly_exp<MOD1>(qs, len(l)));
    auto ret = poly_sum(l, r);
    return ret;
}

vmint divide_and_conquer(int l, int r, const vmint &ps, const vmint &qs) {
    if (l == r) {
        return vmint(1, ps[l]);
    }

    int m = midpoint(l, r);
    auto valL = divide_and_conquer(l, m, ps, qs),
         valR = divide_and_conquer(m + 1, r, ps, qs);

    valR = convolution<MOD1>(valR, poly_exp<MOD1>(qs, (m - l + 1)));

    valR = poly_sum(valR, valL);

    return valR;
}

vmint polynomial_composition(const vmint &a, const vmint &b) {
    return divide_and_conquer(0, len(a) - 1, a, b);
}
void __run() {
    int n1;
    cin >> n1;

    vector<mint> ps(n1 + 1);
    cin >> ps;

    int n2;
    cin >> n2;

    vector<mint> qs(n2 + 1);
    cin >> qs;

    vector<mint> ans = polynomial_composition(ps, qs);

    cout << ans << endl;
}
