/*8<
  @Title:

    Chinese Remainder Theorem

  @Description:

    Find the solution $X$ to the $N$ modular
    equations.

    \begin{equation}
      \begin{aligned}
        x \equiv a_1 (mod m_1) \\
        ... \\
        x \equiv a_n (mod m_n)
      \end{aligned}
    \end{equation}

    The $m_i$ don't need to be coprime, if there
    is no solution then it returns -1.
>8*/
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
T chinese_remainder_theorem(const vector<Congruence<T>> &equations) {
  crt<T> ans;

  for (auto &[a_, m_] : equations) {
    ans = ans * crt<T>(a_, m_);
  }

  return ans.a;
}
