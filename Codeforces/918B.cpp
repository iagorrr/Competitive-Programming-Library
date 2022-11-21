// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ll n, c;
    cin >> n >> c;
    
    // ip -> name;
    map<string, string> ipname;

    for(ll i = 0; i < n; ++i){
        string a, b;
        cin >> a >> b;
        ipname[b] = a;
    }

    for(ll i = 0; i < c; ++i){
        string a, b;
        cin >> a >> b;
        string ip = b;
        ip.pop_back();
        cout << a << " " << b << " #" << ipname[ip] << endl;
    }
    return 0;
}

// Accepted.

