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
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);

ll mul(ll a, ll b, ll m) {
  ll ret = a * b - (ll)((ld)1 / m * a * b + 0.5) * m;
  return ret < 0 ? ret + m : ret;
}

ll pow(ll a, ll b, ll m) {
  ll ans = 1;
  for (; b > 0; b /= 2ll, a = mul(a, a, m)) {
    if (b % 2ll == 1) ans = mul(ans, a, m);
  }
  return ans;
}

bool prime(ll n) {
  if (n < 2) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0) return 0;

  ll r = __builtin_ctzll(n - 1), d = n >> r;
  for (int a :
       {2, 325, 9375, 28178, 450775, 9780504, 795265022}) {
    ll x = pow(a, d, n);
    if (x == 1 or x == n - 1 or a % n == 0) continue;

    for (int j = 0; j < r - 1; j++) {
      x = mul(x, x, n);
      if (x == n - 1) break;
    }
    if (x != n - 1) return 0;
  }
  return 1;
}

ll rho(ll n) {
  if (n == 1 or prime(n)) return n;
  auto f = [n](ll x) { return mul(x, x, n) + 1; };

  ll x = 0, y = 0, t = 30, prd = 2, x0 = 1, q;
  while (t % 40 != 0 or gcd(prd, n) == 1) {
    if (x == y) x = ++x0, y = f(x);
    q = mul(prd, abs(x - y), n);
    if (q != 0) prd = q;
    x = f(x), y = f(f(y)), t++;
  }
  return gcd(prd, n);
}

vll fact(ll n) {
  if (n == 1) return {};
  if (prime(n)) return {n};
  ll d = rho(n);
  vll l = fact(d), r = fact(n / d);
  l.insert(l.end(), r.begin(), r.end());
  return l;
}
auto solve() {
  int N;
  cin >> N;
  vll xs(N);
  for (auto &xi : xs) cin >> xi;

  vector<map<ll, int>> factors(N);
  map<ll, int> histogram;
  for (int i = 0; i < N; i++) {
    auto xi = xs[i];
    auto facts = fact(xi);
    // dbg(xi, facts);
    for (auto fi : facts) {
      histogram[fi]++;
      factors[i][fi]++;
    }
  }

  vector<pll>  qtdeach;
  for (auto &[v, q] : histogram) {
    if (q % N) return false;
    qtdeach.emplace_back(q, q/N);
  }

  // map<ll,int> carrying;
  // for (int i = 0; i < N; i++) {
  //   for (auto &[p, q] : qtdeach) {
  //     if (factors[i][p] > q) {
  //       carrying[p] += factors[i][p] - q;
  //     }
  //     else if (factors[i][p] < q) {
  //       // if (q-factors[i][p] > carrying[p]) return false;
  //       carrying[p] -= q-factors[i][p];
  //     }
  //   }
  // }

  return true;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
}

// AC, math, number theory
