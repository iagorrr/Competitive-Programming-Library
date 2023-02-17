// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int32_t main(void){ fastio;
  ll k, d, p, l, m;
  cin >> k >> d >> p >> l >> m;
  
  ll n; cin >> n;
  vll ps(n);
  for(int i = 0; i < n; ++i){
    cin >> ps[i];
  }

  ll e; cin >> e;
  map<ll, char> es;
  for(int i = 0; i < e; ++i){
    ll dia; cin >> dia;
    char evento; cin >> evento;
    es[dia] = evento;
  }
  
  // so simular ?
  int promovido = false;
  ll despacha = k;
  for(int i  = 1; i <= n; ++i){
    if(promovido){
      cout << i << '\n';
      return 0;
    }

    // adiciona antes de começar a trabalahr.
    p += ps[i-1];
    
    // execedido, demiditod.
    if(p > l){
      cout << -i << '\n';
      return 0;
    }
 
    // despacha aqui.
    p = max(0ll, p - min(despacha, m));

    // não teve nem um evento, diminui oquanto despacha.
    if(es[i] == 0){
      despacha = max(0ll, despacha - d);
    }
    else{
      if(es[i] == 'B'){
        despacha = min(m, despacha+k);
      }
      else{
        despacha = max(0ll, despacha - 3*d);
      }
    }
    // zerou, promovido amanha.
    if (p == 0){
      promovido = true;
    }
  }
  if(promovido) cout << n +1 << '\n';
  cout << 0 << '\n';
  return 0;
}
// AC, implementation, simulation
