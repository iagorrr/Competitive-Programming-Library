// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vll;
typedef long long int ll;
typedef unsigned long long int ull;

#define LOOP(I, S, E) for (ll I = S; I < E; I++)
#define LOOPIN(i, E, V)                                                        \
  for (ll i = 0; i < E; i++) {                                                \
    cin >> V[i];                                                               \
  }
#define LOOPOUT(i, E, V)                                                       \
  for (ll i = 0; i < E; i++) {                                                \
    cout << V[i] << endl;                                                      \
  }
#define SWAP(A, B) A ^= B ^= A ^= B
#define TOBIN(I, b) bitset<b>(I).to_string()
#define endl '\n'
#define sws                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

string tent = "AEOSRINDMTUCLPVGHQBFZJXKWY";
string solve(string s, ll a){
    map<char,bool> e;
    ll te = 0;
    for(auto c : s){ 
      if(!e[c]) te++;
      e[c] = true;
    }

    ll ans = 0;
    for(auto c : tent){
        if(e[c]) ans++;
        else a--;
        if(a == 0) break;
    }

    return ans >= te ? "Sim" : "Nao";
}

int main(void) { 
    sws 
    ll t;
    cin >> t;

    while(t--){
        string s;
        ll a;
        cin >> s >> a;

        cout << solve(s, a) << endl;
    }

    return 0; 
}

// Accepted.

