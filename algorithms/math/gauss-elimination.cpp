template <size_t Dim> struct GaussianElimination {
  vector<ll> basis;
  size_t size;

  GaussianElimination() : basis(Dim + 1), size(0) {}

  void insert(ll x) {
    for (ll i = Dim; i >= 0; i--) {
      if ((x & 1ll << i) == 0)
        continue;

      if (!basis[i]) {
        basis[i] = x;
        size++;
        break;
      }

      x ^= basis[i];
    }
  }

  void normalize() {
    for (ll i = Dim; i >= 0; i--)
      for (ll j = i - 1; j >= 0; j--)
        if (basis[i] & 1ll << j)
          basis[i] ^= basis[j];
  }

  bool check(ll x) {
    for (ll i = Dim; i >= 0; i--) {
      if ((x & 1ll << i) == 0)
        continue;

      if (!basis[i])
        return false;

      x ^= basis[i];
    }

    return true;
  }

  auto operator[](ll k) { return at(k); }

  ll at(ll k) {
    ll ans = 0;
    ll total = 1ll << size;
    for (ll i = Dim; ~i; i--) {
      if (!basis[i])
        continue;

      ll mid = total >> 1ll;
      if ((mid < k and (ans & 1ll << i) == 0) ||
          (k <= mid and (ans & 1ll << i)))
        ans ^= basis[i];

      if (mid < k)
        k -= mid;

      total >>= 1ll;
    }
    return ans;
  }

  ll at_normalized(ll k) {
    ll ans = 0;
    k--;
    for (size_t i = 0; i <= Dim; i++) {
      if (!basis[i])
        continue;
      if (k & 1)
        ans ^= basis[i];
      k >>= 1;
    }
    return ans;
  }
};
