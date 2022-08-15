/*
    iagorrr O(n)
    https://codeforces.com/blog/entry/105419
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(vector <ll> a, ll n){
    ll left = 0;
    while(a[left] <= a[left+1] && left < n) left++;

    ll right = 1;
    while(a[n-right] >= a[n-right+1] && right < n) right++;
    
    return left+right >= n ? "YES" : "NO";
}
int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        vector <ll> a(n+1);
        for(ll i = 1; i <= n; ++i) cin >> a[i];
        cout << solve(a, n) << endl;
    }
    return 0;   
}

// AC.
