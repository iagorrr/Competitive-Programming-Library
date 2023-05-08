// iagorrr ;) O(n)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    vector <ll> a(n+1);
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    ll k;
    cin >> k;

    ll l = 1;
    ll r = n;
    while(l < r){
        if(a[l] + a[r] == k) break;
        else if(a[l] + a[r] > k) r--;
        else l++;
    }
    cout << a[l] << " " << a[r] << endl;
    return 0;
}

// AC