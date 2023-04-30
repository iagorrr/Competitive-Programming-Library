// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define INV(aaaa) for(auto &aaaa : aaaaaa) cin >> aaaaa;

#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void run() {
  ll n, k;
  cin >> n >> k;
  vector<set<ll>> bycolor(k+1);
  vll sorted;
  vector<pair<ll, ll>> order(n);
  for(int i = 0; i < n; ++i) {
    ll c, v;
    cin >> v >> c;
    sorted.push_back(v);
    order[i] = {v, c};
    bycolor[c].insert(v);
  }
  sort(all(sorted));

  for(int i = 0; i < n; ++i) {
    if(! bycolor[order[i].second].count(sorted[i])){
      cout << "N\n";
      return;
    }
  }

  cout << "Y\n";
}
int32_t main() {
  // fastio;
  int t; t =1 ;
  // cin >> t;

  while(t--){
    run();
  }
}
// AC, implementation.
