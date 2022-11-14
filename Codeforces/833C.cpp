// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<long long> a, int n){
    // iterate reverse and change the value that appears the most
    vector<ll> psum(n+1, 0);
    for(int i = 1; i <=n; ++i){
        psum[i] = psum[i-1] + a[i-1];
    }

    map<ll, ll> ap;
    ll m = 0;
    ll ans = 0;
    for(int i = n; i >= 1; --i){
        ap[psum[i]]++;
        m = ap[m] > ap[psum[i]] ? m : psum[i];
 
        if(a[i-1] == 0){
                ans += ap[m];
            ap.clear();
            m = 0;
        }

   }

    for(int i = 1; i <= n and a[i-1] != 0; ++i)
        if(psum[i] == 0)
            ans++;

    return ans;
}
int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<long long> a(n);
        for(auto &x : a)
            cin >> x;
            
        cout << solve(a, n) << endl;
    }
    return 0;
}
// accepted.
