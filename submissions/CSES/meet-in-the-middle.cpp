#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
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

vll get_subset_sums(int l, int r, vector<int> &a) {
  int len = r - l + 1;
  vll res;

  for (int i = 0; i < (1 << len); i++) {
    ll sum = 0;
    for (int j = 0; j < len; j++) {
      if (i & (1 << j)) {
        sum += a[l + j];
      }
    }
    res.push_back(sum);
  }
  return res;
};

int32_t main() {
  fastio;

  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vll left = get_subset_sums(0, n / 2 - 1, a);
  vll right = get_subset_sums(n / 2, n - 1, a);
  sort(all(left));
  sort(all(right));
  ll ans = 0;
  for (ll i : left) {
    auto start_index =
      lower_bound(right.begin(), right.end(), x - i) - right.begin();
    auto end_index =
      upper_bound(right.begin(), right.end(), x - i) - right.begin();
    ans += end_index - start_index;
  }
  cout << ans << endl;
}

// AC,complete search, meet in the middle
