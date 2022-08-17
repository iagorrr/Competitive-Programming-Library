// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(vector <ll> a, ll n){
    ll totalone;
    ll total2;
    sort(a.begin(), a.end());

    totalone = 0;
    while(a[totalone] == 1 && totalone < n) totalone++;

    total2 = n-totalone;

    if(totalone&1) return "NO";
    if(total2&1 && totalone ==0) return "NO";

    return "YES";
}
int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <ll> a(n);
        for(auto &x : a) cin >> x;

        cout << solve(a, n) << endl;

    }

    return 0;
}

// AC