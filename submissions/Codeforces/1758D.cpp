// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(ll n){
    if(n&1){
        vector<ll> ans;
        for(ll i = n/2+1; i <= n; ++i) ans.push_back(i+2);
        for(ll i = n +1; i <= n+n/2; ++i) ans.push_back(i+2);

        ans.front()--;
        ans.back()++;
        ans[ans.size()-2]++;
        
        for(auto a : ans)
            cout << a << ' ';
        cout << '\n';

    }
    else{
        for(int i = 0; i < n/2; ++i) cout << n/2 + i << ' ';
        for(int i = 1; i <= n/2; ++i) cout << n + i << ' ';
        cout << '\n';
    }
}
int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        solve(n);
    }
    return 0;
}

// AC.