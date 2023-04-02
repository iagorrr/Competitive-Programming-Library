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

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }


ll solve(ll n, string s, vll a) {
  vector<pll> b;
  ll cur = 0;
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    b.emplace_back(a[i], s[i]);
    if(s[i]-48) cur++; // equal to say that everyone is adult.
  }

  sort(all(b));
  ans = cur;
  for(int i = 0; i < n; ++i) {
    if(b[i].second == '1') cur--; // below the adult age.
    else cur++; // okay, a child below

    if(i < n-1 ){
      if(b[i].first != b[i+1].first) // if same color decide when see if is a child or adult.
        ans = max(cur, ans);
    }
    else ans = max(ans, cur); 
  }

  return ans;
}
void run(){
  ll n; cin >> n;
  string s; cin >> s;
  vll a(n); INV(a);

  cout << solve(n , s, a) << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
// AC, greedy.
