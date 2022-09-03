// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll solve(ll x){
    return x + x/2 * 2 + (x/3) * 2;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}