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
        list <pair<ll,ll>> qc;
        for(ll i = 0; i < n; ++i){
            ll x;
            cin >> x;

            qc.push_back({x, i+1});
        }
        
        while(qc.size() > 1){
            pair<ll,ll> f = qc.front();
            qc.pop_front();
            pair <ll, ll> s = qc.front();
            qc.pop_front();

            ll remove = min(f.first, s.first);
            f.first -= remove;
            s.first -= remove;

            if(f.first > 0) qc.push_front(f);
            if(s.first > 0) qc.push_front(s);
        }

        cout << qc.front().second << '\n';
    }
    return 0;
}

// Accepted.