#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 99824353;


template <uint_fast64_t Modulus> class modint {
  using u64 = uint_fast64_t;

public:
  using value_type = u64;

  static constexpr u64 mod = Modulus;

private:
  static_assert(mod < static_cast<u64>(1) << 32, "Modulus must be less than 2**32");
  u64 v;

  constexpr modint &negate() noexcept {
    if (v != 0) v = mod - v;
    return *this;
  }

public:
  constexpr modint(const ll x = 0) noexcept : v(x % (int)mod + mod) { if (v >= mod) v -= mod; }
  constexpr u64 &value() noexcept { return v; }
  constexpr const u64 &value() const noexcept { return v; }
  constexpr modint operator+() const noexcept { return modint(*this); }
  constexpr modint operator-() const noexcept { return modint(*this).negate(); }
  constexpr modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }
  constexpr modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }
  constexpr modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }
  constexpr modint operator/(const modint rhs) const noexcept { return modint(*this) /= rhs; }
  constexpr modint &operator+=(const modint rhs) noexcept {
    v += rhs.v;
    if (v >= mod) v -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (v < rhs.v) v += mod;
    v -= rhs.v;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    v = v * rhs.v % mod;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = mod - 2;
    while (exp != 0) {
      if (exp % 2 != 0) *this *= rhs;
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
  constexpr modint pow(u64 x) const {
    if (x == 0) return 1;
    auto ans = pow(x>>1);
    ans *= ans;
    if (x&1) ans *= v;
    return ans;
  }
  constexpr inline modint inv() const { return pow(mod - 2); }

  friend ostream& operator<<(ostream& s, const modint<mod>& x) {
    s << x.value();
    return s;
  }

  friend istream& operator>>(istream& s, modint<mod>& x) {
    s >> x.v;
    return s;
  }
};

template <uint_fast64_t Modulus>
constexpr typename modint<Modulus>::u64 modint<Modulus>::mod;
using mint = modint<998244353>;

auto run() {
        int N;
        cin >> N;

        vector<mint> XS(N);

        for (int i = 0; i < N; i++) {
                cin >> XS[i];
        }

        
        mint ans = 0;
        mint prevs = 0;
        for (int i = N-1; i >= 0; i--) {
                mint cur = prevs / mint(N) + XS[i];
                prevs += cur;
                ans += cur;
        }

        ans = ans / mint(N);
        
        cout << ans << '\n';
}

int32_t main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        run();
}

/*
 * encerra no momento em que tu joga
 * um valor menor que o anterior
 *
 * dp[i] = valor esperado com o primeiro valor sendo i
 *
 * se o menor valor for tirado encerra ali, ele é O(1)
 * Dynamic programming, expected value
 * */
