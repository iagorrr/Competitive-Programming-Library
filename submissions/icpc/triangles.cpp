#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using vll = vector<ll>;
#define all(__x) __x.begin(), __x.end()
using vc = vector<char>;

void solve() {
  ll n;
  cin >> n;
  vector<ll> ps(n + 1);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ps[i + 1] = ps[i] + x;
  }
  if (ps.back() % 3) {
    cout << "0\n";
    return;
  }
  ll x = ps.back() / 3;
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    auto value = ps[i] + x;
    auto can = binary_search(all(ps), value);
    if (!can) continue;
    value = ps[i] + 2 * x;
    can = binary_search(all(ps), value);
    if (!can) continue;
    ans++;
  }
  cout << ans << '\n';
}
int32_t main() {
  int t = 1;
  //  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

// AC, prefixsum, geometry
