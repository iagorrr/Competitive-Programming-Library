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
int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 2e18 + 1;
int T(1);
const int MAXN(1'000'000);

auto run() {
  ll n, q;
  cin >> n >> q;
  vll lst(n), sz(n);
  for (int i = 0; i < n; i++) {
    ll o, x;
    cin >> o >> x;
    if (o == 1) {
      lst[i] = x, sz[i] = i ? sz[i - 1] + 1 : 1;
    } else {
      lst[i] = lst[i - 1];
      sz[i] = ((x + 1) >= oo / sz[i - 1])
                ? oo
                : sz[i - 1] * (x + 1);
    }
  }

  while (q--) {
    ll k;
    cin >> k;
    int p = n - 1;
    while (k) {
      int l = 0, r = n - 1;
      while (l <= r) {
        int mid = midpoint(l, r);
        if (sz[mid] >= k) {
          p = min(p, mid);
          r = mid - 1;
        } else
          l = mid + 1;
      }
      if (sz[p] == k) break;
      if (p and (k % sz[p - 1]) == 0) break;
      k %= sz[p - 1];
    }
    cout << lst[p] << ' ';
  }
  cout << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

/*
 * AC
 * math
 * binary search
 * */
