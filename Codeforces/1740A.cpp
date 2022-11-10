// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    while(n--){
        ll x;
        cin >> x;
        
        if(x&1)
            cout << 3 << '\n';
        else
            cout << 2 << '\n';
    }    

    return 0;
}
// AC.