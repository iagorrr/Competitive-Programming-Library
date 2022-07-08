#include "../Contest/template.cpp"

template <ll Mod>
struct modint {
    static constexpr ll mod = Mod;
    ll v;
    modint() : v(0) {}
    template <ll Mod2>
    modint(const modint<Mod2> &x) : v(x.value()) {}
    modint(ll x) : v(safe_mod(x)) {}
    ll &value() { return v; }
    const ll &value() const { return v; }
    static ll safe_mod(ll x) {
        return x >= 0 ? x % mod : ((x % mod) + mod) % mod;
    }
    template <typename T>
    explicit operator T() const {
        return (T)v;
    }
    bool operator==(const modint rhs) const noexcept { return v == rhs.v; }
    bool operator!=(const modint rhs) const noexcept { return v != rhs.v; }
    bool operator<(const modint rhs) const noexcept { return v < rhs.v; }
    bool operator<=(const modint rhs) const noexcept { return v <= rhs.v; }
    bool operator>(const modint rhs) const noexcept { return v > rhs.v; }
    bool operator>=(const modint rhs) const noexcept { return v >= rhs.v; }
    modint operator++(int) {
        modint res = *this;
        *this += 1;
        return res;
    }
    modint operator--(int) {
        modint res = *this;
        *this -= 1;
        return res;
    }
    modint &operator++() { return *this += 1; }
    modint &operator--() { return *this -= 1; }
    modint operator+() const { return modint(*this); }
    modint operator-() const { return mod - modint(*this); }
    friend modint operator+(const modint lhs, const modint rhs) noexcept {
        return modint(lhs) += rhs;
    }
    friend modint operator-(const modint lhs, const modint rhs) noexcept {
        return modint(lhs) -= rhs;
    }
    friend modint operator*(const modint lhs, const modint rhs) noexcept {
        return modint(lhs) *= rhs;
    }
    friend modint operator/(const modint lhs, const modint rhs) noexcept {
        return modint(lhs) /= rhs;
    }
    modint &operator+=(const modint rhs) {
        v += rhs.v;
        if (v >= mod) v -= mod;
        return *this;
    }
    modint &operator-=(const modint rhs) {
        if (v < rhs.v) v += mod;
        v -= rhs.v;
        return *this;
    }
    modint &operator*=(const modint rhs) {
        v = v * rhs.v % mod;
        return *this;
    }
    modint &operator/=(modint rhs) { return *this *= rhs.inv(); }
    modint pow(ll p) const {
        static_assert(mod < static_cast<ll>(1) << 32,
                      "Modulus must be less than 2**32");
        modint res = 1, a = *this;
        while (p) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }
    modint inv() const { return pow(mod - 2); }
    modint sqrt() const {
        modint b = 1;
        while (b.pow((mod - 1) >> 1) == 1) b += 1;
        ll m = mod - 1, e = 0;
        while (~m & 1) m >>= 1, e++;
        auto x = pow((m - 1) >> 1);
        auto y = *this * x * x;
        x *= *this;
        auto z = b.pow(m);
        while (y != 1) {
            ll j = 0;
            for (modint t = y; t != 1; t *= t, ++j);
            z.pow(1ll << (e - j - 1));
            x *= z;
            z *= z;
            y *= z;
            e = j;
        }
        return x;
    }
    friend ostream &operator<<(ostream &s, const modint &x) {
        s << x.value();
        return s;
    }
    friend istream &operator>>(istream &s, modint &x) {
        ll value;
        s >> value;
        x = {value};
        return s;
    }
};
