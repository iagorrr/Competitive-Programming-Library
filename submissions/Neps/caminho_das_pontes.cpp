// iagorrr ;) Dijkstra
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int pilares, pontes;
    cin >> pilares >> pontes;

    // construir grafo que liga os pilares.
    vector<pair<int, int>> grafo_ponte[pilares+2];
    for(int i = 0; i < pontes; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        grafo_ponte[a].push_back({b, w});
        grafo_ponte[b].push_back({a, w});
    }

    // Dijkstra para achar a 'menor' distancia.
    bool marked[pilares+2];
    vector <int> dist(pilares+2);
    for(int i = 0 ; i < pilares+2; ++i){
        marked[i] = false;
        dist[i] = INT_MAX;
    }

    dist[0] = 0;
    for(int i = 0 ; i < pilares+2; ++i){
        int current = -1;
        for(int j = 0; j < pilares+2; ++j){
            if(marked[j]) continue;
            if(current == -1 || dist[j] <= dist[current]) current = j;
        }

        marked[current] = true;
        for(int j = 0 ; j < (int) grafo_ponte[current].size(); ++j){
            int neighbor_id = grafo_ponte[current][j].first;
            int neighbor_weight = grafo_ponte[current][j].second;
            dist[neighbor_id] = min(dist[neighbor_id], dist[current] + neighbor_weight);
        }
    }
    cout << dist[pilares+1] << endl;;
    return 0;
}

// AC 100/100.