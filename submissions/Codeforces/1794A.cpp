// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()
// take the largest prefix and largest suffix and check if is palindrome.
string solve(vector<pair<int, string>> ss, int n) {
  sort(all(ss));
  string a = ss.back().second; ss.pop_back();
  string b = ss.back().second;
  reverse(all(a));

  return a == b ? "YES" : "NO";
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<pair<int,string>> ss(n*2-2);
    for(int i = 0; i < n*2-2; ++i) {
      cin >> ss[i].second;
      ss[i].first = ss[i].second.size();
    }
    cout << solve(ss, n) << '\n';
  }
}
// AC, strings, palindrome.
