// iagorrr ;) O(N^2)
#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

// each block of the same color must be at a odd distance at the next one of the same color.
vector <ll> solve(const vector<vector<ll>> v, ll N){
    vector <ll> ans(N+1, 0);

    for(ll i = 1; i <= N; ++i){
        if(!v[i].size()) continue;
        ans[i]++;
        ll c = v[i][0];// first occurence.
        for(ll j = 1; j < v[i].size(); ++j){
            if((c & 1) != (v[i][j] & 1)){
                ans[i]++;
                c = v[i][j];
            }
        }
    }

    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T;
    cin >> T;

    while(T--){
        ll N;
        cin >> N;

        // starting from 1 to avoid confusion.
        vector<vector<ll>> v(N+1);
        for(ll i = 1; i <= N; ++i){
            ll x; cin >> x;
            v[x].push_back(i);
        }

        vector <ll> ans = solve(v, N);
        cout << ans[1];
        for(ll i = 2; i <= N; ++i) cout << " " << ans[i];
        cout << endl;
    }

    return 0;
}


