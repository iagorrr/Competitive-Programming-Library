// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

/*====================================================================================================*/
ll N, M;
ll totalsum = 0;


map<ll, ll> total;

map<ll, ll> tira;

map<ll, bool> exist;
map<ll, bool> calculated;
// calculates how much i can remove with x;
ll calc(ll x, ll veidonde){

    // don't have this card.
    if(!exist[x])
        return tira[x];
    
    // have the card and already calculated.
    if(calculated[x])
        return tira[x];

    // have the card but didn't calc.
    tira[x] = x*total[x]; // remove every of it self.
    if((x+1)%M != veidonde) // didn't create a loop.
        tira[x] += calc((x+1)%M, veidonde);
    
    calculated[x] = true;
    return tira[x];
}

int main(void) { 
    cin >> N >> M;

    vector<ll> a;
    for(int i = 0; i < N; ++i){
        ll x;
        cin >> x;
        totalsum += x;

        if(!exist[x])
                a.push_back(x);

        exist[x] = true;    
        total[x]++;
    }

    // calc how many a can remove starting from each x, and reuse the previous calculed values.
    sort(a.begin(), a.end(), greater<int>());

    ll ans = 0;
    for(auto x : a){
        ans = max(ans, calc(x, x));
        // cout << "x : " << ans << '\n';
    }

    cout << totalsum - ans << '\n';
    return 0; 
}
/*====================================================================================================*/

// Accepted.
