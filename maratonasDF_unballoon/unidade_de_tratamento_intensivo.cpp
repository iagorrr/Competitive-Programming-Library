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
  cout << n << " horas de tratamento:\n";
  bool foi = false;
  if(n%3 == 0){
    cout << "Troca do soro\n";
    foi = true;
  }
  if(n%5 == 0){
    cout << "Injecao de antibioticos\n";
    foi = true;
  }
  if(n%12 == 0){
    cout << "Reavaliacao\n";
    foi = true;
  }

  if(not foi){
    cout << "Monitoramento dos sinais vitais\n";
  }
}

// AC.

