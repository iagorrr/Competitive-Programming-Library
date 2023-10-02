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

void rotate(vi2d &a) {
  vi2d b = a;

  int n = len(a);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[i][j] = a[n - j - 1][i];
    }
  }

  a = b;
}
pair<ll, int> sum(vi2d &a, const vi2d &b, bool modify = true) {
  int n = len(a);
  ll ans = 0;
  int m = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] += b[i][j] * modify;
      ans += a[i][j];
      m = max(m, a[i][j]);
    }
  }
  return {ans, m};
}
pair<ll, int> sum(vi2d &a) {
  int n = len(a);
  ll ans = 0;
  int m = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans += a[i][j];
      m = max(m, a[i][j]);
    }
  }
  return {ans, m};
}
vi2d translate(vi2d &a, int di, int dj) {
  int n = len(a);
  vi2d a2(n, vi(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i + di >= n or j + dj >= n or i + di < 0 or j + dj < 0) continue;
      a2[i][j] = a[i + di][j + dj];
    }
  }
  return a2;
}
auto solve() {
  int n = 4;
  vi2d a(n, vi(n));
  vi2d b(n, vi(n));
  vi2d c(n, vi(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char cij;
      cin >> cij;
      a[i][j] = cij == '#';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char cij;
      cin >> cij;
      b[i][j] = cij == '#';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char cij;
      cin >> cij;
      c[i][j] = cij == '#';
    }
  }

  for (int i = 0; i < 4; i++) {
    rotate(a);
    for (int i2 = 0; i2 < 4; i2++) {
      rotate(b);
      for (int i3 = 0; i3 < 4; i3++) {
        rotate(c);
        for (int i4 = -4; i4 < 4; i4++) {
          for (int i5 = -4; i5 < 4; i5++) {
            auto a2 = translate(a, i4, i5);
            if (sum(a2) != sum(a)) continue;
            for (int i6 = -4; i6 < 4; i6++) {
              for (int i7 = -4; i7 < 4; i7++) {
                auto b2 = translate(b, i6, i7);
                if (sum(b2) != sum(b)) continue;
                for (int i8 = -4; i8 < 4; i8++) {
                  for (int i9 = -4; i9 < 4; i9++) {
                    auto c2 = translate(c, i8, i9);
                    if (sum(c2) != sum(c)) continue;
                    auto d = a2;
                    sum(d, b2);
                    auto cur = sum(d, c2);
                    if (cur.first == 4 * 4 and cur.second == 1) {
                      cout << "Yes\n";
                      return;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  cout << "No\n";
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) solve();
}

// AC, brute force
