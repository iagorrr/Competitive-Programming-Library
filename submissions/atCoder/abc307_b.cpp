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

bool ispalin(string s) {
  int l = 0;
  int r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r])
      return false;
    l++;
    r--;
  }
  return true;
}
void run() {

  ll n;
  cin >> n;
  vector<string> ss(n);
  for (int i = 0; i < n; ++i) {
    cin >> ss[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      string s = ss[i] + ss[j];
      if (ispalin(s)) {
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, strings
