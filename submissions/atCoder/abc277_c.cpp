// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*====================================================================================================*/
int main(void) {
    int n;
    cin >> n;

    vector<pair<ll, ll>> l;
    for(int i= 0; i < n; ++i){
        ll a, b;
        cin >> a >> b;

        l.emplace_back(min(a,b), max(a,b));
    }

    map<ll,vector<ll>> chega;
    for(auto [x,y] : l){
        chega[x].push_back(y);
        chega[y].push_back(x);
    }

    map<ll, bool> visitados;
    queue<ll> q;
    q.push(1);
    visitados[1] = true;

    ll ans = 1;
    while(!q.empty()){
        ll c = q.front();
        q.pop();

        ans = max(ans, c);

        for(auto v : chega[c]){
            if(!visitados[v]){
                q.push(v);
                visitados[v] = true;
            }
        }
    }
    cout << ans << '\n';
    return 0; 
}
/*====================================================================================================*/
// Accepted.