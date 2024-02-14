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

const ll oo = 1e18;
int T(1);

auto run() {
  int N, K, M;
  cin >> N >> K >> M;
  string S;
  cin >> S;

  string ans;
  int start = 0;
  for (int i = 0; i < N; i++) {
    vi first(26, 1e9);
    for (int j = start; j < M; j++) {
      int k = S[j] - 'a';
      first[k] = min(first[k], j);
    }

    int best = -1;
    for (int j = 0; j < K; j++) {
      if (best == -1 or first[best] < first[j]) best = j;
    }

    if (first[best] == 1e9) {
      cout << "NO\n";
      cout << ans << string(N - len(ans), best + 'a')
           << '\n';
      return;
    }

    ans.push_back(best + 'a');

    start = first[best] + 1;
  }

  cout << "YES\n";
  return;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, strings, greddy
