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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void run() {
  int n, k;
  cin >> n >> k;

  vi xs(n);
  for (auto &xi : xs) cin >> xi;
  ordered_set<pair<int, int>> st;

  for (int i = 0; i < k; i++) {
    st.insert({xs[i], i});
  }

  int pi = 0, pj = k;
  int mid = (k + 1) / 2 - 1;
  while (pj < n) {
    cout << (*st.find_by_order(mid)).fst << ' ';

    st.erase({xs[pi], pi});
    st.insert({xs[pj], pj});

    pi++, pj++;
  }

  cout << (*st.find_by_order(mid)).fst << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, sliding window, ordered set
