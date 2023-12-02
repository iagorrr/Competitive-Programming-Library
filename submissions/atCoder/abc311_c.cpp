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

const ll oo = 1e18;
int T(1);

int N;
vll XS;
vll ys;
map<ll, ll> pos;
map<ll, ll> cnt;
vll psum;
auto solve() {
  cin >> N;
  XS.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> XS[i];
    cnt[XS[i]]++;
  }

  set<ll> st(all(XS));
  ys = vll(all(st));

  for (int i = 0; i < len(ys); i++) {
    pos[ys[i]] = i;
  }

  psum.resize(len(ys) + 1);

  for (int i = 1; i <= len(ys); i++) {
    psum[i] = psum[i - 1] + ys[i - 1] * cnt[ys[i - 1]];
  }

  for (int i = 0; i < N; i++) {
    ll tpos = pos[XS[i]];
    cout << psum[len(ys)] - psum[tpos + 1]
         << " \n"[i == N - 1];
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}

/*
 * AC
 * prefix sum
 * data structures
 * https://atcoder.jp/contests/abc331/tasks/abc331_c
 * */
