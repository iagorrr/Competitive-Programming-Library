// iagorrr ;)
#include <algorithm>
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

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

ll solve(ll n, ll t, vll &a) {
  ll ans = 0;
  ll lowest = LLONG_MAX; 
  ll maxdiff = 0;
  for(int i = 0; i < n; ++i) {
    if(a[i] >= lowest)
      maxdiff = max(maxdiff, a[i]-lowest);
    lowest = min(lowest, a[i]);
  }

  multiset<ll> st;
  for(int i = 0; i < n; ++i) {

    if (st.count(a[i] - maxdiff)) {
      ans++;
      a[i] -= 1;
    }
    st.insert(a[i]);
  }

  return ans;
}

void run(){
  ll n, t; cin >> n >> t;
  vll a(n); INV(a);

  cout << solve(n, t, a) << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, greedy.
