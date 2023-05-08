// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Looking from the last day to the first we store the lowest price we cound pay in any day before,
    using a priority queue.
*/
ll inline solve(const vector<ll> k, const vector<ll> p, const ll n) {
    ll ans = 0;

    // the price, and the day we could pay for it, ordered as a min heap.
    priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    for(ll i = 0; i < n; ++i) pq.push({p[i], i});

    for(ll i = n-1; i >= 0; --i){
        // remove every price that is after the current we are looking.
        while(pq.top().second > i) pq.pop();
        // cout << pq.top().first << ' ' << k[i] << '\n';
        ans += (pq.top().first * k[i]);
    }
    
    return ans;
}
int main(){
    ll n;
    cin >> n;

    vector<ll> k(n);
    vector<ll> p(n);
    for(ll i = 0; i < n; ++i){
        cin >> k[i] >> p[i];
    }
    
    cout << solve(k, p, n) << '\n';


    return 0;

}

// Accepted
