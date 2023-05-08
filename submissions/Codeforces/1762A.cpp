// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)

ll solve(vector<ll> impar, vector<ll> par){
    ll minpartoimpar = LLONG_MAX;
    ll minimpartopar = LLONG_MAX;

    for(int i = 0; i < (int)impar.size(); ++i){
        ll current = impar[i];
        for(int j = 1; j <= 40; ++j){
            if((ll)(1<<j) > current or (((ll)(1<<j))&current) == 0){
                minimpartopar = min(minimpartopar,(ll)j);
                break;
            }
        }
    }

    // todo: user hackers delight.
    for(int i = 0; i < (int)par.size(); ++i){
        ll current = par[i];
        for(int j = 1; j <= 40; ++j){
            if((ll)(1<<j) > current or (((ll)(1<<j))&current) != 0){
                minpartoimpar = min(minpartoimpar, (ll)j);
                break;
            }
        }
    }

    return min(minpartoimpar, minimpartopar);
}
int main(){ 
    fastio
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> impar;
        vector<ll> par;
        ll sum = 0;
        while(n--){
            ll x;
            cin >> x;

            if(x&1) impar.push_back(x);
            else par.push_back(x);

            sum += x;
        }
        

        if(sum&1) cout << solve(impar, par) << '\n';
        else cout << 0 << '\n';
        
    }


    return 0;
}
