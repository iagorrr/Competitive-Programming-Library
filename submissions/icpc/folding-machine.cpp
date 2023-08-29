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

bool dfs(vector<int> &a, vector<int> &b) {
  if (len(a) < len(b)) return false;
  {
    if (a == b) return true;
    auto ca = a;
    reverse(all(ca));
    if (ca == b) return true;
  }
  bool ans = false;
  for (int i = 0; i < len(a) / 2; i++) {
    // i = corte
    vector<int> ca;
    // reverso
    for (int j = len(a) - 1; j >= (i + 1) * 2; j--) ca.push_back(a[j]);

    for (int l = i, r = i + 1; l >= 0 and r < len(a); l--, r++)
      ca.push_back(a[l] + a[r]);

    if (dfs(ca, b)) return true;
  }
  for (int i = len(a) / 2; i < len(a) - 1; i++) {
    // corte padrão delicinha
    auto ca = a;
    for (int l = i, r = i + 1; l >= 0 and r < len(a); l--, r++) ca[l] += ca[r];
    ca.resize(i + 1);

    if (dfs(ca, b)) return true;
  }

  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int m;
  cin >> m;
  vector<int> b(m);
  for (auto &x : b) cin >> x;
  auto can = dfs(a, b);
  cout << (can ? 'S' : 'N') << '\n';
}
int32_t main() {
  int t = 1;
  //  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

// AC, brute force
