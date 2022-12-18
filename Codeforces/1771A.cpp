// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
ll solve(map<ll,ll> a, vll b, ll n){
    sort(b.begin(), b.end());
    ll ans = 0;
    ll dif = abs(b.back() - b.front()); // value a need to reach
    if(dif == 0){
        for(int i = 0; i < (int)b.size(); ++i){
            ans += a[b[i]] -1;
        }
    }
    else{
        
        for(int i = 0; i < (int)b.size(); ++i){
            ll d = b[i]+dif;
            ans += a[d];
            d = b[i]-dif;;
            ans += a[d];
        }
    }
    

    return ans;
    
}
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        map<ll,ll> a;
        vector<ll> b(n);
        for(int i = 0 ; i < n; ++i){
            cin >> b[i];
            a[b[i]] ++;
        }

        cout << solve(a, b, n) << '\n';
    }
    return 0;
}
// AC.
