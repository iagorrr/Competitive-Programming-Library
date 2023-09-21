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

vector<string> days {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat",  "Sun"};
ll currdayglobal;
ll currweekdayglobal;
struct dep {
  ll currweekday;
  ll currday;
  ll tosimulate; 
  ll poscycle;
  ll totaldaysdeposited;
  ll simulated;
};

// coloca um depósito pro seu primeiro dia.
void tostart(dep &di) {

  di.currday = currdayglobal-di.totaldaysdeposited;
  di.currweekday = (((currweekdayglobal-di.totaldaysdeposited)%7)+7)%7;
  di.tosimulate = di.totaldaysdeposited;
  di.simulated = 0;
  di.poscycle = 0;
}
// simula um depósito que começa terça ou quinta até ele cair na segunda.
void tofirstcycle(dep &di) {
  
  while (di.currweekday != 0 and di.currweekday != 2 and di.currweekday != 4 and di.tosimulate >= 100) {
    di.tosimulate -= 30;
    di.currday += 30;
    di.currweekday = (di.currweekday+2)%7;
    di.simulated += 30;

    if(di.currweekday == 5) {
      di.tosimulate -= 2;
      di.simulated += 2;
      di.currday += 2;
      di.currweekday = 0;
    }
    else if(di.currweekday == 6) {
      di.tosimulate -= 1;
      di.currday++;
      di.simulated++;
      di.currweekday = 0;
    }
  }

  di.poscycle = 0;
}

// roda o máximo de ciclos completos de 91 que conseguir, começa numa segunda quarta ou sexta.
void runmaxcycle(dep &di) {
  int runned = di.tosimulate/91 * 91;
  // mesmo dia da semana mesmo do ciclo.
  di.simulated += runned;
  di.tosimulate = di.tosimulate%91;
  di.currday += runned; 
}

// simula um depósito até o ciclo dele fechar no dia atual global ou depois.
void simulate(dep &di) {
  // cout << "simulate from : " << days[di.currweekday] << " curday: " << di.currday << '\n' ;
  while(!(di.tosimulate <= 0 and di.poscycle == 0 and di.simulated >= 1)) {
    di.simulated++;
    di.tosimulate--;
    di.poscycle++;
    di.currday++;
    di.currweekday = (di.currweekday+1)%7;
    if(di.poscycle >= 30 and di.currweekday < 5) di.poscycle = 0;
  }

  // cout << days[di.currweekday] << " diday: " << di.currday << '\n';
}
// recebe um depósito qualquer e seta ele pro último dia do ciclo.
void tolast(dep &di){
  if(di.tosimulate <= 100) {
    simulate(di);
    return;
  }

  // se estiver numa terça ou quinta seta pro prox ciclo.
  if(di.currweekday == 1 or di.currweekday == 3)
    tofirstcycle(di);

  if(di.tosimulate <= 100) {
    simulate(di);
    return;
  }
  runmaxcycle(di);
  
  simulate(di);
}
void run(){
  string day; cin >> day;
  ll n; cin >> n;
  vll a(n); INV(a);

  // setar geral pro dia zero individual.
  currdayglobal  = *max_element(all(a));
  currweekdayglobal = find(all(days), day) - days.begin();
  vector<dep> aa(n);
  for(int i = 0; i < n; ++i) {
    aa[i].currday = currdayglobal;
    aa[i].tosimulate = 0;
    aa[i].poscycle = 0; // na real nem da pra saber.
    aa[i].totaldaysdeposited = a[i];
    tostart(aa[i]);
  }


  ll ans = LLONG_MAX;
  for(int i = 0; i < n; ++i) {
    tolast(aa[i]);
    ans = min(ans, aa[i].currday-currdayglobal);
  }
  cout << ans << '\n';
}

int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// implementation.
