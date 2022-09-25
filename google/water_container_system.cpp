#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;

ll casei = 0;
void solve(){
    ll filled = 0;
    ll n, q;
    cin >> n >> q;

    if(n == 1){
        ll x;
        cin >> x;
        cout << "Case #" << casei << ": " << 1 << '\n';
        return;
    }
    

    vector<ll> adj[n+1];
    vector<ll> containers(n+1, 0);
    for(ll i = 0; i < n-1; ++i){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll inputx;
    for(ll i = 0; i < q; ++i){ cin >> inputx;}

    
    bool check[n+1];
    for(ll i = 0; i < n+1; ++i) check[i] = false;
    queue<pair<ll,ll>> bfs;
    bfs.push({1, 1});
    check[1] = true;


    vector<ll> porlevel(n+1, 0);
    while(!bfs.empty()){
        auto current = bfs.front();
        bfs.pop();
       
        porlevel[current.second]++;

        for(auto parentes : adj[current.first]){
            if(!check[parentes]) {
                bfs.push({parentes, current.second+1});
                check[parentes] = true;
            }
        }
    }



    map<ll, ll> litrocheio;
    ll currentlitro = 0;
    for(ll i = 0; i < porlevel.size(); ++i){
        currentlitro += porlevel[i];
        litrocheio[currentlitro] = currentlitro;
    }

    ll ans = 0;
    while(litrocheio[q] == 0){
        q--;
    }
    ans = litrocheio[q];
    cout << "Case #" << casei << ": " << ans << '\n';
}
int main(){
    fast
    ll t;
    cin >> t;
    while(t--){
      ++casei;
      solve();
    }
    return 0;
} 

// Accepted.