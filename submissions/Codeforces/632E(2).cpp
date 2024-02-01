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
/*======================================================================================================*/

int maxxi(1000);
auto run() {
  int n, k;
  cin >> n >> k;

  vector<ll> xs1(maxxi + 1);
  for (int i = 0; i < n; i++) {
    ll xi;
    cin >> xi;
    xs1[xi]++;
  }

  auto ans1 = xs1;
  ans1 = poly_exp(xs1, k);

  for (int i = 0; i < len(ans1); i++) {
    if (ans1[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
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

// AC, convolution
