// iagorrr ;)
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
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

ll solve(string s){
  ll ans = 0;
  unordered_map<ll, ll> h;
  ll bitmask = 0;
  h[0] = 1;
  for(int i = 0; i < (int)s.size(); ++i) {
    int v = s[i]-'0';
    bitmask = bitmask^(1<<v);
    ans += h[bitmask];
    h[bitmask]++;
  }
  return ans; 
}
void run(){
  string s; cin >> s;

  cout << solve(s) << '\n';

}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, bitmask.
