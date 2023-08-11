// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define len(__x) (ll) __x.size()
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define INV(xxxx) \
  for (auto &xxx : xxxx) cin >> xxx;
#define PRINTV(___x) \
  for_each(all(___x), [](ll &____x) { cout << ____x << ' '; }), cout << '\n';
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
#define rsz(___x, ___n) resize(___x, ___n)

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                 \
  {                              \
    cerr << #__VA_ARGS__ << ':'; \
    dbg_out(__VA_ARGS__);        \
  }
const ll INF = 1e18;

void run() {
  ll n, d, a;
  cin >> n >> d >> a;

  vector<pll> ms(n);
  for (int i = 0; i < n; ++i) {
    cin >> ms[i].fst >> ms[i].snd;
  }
  sort(all(ms));

  vll range(n);
  for (int i = 0; i < n; ++i) {
    ll j = range[max(0, i - 1)];
    range[i] = range[max(0, i - 1)];
    while (j < n and ms[j].fst - ms[i].fst <= 2 * d) range[i] = j, j++;
  }

  vll psumbomb(n + 1);
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    psumbomb[i] += psumbomb[max(0ll, i - 1)];
    ll bombed = max(0ll, psumbomb[i]);
    auto [pos, hp] = ms[i];
    hp -= bombed * a;
    if (hp <= 0) continue;

    ll tokill = hp / a + (hp % a != 0);
    ans += tokill;
    ll l = i;
    ll r = range[i] + 1;
    psumbomb[l] += tokill;
    psumbomb[r] -= tokill;
  }
  cout << ans << '\n';
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, greedy, binary search
