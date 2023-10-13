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
  // versão pouco(nada) otimizada
  string s;
  cin >> s;
  ll k;
  cin >> k;
  set<ll> st;
  for (int i = 0; i <= s.size() - k; ++i) {
    ll cur = 0;
    for (int j = 0; j < k; ++j) {
      cur |= ((s[i + j] == '1') << j);
    }
    st.insert(cur);
  }

  ll q;
  cin >> q;
  while (q--) {
    cin >> s;
    bool ans = false;
    for (int i = 0; i <= s.size() - k; ++i) {
      ll cur = 0;
      for (int j = 0; j < k; ++j) {
        cur |= ((s[i + j] == '1') << j);
      }
      ans |= st.count(cur);
      if (ans)
        break;
    }
    cout << ans << '\n';
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, bitwise, data structures
