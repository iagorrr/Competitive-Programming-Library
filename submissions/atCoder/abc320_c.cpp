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
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll oo = 1e18;

void run() {
  int n;
  cin >> n;
  vector<string> ss(3);
  for (int i = 0; i < 3; i++) {
    cin >> ss[i];
  }

  int ans = 1e9 + 1;
  sort(all(ss));
  do {
    for (char c = '0'; c <= '9'; c++) {
      int curans = 0;
      int cnt = 0;
      set<int> tu;
      // cout << "tentando " << c << endl;
      for (int i = 0; i < 3; i++) {
        for (int k = 0; k <= 5 * n; k++) {
          if (ss[i][((k) % n)] == c and !tu.count(k)) {
            // cout << "     parei o " << i << " no " << k << endl;
            curans = max(k, curans);
            tu.insert(k);
            cnt++;
            break;
          }
        }
      }

      if (cnt == 3) {
        // cout << (char)c << ' ' << curans << endl;
        ans = min(ans, curans);
      }
    }
  } while (next_permutation(all(ss)));

  cout << (ans == (int)1e9 + 1 ? -1 : ans) << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, brute force
