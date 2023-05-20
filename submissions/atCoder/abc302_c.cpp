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

bool check(vector<string> vs){
  for(int i = 0; i < vs.size()-1; ++i) {
    int diff = 0;
    for(int j = 0; j < vs[i].size(); ++j){
      diff += (vs[i][j] != vs[i+1][j]);
    }
    if(diff > 1) return false;
  }
  return true;
}
void run(){
  ll n, m; cin >> n >> m;
  vector<string> vs(n);
  for(int i = 0; i < n; ++i){
    string s; cin >> s;
    vs[i] = s;
  }
  sort(all(vs));

  do {

    if(check(vs)){
      cout << "Yes\n";
      return;
    }
  }while(next_permutation(all(vs)));

  cout << "No\n";
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, implementation, permutation
