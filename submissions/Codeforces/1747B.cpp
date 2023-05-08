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

void run(){
  int n; cin >> n;

  int l = 1, r = n*3;
  vector<pii> ans;
  while(l <= r) {
    ans.emplace_back(l, r);
    l += 3;
    r -= 3;
  }

  cout << ans.size() << '\n';
  for(auto [a, b] : ans) {
    cout << a << ' ' << b << '\n';
  }
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}

// AC, strings, two pointers.
