// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(ll n, ll m, ll k, vector<ll> a){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> lowest;
    set<pair<ll,ll>> used;

    ll sum = 0;
    a.push_back(LLONG_MAX);
    // find the value of the first sum.
    for(int i = 0; i < m; ++i)
        lowest.push({a[i],i});

    for(int i = 0; i < k; ++i){
        sum += lowest.top().first;
        used.insert(lowest.top());
        lowest.pop();
    }
    cout << sum;

    for(int i = 0; i < n-m; ++i){
       // add the right edge value to the possibles to be used.
       lowest.push({a[i+m], i+m});
       
       // remove the values that can't be used anymore
       while(lowest.top().second <= i) lowest.pop();
       
       // if a[i] was used in the sum.
       if(used.count({a[i], i})){
               sum -= a[i];
               sum += lowest.top().first;

               used.erase({a[i], i});

               // after removed take some value to take his place.
               used.insert(lowest.top());
               lowest.pop();
       }
       // remove 'garbage' garbage again.
       while(lowest.top().second <= i) lowest.pop();

       // case this new value needs to take place.
       if(lowest.top().first < used.rbegin()->first){
           sum -= used.rbegin()->first;
           sum += lowest.top().first;
           lowest.push(*used.rbegin());
           used.insert(lowest.top());
           used.erase(*used.rbegin());
           lowest.pop();
       }
       cout << ' ' << sum;
    }

    cout << '\n';
}

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    solve(n, m, k, a);
    return 0;
}

// AC.