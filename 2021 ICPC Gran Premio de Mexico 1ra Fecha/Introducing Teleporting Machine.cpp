#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;

void run() {
  ll n, k, t;
  cin >> n >> k >> t;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  vector<ll> psum(n);
  vector<ll> pref(n), suf(n);
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + i * (v[i] - v[i - 1]);
    psum[i] = psum[i - 1] + (v[i] - v[i - 1]);
  }
  suf[0] = pref.back();
  for (int i = 1; i < n; i++) {
    suf[i] = suf[i - 1] - (psum.back() - psum[i - 1]);
    // cerr << "suf[i] = " << suf[i] << ' ';
  }
  // cerr << '\n';

  ll ans = LLONG_MAX;
  ll best_i = -1, best_j = -1;
  for (int l = 0, r = 0; l < n - 1; l++) {
    if (r < l) r = l;
    while (r < n and psum[r] - psum[l] <= k) r++;
    --r;

    if (r == l) {
      r++;
      continue;
    }

    ll cost = pref[l] + (t + psum.back() - psum[r]) * (l + 1) + suf[l + 1];
    // cerr << "cost : " << cost << ", l = " << l << ", r -> " << r << '\n';
    // cerr << "pref[l]: " << pref[l] << '\n';
    // cerr << "suf[l+1]: " << suf[l+1] << '\n';
    if (ans > cost) {
      ans = cost;
      best_i = l;
      best_j = r;
    }
  }
  // cerr << "pref.back() = " << pref.back() << '\n';

  if (ans >= pref.back())
    cout << "-1\n";
  else
    cout << best_i + 1 << ' ' << best_j + 1 << ' ' << ans << "\n";
}

int32_t main() {
  fastio;
  int t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, prefix sum, two pointers
