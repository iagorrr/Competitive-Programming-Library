#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fastExp(ll a, ll b){
    ll ans = 1;
    ll base = a;

    while(b){
        if(b & 1) ans *= base;
        base *= base;
        b >>= 1; // Move 1 bit to right (decrease)
    }

    return ans;
}

ll fastExpMod(ll a, ll b, ll q = 1000000007){
    ll ans = 1;
    ll base = a;

    while(b){
        if(b & 1) ans = (ans*base) % q;
        base = (base * base) % q;
        b >>= 1;
    }

    return ans;
}

int main(){
    int T;
    cout << "Total test cases: ";
    cin >> T;
    while(T--){
        int base, exp;
        cout << "Enter base and exp: ";
        cin >> base >> exp;
        cout << "Fast Exp: " << fastExp(base, exp) << endl;
        cout << "Fat Ext Mod: " << fastExpMod(base, exp) << endl;
    }

    return 0;
}
