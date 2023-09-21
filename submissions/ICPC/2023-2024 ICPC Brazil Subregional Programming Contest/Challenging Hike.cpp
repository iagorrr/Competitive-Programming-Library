#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
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

const int oo = 1e9;

int n;
const int maxn = 1e5;
vi2d ps(maxn + 1);
vi vs(maxn + 1);
vi ans(maxn + 1);
vi lis(maxn + 1, oo);
void dfs(int u, int cur) {
  auto it = lower_bound(all(lis), vs[u]);
  int pos = (int)(it - lis.begin());
  cur = max(cur, pos);
  ans[u] = cur;
  int pit = *it;
  *it = min(vs[u], *it);
  for (auto &ci : ps[u]) dfs(ci, cur);
  *it = pit;
}
void run() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int pi;
    cin >> pi;
    ps[pi].eb(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> vs[i];
  }

  lis[0] = -oo;
  dfs(1, 0);
  for (int i = 2; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graphs, trees, longest increasing subsequence
