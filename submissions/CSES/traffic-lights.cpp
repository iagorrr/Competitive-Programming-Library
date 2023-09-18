#include <bits/stdc++.h>
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
ll X, N;
void run() {
  cin >> X >> N;

  set<ll> st;
  st.insert(0);
  st.insert(X);
  set<array<ll, 3>> segments;
  segments.insert({X, 0, X});

  for (int i = 0; i < N; i++) {
    ll xi;
    cin >> xi;

    // last element lower than xi
    ll l = *prev(st.lower_bound(xi));

    // first element greater than xi
    ll r = *st.upper_bound(xi);

    // cout << xi << ' ' << l << ' ' << r << endl;

    st.insert(xi);
    segments.erase({r - l, l, r});
    segments.insert({xi - l, l, xi});
    segments.insert({r - xi, xi, r});

    cout << (*prev(segments.end()))[0] << ' ';
  }
  cout << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, data structures, searching
