#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll kadane(vll a, ll n){
    ll ans = a[0];
    ll currmax = a[0];

    for(ll i = 1; i  < n; ++i){
        currmax = max(a[i], currmax + a[i]);
        ans = max(ans, currmax);
    }

    return ans;
}
int main(){
    srand(time(NULL));
    ll n;
    cin >> n;

    vll a(n);
    for(auto &x : a){ x = rand()%10 >= 5 ? rand()%10 : -rand()%10; }
    for(auto x : a) cout << x << " ";
    cout << endl;

    cout << "kadane: " << kadane(a, n) << endl;;
    return 0;
}
