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
const int MAXN(1'000'000);

vll p8s = {0,   8,   16,  24,  32,  40,  48,  56,  64,  72,
           80,  88,  96,  104, 112, 120, 128, 136, 144, 152,
           160, 168, 176, 184, 192, 200, 208, 216, 224, 232,
           240, 248, 256, 264, 272, 280, 288, 296, 304, 312,
           320, 328, 336, 344, 352, 360, 368, 376, 384, 392,
           400, 408, 416, 424, 432, 440, 448, 456, 464, 472,
           480, 488, 496, 504, 512, 520, 528, 536, 544, 552,
           560, 568, 576, 584, 592, 600, 608, 616, 624, 632,
           640, 648, 656, 664, 672, 680, 688, 696, 704, 712,
           720, 728, 736, 744, 752, 760, 768, 776, 784, 792,
           800, 808, 816, 824, 832, 840, 848, 856, 864, 872,
           880, 888, 896, 904, 912, 920, 928, 936, 944, 952,
           960, 968, 976, 984, 992, 1000};

string s;
vll2d dpos(10);

bool check(const string &sx, int p = 0, int m = -1) {
  if (p >= len(sx)) return true;
  for (auto pi : dpos[sx[p] - '0']) {
    if (pi <= m) continue;
    if (check(sx, p + 1, pi)) return true;
  }

  return false;
}

auto run() {
  cin >> s;

  int n = len(s);
  for (int i = 0; i < n; i++) {
    int d = s[i] - '0';
    dpos[d].emplace_back(i);
  }

  for (auto p8i : p8s) {
    if (check(to_string(p8i))) {
      cout << "YES\n";
      cout << p8i << '\n';
      return;
    }
  }

  cout << "NO\n";
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

/*
 * AC
 * Brute force
 * Math
 * */
