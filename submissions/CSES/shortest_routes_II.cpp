// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a)                                                                 \
  for (auto &x : a)                                                            \
  cin >> x
#define all(a) a.begin(), a.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T> void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                                                               \
  {                                                                            \
    cerr << #__VA_ARGS__ << ':';                                               \
    dbg_out(__VA_ARGS__);                                                      \
  }

vector<vll> floyd_warshall(const vector<vll> &adj, ll n) {
  auto dist = adj;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }
  return dist;
}
ll __inf = LLONG_MAX >> 5;
void run() {
  ll n, m, q;
  cin >> n >> m >> q;

  vector<vector<ll>> adj(n, vll(n, __inf));
  for (int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    adj[a][a] = 0;
    adj[b][b] = 0;
    adj[a][b] = min(adj[a][b], c);
    adj[b][a] = min(adj[b][a], c);
  }

  auto dist = floyd_warshall(adj, n);
  while (q--) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    cout << (dist[a][b] >= __inf ? -1 : dist[a][b]) << '\n';
  }
}

int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, floyd warshall
