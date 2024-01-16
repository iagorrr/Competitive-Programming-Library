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
const ll oo = 1e18;
int T(1);

auto run() {
  ll h, w, xa, ya, xb, yb;
  cin >> h >> w >> xa >> ya >> xb >> yb;

  if (xb <= xa) {
    cout << "Draw\n";
    return;
  }

  ll dx = xb - xa;
  ll m = (dx + 1ll) >> 1;

  if (ya == yb) {
    if (!(dx & 1))
      cout << "Bob\n";
    else
      cout << "Alice\n";
    return;
  }

  if (!(dx & 1ll)) {  // bob moves to equal height
    // can alice run ? draw
    // else bob
    // maxima distancia no eixo y
    ll fdy = max(abs(min(w, ya + (m)) - yb),
                 abs(max(1ll, ya - (m)) - yb));
    if (fdy > m) {
      cout << "Draw\n";
    } else {
      cout << "Bob\n";
    }

  } else {  // alice moves to equal height
    // can bob run ? draw
    //
    // else alice
    ll fdy = max(abs(min(w, yb + (m - 1ll)) - ya),
                 abs(max(1ll, yb - (m - 1ll)) - ya));
    if (fdy > m) {
      cout << "Draw\n";
    } else {
      cout << "Alice\n";
    }
  }
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
 * games
 * math
 * https://codeforces.com/contest/1921/problem/E
 * */
