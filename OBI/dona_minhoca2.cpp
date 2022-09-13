// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> adj[50000+4];
ll n;
ll qtda, qtdb;

pair <ll, ll> bfs(ll s, ll N){
    vector<ll> dist(N+1, LLONG_MAX);
    dist[s] = 0;
    qtda = 0;
    queue<ll> q;
    q.push(s);
    ll last = s;


    while(!q.empty()){
        ll current = q.front();
        q.pop();

        last = current;

        for(ll u : adj[current]){
            if(dist[u] == LLONG_MAX){
                dist[u] = dist[current] + 1;
                q.push(u);
            }
        }
    }

    // Verificar quantos possuem a mesma distância máxima para sabermos as possibilidades.
    for(auto x : dist){
        if(x == dist[last]) qtda++;
    }

    return {last, dist[last]};
}

pair <ll, ll> bfs2(ll s, ll N){
    vector<ll> dist(N+1, LLONG_MAX);
    dist[s] = 0;
    qtdb = 0;
    queue<ll> q;
    q.push(s);
    ll last = s;


    while(!q.empty()){
        ll current = q.front();
        q.pop();

        last = current;

        for(ll u : adj[current]){
            if(dist[u] == LLONG_MAX){
                dist[u] = dist[current] + 1;
                q.push(u);
            }
        }
    }

    // Verificar quantos possuem a mesma distância máxima para sabermos as possibilidades.
    for(auto x : dist){
        if(x == dist[last]) qtdb++;
    }

    return {last, dist[last]};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for(ll i = 0; i < n-1; ++i){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto [last1, aaa] = bfs(1, n);
    auto [last, _] = bfs2(last1, n);
    auto [last2, diameter] = bfs(last, n);
    
    
    cout << diameter +1<< endl; 
    cout << qtda*qtdb << endl;
    return 0;
}

// 70/100 WA
