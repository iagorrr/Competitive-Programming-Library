// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){


    ll n;
    cin >> n;

    vector<ll> a(n);
    for(auto &x: a)
        cin >> x;

    ll p = 0;

    vector<ll> squaresa(4, 0);
    for(auto x : a){
        squaresa[0]++;

        vector<ll> squaresb(4, 0);
        for(int i = 0; i < 4; ++i){
            if(i+x < 4){
                squaresb[i+x] = squaresa[i];
            }
            else{
                p += squaresa[i];
            }
        }   

        squaresa = squaresb;
    }
    cout << p << '\n';
    return 0;
}

// Accepted.