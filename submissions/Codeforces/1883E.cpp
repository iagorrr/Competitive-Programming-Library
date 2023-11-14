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

auto solve() {
  int N;
  cin >> N;

  vll XS(N);
  for (auto &xi : XS) cin >> xi;

  ll pm = 0;  // how many moves the previous one did
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    // get how many moves XS[i] need to become equal/greater
    // to XS[i-1]
    ll m = 0, tmp = XS[i];
    while (tmp < XS[i - 1]) m++, tmp *= 2;

    // from those pm movents the previous one did how many
    // would can we use and keep XS[i-1] less/equal to XS[i]
    // ?
    ll tmp2 = XS[i - 1];
    while (pm and tmp2 * 2 <= tmp) tmp2 *= 2, pm--;

    // the pm movements left make XS[i-1] greater again, so
    // we will need to use those pm movements left in XS[i]
    pm = m + pm;
    ans += pm;
  }

  cout << ans << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}

// AC, greedy
