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

void run() {
  ll n, k, x;
  cin >> n >> k >> x;

  // use only 1 
  if (k >= 1 and x != 1) {
    cout << "YES\n";
    cout << n << '\n';
    for (int i = 0; i < n; ++i)
      cout << 1 << ' ';
    cout << '\n';
    return;
  }

  // as 2 as possible
  if(n%2==0 and k>= 2 and x != 2) {
    cout << "YES\n";
    vll ans;
    ans.push_back(2);
    ll cur = 2;
    while (cur != n) {
      ans.push_back(2);
      cur += 2;
    }
    cout << ans.size() << '\n';
    for (auto xi : ans)
      cout << xi << ' ';
    cout << '\n';
    return;
  }

  // as two as possible and a 3 do set it odd
  if (n&1 and k >= 3 and x != 2 and x != 3) {
    cout << "YES\n";
    vll ans;
    ans.push_back(3);
    ll cur = 3;
    while (cur != n) {
      ans.push_back(2);
      cur += 2;
    }
    cout << ans.size() << '\n';
    for (auto xi : ans)
      cout << xi << ' ';
    cout << '\n';
    return;
  }


  cout << "NO\n";
}
int32_t main(void) {
  // fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--)
    run();
}

// AC, ad-hoc
