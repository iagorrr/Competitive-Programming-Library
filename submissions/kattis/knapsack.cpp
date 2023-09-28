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

const int MAXN{2010}, MAXM{2010};
ll st[MAXN][MAXM];
char ps[MAXN][MAXM];
pair<ll, vi> knapsack(int M, const vll &VS, const vi &WS) {
  memset(st, 0, sizeof(st));
  memset(st, 0, sizeof(st));
  int N = len(VS) - 1;  // ELEMENTS START AT INDEX 1 !

  for (int i = 0; i <= N; ++i) st[i][0] = 0;

  for (int m = 0; m <= M; ++m) st[0][m] = 0;

  for (int i = 1; i <= N; ++i) {
    for (int m = 1; m <= M; ++m) {
      st[i][m] = st[i - 1][m];
      ps[i][m] = 0;
      int w = WS[i];
      ll v = VS[i];

      if (w <= m and st[i - 1][m - w] + v > st[i][m]) {
        st[i][m] = st[i - 1][m - w] + v;
        ps[i][m] = 1;
      }
    }
  }

  int m = M;
  vi is;
  for (int i = N; i >= 1; --i) {
    if (ps[i][m]) {
      is.emplace_back(i - 1);
      m -= WS[i];
    }
  }

  return {st[N][M], is};
}

int32_t main(void) {
  fastio;
  int N, C;
  while (cin >> C >> N) {
    vll VS(N + 1);
    vi WS(N + 1);

    for (int i = 1; i <= N; i++) {
      cin >> VS[i] >> WS[i];
    }
    auto [v, vs] = knapsack(C, VS, WS);
    cout << len(vs) << endl;
    for (auto xi : vs) cout << xi << ' ';
    cout << endl;
  }
}

// AC, dynamic programming knapsack
