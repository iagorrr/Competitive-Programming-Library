// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

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
vector<vll> subordinates(2 * 1e5 + 1);
vll subs(2 * 1e5 + 1, -1);
ll dfs(ll x) {
  ll ans = 0;
  for (auto si : subordinates[x]) {
    if (subs[si] >= 0)
      ans += subs[si] + 1;
    else
      ans += dfs(si) + 1;
  }
  return subs[x] = ans;
}
void run() {
  ll n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    ll boss;
    cin >> boss;
    subordinates[boss].push_back(i);
  }

  for (int i = 1; i <= n; ++i) {
    cout << dfs(i) << ' ';
  }
  cout << '\n';
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, dfs, tree algorithms
