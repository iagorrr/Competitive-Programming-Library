// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

ll dist(pll a, pll b) {
  return abs(a.first-b.first)*abs(a.first-b.first)+ abs(a.second-b.second)*abs(a.second-b.second);
}

vector<pair<ll,ll>> ppos;
vll ans(2000+5, 0);
void run(){
  ll n, d; cin >> n >> d;
  d *= d;
  ppos.resize(n);

  for(int i = 0; i < n ; ++i) {
    cin >> ppos[i].first >> ppos[i].second;
  }
  
  queue<int> q;
  q.push(0);
  // for(int i = 0; i < n; ++i) q.push(i);
  vll vis(n+1);
  while(!q.empty()) {
    int cur = q.front(); q.pop(); 
    ans[cur] = true;

    for(int i = 0; i < n; ++i) {
      if(i == cur) continue;

      if(dist(ppos[i], ppos[cur]) <= d) {
        if(vis[i]) continue;
        q.push(i);
        vis[i]=true;
      }
    }
  }

  for(int i = 0; i < n; ++i) {
    cout << (ans[i] ? "Yes\n" : "No\n");
  }
   
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, flood fill
