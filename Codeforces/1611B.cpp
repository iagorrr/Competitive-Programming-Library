// iagorrr O(1)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll a, b;
        cin >> a >> b;

        cout << min(min(a, b), (a+b)/4) << endl;
    }
    return 0;
}

// Accepted.