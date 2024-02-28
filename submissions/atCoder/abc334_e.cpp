#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
// #define int long long
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

const ll OO = 1e18;
const int oo = 1e9;

int T(1);

const int MAXHW(1000);
string grid[MAXHW];
int H, W;

const ll MOD = 998244353;
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

  mint& operator+=(mint const& b) {
    value += b.value;
    if (value >= _mod) value -= _mod;
    return *this;
  }
  mint& operator-=(mint const& b) {
    value -= b.value;
    if (value < 0) value += _mod;
    return *this;
  }
  mint& operator*=(mint const& b) {
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
  friend mint inverse(mint a) { return mexp(a, _mod - 2); }

  mint& operator/=(mint const& b) {
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
  friend mint operator-(mint const a) { return 0 - a; }
  mint operator--(int) {
    return this->value = (this->value - 1 + _mod) % _mod;
  }

  mint operator--() {
    return this->value = (this->value - 1 + _mod) % _mod;
  }
  friend mint operator*(mint a, mint const b) {
    return a *= b;
  }
  friend mint operator/(mint a, mint const b) {
    return a /= b;
  }
  friend std::ostream& operator<<(std::ostream& os,
                                  mint const& a) {
    return os << a.value;
  }
  friend bool operator==(mint const& a, mint const& b) {
    return a.value == b.value;
  }
  friend bool operator!=(mint const& a, mint const& b) {
    return a.value != b.value;
  }
};
int qtdcomp = 0;
int comp[MAXHW][MAXHW];

void dfs(int x, int y) {
  comp[x][y] = qtdcomp;

  for (int i = 0; i < 4; i++) {
    int x2 = x + dx[i], y2 = y + dy[i];
    if (x2 < 0 or y2 < 0) continue;
    if (x2 >= H or y2 >= W) continue;
    if (comp[x2][y2]) continue;
    if (grid[x2][y2] == '.') continue;
    dfs(x2, y2);
  }
}

void calcComps() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (comp[i][j] or grid[i][j] == '.') continue;

      qtdcomp++;
      dfs(i, j);
    }
  }
}

mint ans;

void calcAns() {
  mint cntRed = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cntRed += grid[i][j] == '.';
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == '#') continue;

      set<int> comps;
      for (int k = 0; k < 4; k++) {
        int i2 = i + dx[k];
        int j2 = j + dy[k];

        if (i2 < 0 or j2 < 0) continue;
        if (i2 >= H or j2 >= W) continue;
        if (grid[i2][j2] == '.') continue;
        comps.emplace(comp[i2][j2]);
      }

      mint curComps = qtdcomp - len(comps) + 1;
      ans += curComps / mint(cntRed);
    }
  }
}

auto run() {
  cin >> H >> W;

  for (int i = 0; i < H; i++) {
    cin >> grid[i];
  }

  calcComps();

  calcAns();

  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, expected value
