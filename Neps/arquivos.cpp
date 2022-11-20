#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector <ll> a, ll b){
    sort(a.begin(), a.end());

    ll ans = 0;
    while(!a.empty() && a.back() == b){a.pop_back(); ans++;}
    // Always sum the highest value with the lowest one.
    ll l = 0;
    ll r = a.size()-1;
    while(l < r){
        if(a[l] + a[r] <= b){
            l++;
            r--;
            ans++;
        }
        else{
            r--;
            ans++;
        }
    }
    if(l == r) ans++;
    return ans;
}
int main(){
    ll n,b;
    cin >> n >> b;
    
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    cout << solve(a, b) << endl;

    return 0;
}

// AC