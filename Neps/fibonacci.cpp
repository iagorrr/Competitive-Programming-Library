// iagorrr O(N)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector <ll> dpfib(40, 0);

ll fib(ll n){
    if(dpfib[n]) return dpfib[n];

    dpfib[n] = fib(n-1) + fib(n-2);
    return dpfib[n];
}
int main(){
    ll n;
    dpfib[0] = 1;
    dpfib[1] = 1;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}

// Accepted.
