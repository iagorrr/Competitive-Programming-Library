const ld PI = acos(-1);

/* change the ld to doulbe may increase performance =D */
struct num {
  ld a{0.0}, b{0.0};
  num() {}
  num(ld na) : a{na} {}
  num(ld na, ld nb) : a{na}, b{nb} {}

  const num operator+(const num& c) const {
    return num(a + c.a, b + c.b);
  }
  const num operator-(const num& c) const {
    return num(a - c.a, b - c.b);
  }
  const num operator*(const num& c) const {
    return num(a * c.a - b * c.b, a * c.b + b * c.a);
  }
  const num operator/(const ll& c) const {
    return num(a / c, b / c);
  }
};

void fft(vector<num>& a, bool invert) {
  int n = len(a);
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int sz = 2; sz <= n; sz <<= 1) {
    ld ang = 2 * PI / sz * (invert ? -1 : 1);
    num wsz(cos(ang), sin(ang));
    for (int i = 0; i < n; i += sz) {
      num w(1);
      rep(j, 0, sz / 2) {
        num u = a[i + j], v = a[i + j + sz / 2] * w;
        a[i + j] = u + v;
        a[i + j + sz / 2] = u - v;
        w = w * wsz;
      }
    }
  }
  if (invert)
    for (num& x : a) x = x / n;
}

vi conv(vi const a, vi const b) {
  vector<num> fa(all(a));
  vector<num> fb(all(b));
  int n = 1;
  while (n < len(a) + len(b)) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  rep(i, 0, n) fa[i] = fa[i] * fb[i];
  fft(fa, true);
  vi result(n);
  rep(i, 0, n) result[i] = round(fa[i].a);
  while (len(result) and result.back() == 0)
    result.pop_back();

  /* Unconment this line if you want a boolean convolution*/
  for (auto& xi : result) xi = min(xi, 1ll);

  return result;
}
vll poly_exp(vll& ps, int k) {
  vll ret(len(ps));
  auto base = ps;
  ret[0] = 1;

  while (k) {
    if (k & 1) ret = conv(ret, base);
    k >>= 1;
    base = conv(base, base);
  }

  return ret;
}
