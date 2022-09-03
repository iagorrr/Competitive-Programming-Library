// iagorr ;) BFS
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int teste = 1;
void solve(int cidades, int estradas, int inicio, int pedagios, vector<pair<int, int>> grafo_estradas){
    vector<int> grafo[cidades+1];
    for(int i = 0; i < estradas; ++i){
        grafo[grafo_estradas[i].first].push_back(grafo_estradas[i].second);
        grafo[grafo_estradas[i].second].push_back(grafo_estradas[i].first);
    }

    queue <pair<int,int>> bfs;
    map<int, bool> visitados;
    bfs.push({inicio, pedagios});
    while(!bfs.empty()){
        auto [cidade, peda] = bfs.front();
        bfs.pop();
        if(peda == 0) continue;

        for(int i = 0; i < (int)grafo[cidade].size(); ++i){
            if(!visitados[grafo[cidade][i]]){
                visitados[grafo[cidade][i]] = true;
                bfs.push({grafo[cidade][i], peda-1});
            }
        }
    }

    cout << "Teste " << teste << endl;
    for(auto x : visitados)if(x.first != inicio) cout << x.first << " ";
    cout << endl;
    teste++;    
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int cidades, estradas, inicio, pedagios;
    do{
        cin >> cidades >> estradas >> inicio >> pedagios;
        if (!(cidades != 0 && estradas != 0 && inicio != 0 && pedagios != 0)) break;
        vector<pair<int, int>> grafo_estradas(estradas);
        for(int i = 0; i < estradas; ++i) cin >> grafo_estradas[i].first >> grafo_estradas[i].second;

        solve(cidades, estradas, inicio, pedagios, grafo_estradas);
    }while(cidades != 0 && estradas != 0 && inicio != 0 && pedagios != 0);
    
    cin >> cidades >> estradas >> inicio >> pedagios;
}

// Aceito 100/100