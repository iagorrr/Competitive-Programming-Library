// iagorrr floyd-warshall minmax ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // input e construindo o grafo.
    int s, c;
    cin >> s >> c;
    
    int dist[s+1][s+1];
    memset(dist, 0x1f, sizeof(dist));
    for(int i = 1; i <= s; ++i) dist[i][i] = 0;

    for(int i = 0; i < c; ++i){
        int a, b, d;
        cin >> a >> b >> d;
        
        // ja que foi dito que existe um unico caminho entre os vertices.
        dist[a][b] = d;
        dist[b][a] = d;
    }   

    
    // floyd-warshall relaxing.
    for(int k = 1; k <= s; ++k)
        for(int u = 1; u <= s; ++u)
            for(int v = 1; v <= s; ++v)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

    // achar o minmax, a menor distancia maxima de uma sala pra as demais.
    int minmax = INT_MAX;
    for(int i = 1; i <= s; ++i){
        int curmax = 0;
        for(int j = 1; j <= s; ++j){
            curmax = max(curmax, dist[i][j]);
        }

        minmax = min(minmax, curmax);
    }

    cout << minmax << "\n";
    return 0;
}

// Aceito