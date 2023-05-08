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


void solve(ll n, ll x, ll y){
    if(x != 0 and y != 0 ){// must have a loser with 0 wins at the first match.
        cout << -1 << endl;
        return;
    }
    if(x == 0 and y == 0){// must have a winner at the first match.
        cout << -1 << endl;
        return;
    }
    if((n-1)%(max(x, y)) != 0){// the last winner won't wins the much times it needs.
        cout << -1 << endl;
        return;
    }

    // simply give the win to the current until it can, and after that to the next current.
    ll current = 1;
    ll currentwins = 0;
    vll ans;
    for(ll i = 2; i <= n; ++i){
        if(currentwins < max(x, y)){
            ans.push_back(current);
        }
        else {
            current = i;
            currentwins = 0;
            ans.push_back(current);
        }
        currentwins++;
    }
    for(auto i : ans) cout << i << ' ';
    cout << endl;

}

int main(void) { 
    sws 
    ll t;
    cin >> t;

    while(t--){
        ll n, x, y;
        cin >> n >> x >> y;

        solve(n, x, y);
    }
    return 0; 
}

// Accepted.