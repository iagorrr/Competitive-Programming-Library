#include <bits/stdc++.h>

#include <algorithm>
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
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = LLONG_MAX;
int T(1);
const int MAXN(1'000'000);

int N, K;
vll xs;

bool check(int m) {
  if (!m) return 1;
  vll stacks(m, oo);

  int cnt = 0, pm = 0;
  for (auto xi : xs) {
    if ((stacks[pm] >= xi * 2ll)) {
      stacks[pm] = xi;
      pm = (pm + 1) % m;
      cnt++;
    }
  }

  return cnt >= K * m;
}

int run() {
  cin >> N >> K;
  xs.resize(N);
  for (auto &xi : xs) cin >> xi;

  sort(all(xs), greater<ll>());
  int ans = 0;

  for (int l = 0, r = (N + K - 1) / K; l <= r;) {
    int m = midpoint(l, r);
    if (check(m)) {
      ans = max(ans, m);
      l = m + 1;
    } else
      r = m - 1;
  }

  return ans;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": " << run() << '\n';
  }
}

/*
 * Greedy
 * binary search
 * */
