// iagorrr O(N)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector <ll> a, ll n){
    ll ans = -1;
    ll right;
    for(ll left = 0; left < n; ++left){
        right = left;

        while(right + 1 < n && a[right]*2 >= a[right+1]) right++;

        ans = max(ans, right-left+1);
        left = right;
    }
    return ans;
}
int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    for(auto &x : a) cin >> x;

    cout << solve(a, n) << endl;

    return 0;
}

// AC