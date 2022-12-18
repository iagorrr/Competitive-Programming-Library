// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
void solve(ll k, ll n){

    vector<ll> ans;
    vector<ll> to_skip;
    ll c = 1;
    ll carried = 0;
    while(c + carried <= (n-k)){
        to_skip.push_back(c);
        carried += c;
        c++;
    }
    reverse(to_skip.begin(), to_skip.end());
    
    ll ts_pos = 0;
    ll i = n;
    while(i >= 1 and ans.size() < k){
        ans.push_back(i);
        if(ts_pos < to_skip.size()){
            i = i-to_skip[ts_pos];
            ++ts_pos;
        }
        --i;
    }

    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << ' ';

    cout << '\n';
}   
int main(){ 
    fastio;

    ll t;
    cin >> t;

    while(t--){
        ll k, n;
        cin >> k >> n;

        solve(k, n);
    }
    return 0;
}

// AC.