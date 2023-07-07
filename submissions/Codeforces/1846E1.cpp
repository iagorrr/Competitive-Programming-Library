// iagorrr ;)
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using ll = unsigned long long;
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
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

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

set<ll> st;
ll fastpow(ll a, int n) {
  if (n == 1)
    return a;
  ll x = fastpow(a, n / 2);
  return x * x * (n & 1 ? a : 1);
}
ll powersum(ll n, ll k) { return (fastpow(n, k + 1) - 1) / (n - 1); }
void gen() {
  for (ll i = 2; i <= 1e3 + 1; ++i) {
    for (ll j = 2; j <= 1e3 + 1; ++j) {
      ll x = powersum(i, j);
      if (x <= 1e18)
        st.insert(x);
    }
  }
}
void run() {
  ll n;
  cin >> n;
  bool ans = false;
  if (st.count(n))
    ans = true;
  cout << (ans ? "YES" : "NO") << '\n';
}

int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  gen();
  while (t--)
    run();
}

// AC, math, brute force
