
// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

ll solve(ll n){
  queue<pll> q;
  unordered_set<ll> visited;
  q.emplace(n, 0);
  visited.insert(n);
  while(!q.empty()){
    auto [cur, moves] = q.front(); q.pop();
    if(cur == 0) return moves;

    set<ll> digits;
    for(auto c : to_string(cur)) {
      if(c != '0' and not visited.count(cur-(c-'0'))){
        q.emplace(cur-(c-'0'), moves+1);
        visited.insert(cur-(c-'0'));
      }
    }
  }
}
void run(){
  ll n; cin >> n;
  cout << solve(n) << '\n';
   
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, bfs
