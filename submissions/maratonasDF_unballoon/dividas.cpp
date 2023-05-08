// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int32_t main(void){ fastio;
  ll n, m; cin >> n >> m;

  vector<pair<ll,ll>> cheq(n);

  for(int i = 0; i < n; ++i){
    cheq[i].second = i;
    cin >> cheq[i].first;
  }

  vector<pair<ll,ll>> div(m);
  for(int i = 0; i < m; ++i){
    div[i].second = i;
    cin >> div[i].first;
  }
  
  sort(div.begin(), div.end()); sort(cheq.begin(), cheq.end());

  int cans = 0;
  map<ll, ll> ans;

  int j = 0;
  for(int i = 0; i < m; ++i){
    while(j < n and div[i].first > cheq[j].first){
      j++;
    }
    
    if(j < n){
      cans++;
      ans[cheq[j].second+1] = div[i].second+1;
      ++j;
    }
  }

  cout << cans << '\n';
  for(auto [x, y] : ans)
    cout << x << ' ' << y << '\n';
}

// AC.
