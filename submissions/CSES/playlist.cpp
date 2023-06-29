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
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define ss second
#define ff first
#define mp make_pair

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
  ll n;
  cin >> n;
  vll xs(n);
  for (int i = 0; i < n; ++i)
    cin >> xs[i];

  ll ans = 1;
  set<ll> st;
  ll l = 0;
  ll r = 0;
  map<ll,queue<ll>> appears;
  while (l <= r and r < n and l < n) {
    ll cur = xs[r];
    // the new element is already in the set
    if (st.count(cur)) {

      // moves l to some point that value don't appear
      ll removeUntil = appears[cur].front();
      appears[cur].pop();
      while (l < removeUntil) {
        // remove element
        ll toRemove = xs[l];
        st.erase(xs[l]);
        appears[toRemove].pop();
        l++;
      }

      // goes one after the previous cur
      l++;

      // add element
      appears[cur].push(r);
      st.insert(cur);

      // now is valid segment check it
      ans = max(ans, r - l + 1);

      // check next
      r++;
    }
    // new element
    else {
      // add element
      appears[cur].push(r);
      st.insert(cur);

      // now is valid segment check it
      ans = max(ans, r - l + 1);

      // go next element
      r++;
    }
  }

  cout << ans << '\n';
}
int32_t main(void) {
  // fastio;
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, ad-hoc
