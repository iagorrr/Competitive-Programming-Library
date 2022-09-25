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
string solve(string a, string b){
    ll match = 0;
    ll m = a.size();
    ll n = b.size();
    bool prefixo, sufixo, borda, substring;

    prefixo = sufixo = borda = substring = false;
    // prefixo.
    for(ll i = 0; i < n; ++i){
        if(a[i] == b[i]) match++;
    }
    if(match == n) prefixo = true;;

    // sufixo;
    ll pa = m-1;
    ll pb = n-1;
    match = 0;
    while(pb >= 0){
      if(a[pa] == b[pb]) match++;
      pa--;
      pb--;
    }
    if(match == n) sufixo = true;

    if(sufixo and prefixo) return "borda";
    else if (sufixo) return "sufixo";
    else if (prefixo) return "prefixo";
    else return "substring";
}

int main(void) { 
    sws 
    string a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0; 
}

// Accepted.



