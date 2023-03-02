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
ll solve(vll a, int n) {
  priority_queue<ll> pq;

  ll ans = 0;
  for(auto ai : a) {
    if (ai > 0) pq.push(ai);
    else {
      if(!pq.empty()){
        ans += pq.top();
        pq.pop();
      }
    }
  }
  return ans;
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vll a(n); INV(a);
    cout << solve(a, n) << '\n';
  }
}

// AC, greedy, priority_queue
