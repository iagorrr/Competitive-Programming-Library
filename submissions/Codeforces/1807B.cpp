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

void run(){
  ll n; cin >> n;
  ll a, b;
  a = 0;
  b = 0;
  for(int i = 0; i < n; ++i) {
    ll ai; cin >> ai;
    if(ai&1) b += ai;
    else a += ai;
  }
  cout << (a > b ? "YES" : "NO") << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;
  while(t--)
    run();
}

// AC, greedy.
