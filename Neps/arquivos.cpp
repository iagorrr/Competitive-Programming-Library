#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ll n, b;
    cin >> n >> b;

    vector <ll> a(n);
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = 0;
    ll sum = 0;
    ll c = 0;
    for(ll i = 0; i < n; ++i){
        if(a[i] >= b){
            ans++;
        }
        else if (c < 2){
            
        }
    }
    
    cout << ans << endl;
    return 0;   
}
