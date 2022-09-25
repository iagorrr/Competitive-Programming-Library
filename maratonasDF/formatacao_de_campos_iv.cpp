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


string solve(string cpf){
    if(cpf.size() != 11+3) return "Nao";

    if(cpf[3] != '.' || cpf [7] != '.' || cpf[11] != '-') return "Nao";

    for(int i = 0; i < cpf.size(); ++i){
        if(i != 3 and i != 7 and i != 11 and (cpf[i] > '9' || cpf[i] < '0')) return "Nao";

    }

    return "Sim";

}

int main(void) { 
    sws 
    string cpf;
    cin >> cpf;
    cout << solve(cpf) << endl;
    
    return 0; 
}

// Accepted.


