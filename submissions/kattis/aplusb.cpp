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

const ld PI = acos(-1);

/* change the ld to doulbe may increase performance =D */
struct num {
  double a{0.0}, b{0.0};
  num() {}
  num(double na) : a{na} {}
  num(double na, double nb) : a{na}, b{nb} {}

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
  // for (auto& xi : result) xi = min(xi, 1ll);

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
ll k50 = 50000;
auto run() {
  int n;
  cin >> n;

  vll xs(n);
  map<ll, ll> hist;
  vll factor(k50 * 2 + 1);
  for (auto& xi : xs) {
    cin >> xi;

    hist[xi]++;
    if (!xi) continue;

    xi += k50;
    factor[xi]++;
  }

  auto tmp = factor;
  auto convresult = conv(factor, tmp);

  map<ll, ll> conv;
  for (int i = 0; i < len(convresult); i++) {
    auto convi = convresult[i];
    if (!convi) continue;
    if (hist[i - k50 * 2]) conv[i - k50 * 2] = convi;
  }

  for (auto& [v, qtd] : conv) {
    if (!v) continue;
    if (v & 1) continue;
    if (hist.find(v / 2) != hist.end()) {
      qtd -= hist[v / 2] * hist[v / 2] -
             hist[v / 2] * (hist[v / 2] - 1);
    }
  }

  dbg(conv);

  map<ll, ll> ways;
  for (auto& [v, qtd] : conv) {
    if (!qtd) continue;
    ways[v] = qtd * hist[v];
  }

  ll ans = 0;

  dbg(ways);

  if (hist[0]) {
    for (auto& [v, qtd] : hist) {
      if (!v) continue;
      ll increment = 2 * qtd * hist[0] * (qtd - 1);
      dbg(v, increment);
      ways[v] += increment;
    }
    ways[0] += hist[0] * (hist[0] - 1) * (hist[0] - 2);
  }

  for (auto& [________________, maxwways] : ways) {
    ans += maxwways;
  }

  cout << ans << '\n';
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

// AC, fft, convolution
