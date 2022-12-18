// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        ll p;
        cin >> p;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i = 1; i < n; ++i){
            ll x;
            cin >> x;
            pq.push(x);
        }

        while(!pq.empty()){
            ll c = pq.top(); pq.pop();
            if(c <= p) continue;
            ll mid=1;
            ll l = 1; ll r = c;
            while(r > l+1){
                mid = l + (r-l)/2;
                if(mid+p <= c-mid+1) l = mid;
                else r = mid-1;
            }
            ll ans = l;
            if(r+p <= c-r+1) ans = r;
            p+= ans;
        }

        
        cout << p << '\n';
    }
    return 0;
}

// AC.
