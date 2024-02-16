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

tuple<ll, ll, ll> ext_gcd(ll a, ll b) {
  if (!a) return {b, 0, 1};
  auto [g, x, y] = ext_gcd(b % a, a);
  return {g, y - b / a * x, x};
}

template <typename T = ll>
struct crt {
  T a, m;

  crt() : a(0), m(1) {}
  crt(T a_, T m_) : a(a_), m(m_) {}
  crt operator*(crt C) {
    auto [g, x, y] = ext_gcd(m, C.m);
    if ((a - C.a) % g != 0) a = -1;
    if (a == -1 or C.a == -1) return crt(-1, 0);
    T lcm = m / g * C.m;
    T ans = a + (x * (C.a - a) / g % (C.m / g)) * m;
    return crt((ans % lcm + lcm) % lcm, lcm);
  }
};

template <typename T = ll>
struct Congruence {
  T a, m;
};

template <typename T = ll>
T chinese_remainder_theorem(
  const vector<Congruence<T>>& equations) {
  crt<T> ans;

  for (auto& [a_, m_] : equations) {
    ans = ans * crt<T>(a_, m_);
  }

  return ans.a;
}

#define int long long
template <ll m1, ll m2>
vll merge_two_mods(const vector<mint<m1>>& a,
                   const vector<mint<m2>>& b) {
  int n = len(a);
  vll ans(n);
  for (int i = 0; i < n; i++) {
    auto cur = crt<ll>();
    auto ai = a[i].v;
    auto bi = b[i].v;
    cur = cur * crt<ll>(ai, m1);
    cur = cur * crt<ll>(bi, m2);
    ans[i] = cur.a;
  }

  return ans;
}

vll convolution_2mods(const vll& a, const vll& b) {
  vector<mint<MOD1>> l(all(a)), r(all(b));
  int N = len(l) + len(r) - 1, n = 1;
  while (n <= N) n *= 2;
  l.resize(n), r.resize(n);
  ntt(l, false), ntt(r, false);
  for (int i = 0; i < n; i++) l[i] *= r[i];
  ntt(l, true);
  l.resize(N);

  vector<mint<MOD2>> l2(all(a)), r2(all(b));
  l2.resize(n), r2.resize(n);
  ntt(l2, false), ntt(r2, false);
  rep(i, 0, n) l2[i] *= r2[i];
  ntt(l2, true);
  l2.resize(N);

  return merge_two_mods(l, l2);
}

vll poly_exp(const vll& xs, ll k) {
  vll ret(len(xs));
  ret[0] = 1;
  auto base = xs;
  while (k) {
    if (k & 1) ret = convolution_2mods(ret, base);
    k >>= 1;
    base = convolution_2mods(base, base);
  }

  return ret;
}
