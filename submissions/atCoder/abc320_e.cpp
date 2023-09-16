#include <bits/stdc++.h>

#include <queue>
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
  int n, m;
  cin >> n >> m;

  priority_queue<ll, vector<ll>, greater<ll>> fila;
  priority_queue<pll, vector<pll>, greater<pll>> comendo;

  for (int i = 0; i < n; i++) {
    fila.push(i);
  }

  vll ans(n);
  while (m--) {
    ll t, w, s;
    cin >> t >> w >> s;
    while (!comendo.empty()) {
      if (comendo.top().first > t) break;
      fila.push(comendo.top().second);
      comendo.pop();
    }

    if (fila.empty()) continue;

    ll p = fila.top();
    fila.pop();
    ans[p] += w;
    comendo.emplace(t + s, p);
  }

  for (auto &ai : ans) cout << ai << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, implementation
