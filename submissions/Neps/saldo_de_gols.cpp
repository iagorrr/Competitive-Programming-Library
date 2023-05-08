// iagorrr ;) O(N)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector <long long>;

// kadane algoritmo mas salvando as posições.
void solve(vll a, ll n, ll t){
    ll maxans = LLONG_MIN, currmax = 0, start = 0, end = 0, s =0;

    for(ll i = 0; i < n; ++i){
        currmax += a[i];

        if(currmax >= maxans){
            maxans = currmax;
            start = s;
            end = i;
        }

        if(currmax < 0){
            currmax = 0;
            s = i+1;
        }
    }

    cout << "Teste " << t << endl;
    if(maxans > 0) cout << start+1 << " " << end+1;
    else cout << "nenhum";
    cout << endl;
}

int main(){

    ll n;
    cin >> n;
    ll t = 1;
    while(n != 0){

        vll saldogols(n);
        for(ll i = 0; i < n; ++i){
            ll a, b;
            cin >> a >> b;
            saldogols[i] = a-b;
            
        }
        

        solve(saldogols, n, t);

        cin >> n;
        ++t;
    }
    return 0;
}

// AC.