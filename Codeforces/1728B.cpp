// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> ans;
        ans.push_back(0);
        if(n%2 == 0){        
            for(ll i = n-2; i >= 1; --i) ans.push_back(i);
            ans.push_back(n-1);
            ans.push_back(n);
        }
        else if(n == 5){
            for(ll i = 1; i <= 5; ++i) ans.push_back(i);
        }
        else {
            vector<bool> ok(n+1, true);
            ok[n] = false;
            ok[n/2+1] = false;
            ok[n/2-1] = false;
            ok[1] = false;
            for(ll i = 1; i <= n; ++i){
                if(ok[i]) ans.push_back(i);
            }
            reverse(ans.begin()+1, ans.end());
            ans.push_back(1);
            ans.push_back(n/2-1);
            ans.push_back(n/2+1);
            ans.push_back(n);
        }


        for(int i = 1; i <=n ; ++i) cout << ans[i] << " ";
        cout << endl;   
    }
    return 0;
}

// Accepted.