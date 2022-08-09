// iagorrr O(NlogN)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    vector <ll> a(n);
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    cout << a[0];
    for(ll i = 1; i < n; ++i) cout << " " << a[i];
    cout << endl;

    return 0;
}

// AC