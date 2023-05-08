// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    map <ll, bool> unique;
    ll ans= 0;
    for(ll i = 0; i < 5; ++i){
        ll x;
        cin >> x;

        if(!unique[x]) ans++;
        unique[x] = true;
    }
    cout << ans << endl;

    return 0;
}

// Accept.
