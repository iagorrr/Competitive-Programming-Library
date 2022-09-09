// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;

    vector<ll> adj[n+1];
    for(ll i = 0; i < n-1; ++i){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Achar o ponto mais distante de 1 usando dfs.
    map<ll, bool> visited;
    queue <pair<ll, ll>> bfs;
    bfs.push({1, 0});
    visited[1] = true;
    ll maxdis = 0;
    ll maxvertice = 1;
    ll totalmaxdis = 0;

    while(!bfs.empty()){
        // pegar o primeiro elemento e marcar como visitado.
        pair<ll, ll> current = bfs.front();
        // cout << "checando: " << current.first;
        bfs.pop();
        visited[current.first] = true;

        // Verificar se essa é a maior distanica que já chegamos do nó 1.
        if(current.second > maxdis){
            // cout << " max !";
            maxdis = current.second;
            maxvertice = current.first;
            totalmaxdis = 1;
        }
        else if(current.second == maxdis){
            totalmaxdis++;
        }

        // Adicionar os que ainda não foram visitados na bfs.
        for(ll i = 0; i < adj[current.first].size(); ++i){
            if(!visited[adj[current.first][i]]){
                bfs.push({adj[current.first][i], current.second+1});
            }
        }
        // cout << endl;
    }

    // cout << maxvertice << " " << maxdis << " " << totalmaxdis << endl;

    // Do vertice mais distante da origem, achar  qual é o mais distante dele.
    map<ll, bool> visited2;
    queue <pair<ll, ll>> bfs2;
    ll maxdist2 = 0;
    ll qtdmaxdist2 = 0;
    bfs2.push({maxvertice, 0});
    visited2[maxvertice] = true;
    while(!bfs2.empty()){
        pair<ll,ll> current = bfs2.front();
        bfs2.pop();
        visited2[current.first] = true;

        if(current.second > maxdist2){
            maxdist2 = current.second;
            qtdmaxdist2 = 1;
        }
        else if(current.second == maxdist2) qtdmaxdist2++;

        for(ll i = 0; i < adj[current.first].size(); ++i){
            if(!visited2[adj[current.first][i]]){
                bfs2.push({adj[current.first][i], current.second+1});
            }
        }
    }
    // cout << maxdist2 << " " << qtdmaxdist2 << endl;
    cout << maxdist2+1ll << endl;
    cout << qtdmaxdist2*totalmaxdis << endl;
    return 0;
}

// 50/100 WA