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
  ll n; cin >> n;

  map<string, int> qtd;

  for(int i = 0; i < n; ++i){
    string s; ll q;
    cin >> s >> q;
    qtd[s] += q;
  }

  string ans = "Sim";

  cin >> n;
  for(int i = 0; i < n; ++i){
    string s; ll q;
    cin >> s >> q;

    qtd[s] -= q;
    if(qtd[s] < 0) ans = "Nao";
  }

  cout << ans << '\n';
}

// AC.

