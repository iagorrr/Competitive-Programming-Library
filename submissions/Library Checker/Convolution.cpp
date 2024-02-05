#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define int long long
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
#define rep(i, begin, end)                              \
  for (__typeof(begin) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end));                  \
       i += 1 - 2 * ((begin) > (end)))

int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);
const int MAXN(1'000'000);

/*======================================================================================================*/
/*====================== MINT ====================== */
template <int _mod>
struct mint {
  ll expo(ll b, ll e) {
    ll ret = 1;
    while (e) {
      if (e % 2) ret = ret * b % _mod;
      e /= 2, b = b * b % _mod;
    }
    return ret;
  }
  ll inv(ll b) { return expo(b, _mod - 2); }

  using m = mint;
  ll v;
  mint() : v(0) {}
  mint(ll v_) {
    if (v_ >= _mod or v_ <= -_mod) v_ %= _mod;
    if (v_ < 0) v_ += _mod;
    v = v_;
  }
  m& operator+=(const m& a) {
    v += a.v;
    if (v >= _mod) v -= _mod;
    return *this;
  }
  m& operator-=(const m& a) {
    v -= a.v;
    if (v < 0) v += _mod;
    return *this;
  }
  m& operator*=(const m& a) {
    v = v * ll(a.v) % _mod;
    return *this;
  }
  m& operator/=(const m& a) {
    v = v * inv(a.v) % _mod;
    return *this;
  }
  m operator-() { return m(-v); }
  m& operator^=(ll e) {
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
  bool operator==(const m& a) { return v == a.v; }
  bool operator!=(const m& a) { return v != a.v; }

  friend istream& operator>>(istream& in, m& a) {
    ll val;
    in >> val;
    a = m(val);
    return in;
  }
  friend ostream& operator<<(ostream& out, m a) {
    return out << a.v;
  }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend m operator^(m a, ll e) { return a ^= e; }
};
/*==================== END MINT ====================== */

/*================== ntt int convolution ==============*/
const ll MOD1 = 998244353;
const ll MOD2 = 754974721;
const ll MOD3 = 167772161;

template <int _mod>
void ntt(vector<mint<_mod>>& a, bool rev) {
  int n = len(a);
  auto b = a;
  assert(!(n & (n - 1)));
  mint<_mod> g = 1;
  while ((g ^ (_mod / 2)) == 1) g += 1;
  if (rev) g = 1 / g;

  for (int step = n / 2; step; step /= 2) {
    mint<_mod> w = g ^ (_mod / (n / step)), wn = 1;
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
    auto n1 = mint<_mod>(1) / n;
    for (auto& x : a) x *= n1;
  }
}

// template <ll _mod>
// vector<mint<_mod>> convolution(
//   const vector<mint<_mod>>& a,
//   const vector<mint<_mod>>& b) {
//   vector<mint<_mod>> l(all(a)), r(all(b));
//   int N = len(l) + len(r) - 1, n = 1;
//   while (n <= N) n *= 2;
//   l.resize(n), r.resize(n);
//   ntt(l, false), ntt(r, false);
//   for (int i = 0; i < n; i++) l[i] *= r[i];
//   ntt(l, true);
//   l.resize(N);

//   // Uncommnent for a boolean convolution :)
//   /*

//   for (auto& li : l) {
//     li.v = min(li.v, 1ll);
//   }
//   */

//   return l;
// }

template <ll _mod>
vector<mint<_mod>> convolution(const vll& a, const vll& b) {
  vector<mint<_mod>> am(all(a)), bm(all(b));
  vector<mint<_mod>> l(all(am)), r(all(bm));
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

  return l;
}

template <ll _mod>
vector<mint<_mod>> poly_exp(vector<mint<_mod>>& ps, int k) {
  vector<mint<_mod>> ret(len(ps));
  auto base = ps;
  ret[0] = 1;

  while (k) {
    if (k & 1) ret = convolution(ret, base);
    k >>= 1;
    base = convolution(base, base);
  }

  return ret;
}
auto run() {
  int n, m;
  cin >> n >> m;

  vll as(n), bs(m);
  for (auto& ai : as) cin >> ai;
  for (auto& bi : bs) cin >> bi;

  auto ans = convolution<MOD1>(as, bs);

  for (int i = 0; i <= n + m - 1 - 1; i++) {
    cout << ans[i] << " \n"[i == n + m - 1 - 1];
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}
