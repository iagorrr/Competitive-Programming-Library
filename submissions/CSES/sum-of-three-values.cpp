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
  ll x;
  cin >> n >> x;

  vector<pair<ll, int>> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i].fst;
    xs[i].snd = i;
  }
  sort(all(xs));

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll miss = x - xs[i].fst - xs[j].fst;
      int l = j + 1;
      int r = n - 1;
      while (l <= r) {
        int mid = (l + r) / 2;

        ll d = miss - xs[mid].fst;
        if (d < 0) {
          r = mid - 1;
        } else if (d > 0) {
          l = mid + 1;
        } else {
          cout << xs[i].snd + 1 << ' ' << xs[j].snd + 1 << ' '
               << xs[mid].snd + 1 << endl;
          return;
        }
      }
    }
  }

  cout << "IMPOSSIBLE\n";
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, sorting and searching
