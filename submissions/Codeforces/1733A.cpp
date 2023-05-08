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


ll solve(vll a, ll n, ll k){
    vll best(n, 0);

    for(ll i = 1; i <= n; ++i)
        best[i%k] = max(best[i%k], a[i-1]);
    

    ll ans=0;
    for(ll i = 0; i < best.size(); ++i) ans += best[i];
    return ans;
}

int main(void) { 
    sws 
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        ll k;
        cin >> k;

        vll a(n);
        for(auto &x : a) cin >> x;
        

        cout << solve(a, n, k) << endl;
    }
    return 0; 
}

// Accepted.
