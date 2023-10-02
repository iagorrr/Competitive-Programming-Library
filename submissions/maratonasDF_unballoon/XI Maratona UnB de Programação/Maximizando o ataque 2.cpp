#include <bits/stdc++.h>
using namespace std;
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

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ll oo = 1e18;

const int MAXN{100}, MAXM{100000};
ll st[MAXN + 1][MAXM + 1];
int ps[MAXN + 1][MAXM + 1];
pair<ll, vector<pair<int, int>>> knapsack(int M, const vll2d &VS,
                                          const vi2d &WS) {
  memset(st, 0, sizeof(st));
  memset(ps, -1, sizeof(ps));
  int N = len(VS) - 1;  // ELEMENTS START AT INDEX 1 !

  for (int i = 0; i <= N; ++i) st[i][0] = 0;

  for (int m = 0; m <= M; ++m) st[0][m] = 0;

  for (int i = 1; i <= N; ++i) {
    for (int k = 0; k < 4; k++) {
      for (int m = 1; m <= M; ++m) {
        st[i][m] = max(st[i - 1][m], st[i][m]);
        int w = WS[i][k];
        ll v = VS[i][k];

        if (w <= m and st[i - 1][m - w] + v > st[i][m]) {
          st[i][m] = st[i - 1][m - w] + v;
          ps[i][m] = k;
        }
      }
    }
  }

  int m = M;
  vector<pii> is;
  for (int i = N; i >= 1; --i) {
    int ch = ps[i][m];
    if (ch != -1) {
      is.emplace_back(i - 1, ch);
      m -= WS[i][ch];
    }
  }

  return {st[N][M], is};
}
int N, M;
auto solve() {
  cin >> N >> M;
  vll2d VS(N + 1, vll(4));
  vi2d WS(N + 1, vi(4));
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> VS[i][j];
    }

    for (int j = 0; j < 4; j++) {
      cin >> WS[i][j];
    }
  }
  auto [v, cs] = knapsack(M, VS, WS);
  cout << v << ' ' << len(cs) << endl;
  for (auto ci : cs) {
    cout << ci.first + 1 << ' ' << ci.second << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) solve();
}

// AC, binary knapsack, bottom up
