const ll MOD = 1 '000' 000'000 + 7;
template <ll _mod = MOD>
struct mint {
  ll value;
  static const ll MOD_value = _mod;

  mint(ll v = 0) {
    value = v % _mod;
    if (value < 0) value += _mod;
  }
  mint(ll a, ll b) : value(0) {
    *this += a;
    *this /= b;
  }

  mint &operator+=(mint const &b) {
    value += b.value;
    if (value >= _mod) value -= _mod;
    return *this;
  }
  mint &operator-=(mint const &b) {
    value -= b.value;
    if (value < 0) value += _mod;
    return *this;
  }
  mint &operator*=(mint const &b) {
    value = (ll)value * b.value % _mod;
    return *this;
  }

  friend mint mexp(mint a, ll e) {
    mint res = 1;
    while (e) {
      if (e & 1) res *= a;
      a *= a;
      e >>= 1;
    }
    return res;
  }
  friend mint inverse(mint a) {
    return mexp(a, _mod - 2);
  }

  mint &operator/=(mint const &b) {
    return *this *= inverse(b);
  }
  friend mint operator+(mint a, mint const b) {
    return a += b;
  }
  mint operator++(int) {
    return this->value = (this->value + 1) % _mod;
  }
  mint operator++() {
    return this->value = (this->value + 1) % _mod;
  }
  friend mint operator-(mint a, mint const b) {
    return a -= b;
  }
  friend mint operator-(mint const a) {
    return 0 - a;
  }
  mint operator--(int) {
    return this->value =
               (this->value - 1 + _mod) % _mod;
  }

  mint operator--() {
    return this->value =
               (this->value - 1 + _mod) % _mod;
  }
  friend mint operator*(mint a, mint const b) {
    return a *= b;
  }
  friend mint operator/(mint a, mint const b) {
    return a /= b;
  }
  friend std::ostream &operator<<(
      std::ostream &os, mint const &a) {
    return os << a.value;
  }
  friend bool operator==(mint const &a,
                         mint const &b) {
    return a.value == b.value;
  }
  friend bool operator!=(mint const &a,
                         mint const &b) {
    return a.value != b.value;
  }
};
