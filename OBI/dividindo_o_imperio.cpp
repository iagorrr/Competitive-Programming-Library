// iagorrr ;)
/*
    Partindo de um vértice qualquer, iterar por todos os seus 'filhos' para saber quantas vértices
    seria possível chegar tomando aquele caminho, claro, que o pai daquele vértice não deve ser
    incluso na contagem.

    Sabendo que é possível chegar em V vértices seriam alcançados por aquele caminho é fácil
    enxergar que se aquele caminho fosse rompido o império seria em  V e (N-V) vértices, portanto a
    diferença seria de |V - (N-V)|.

    Com isso em mente basta utilizar uma dfs ou bfs para saber quantos cada vértice adjacente ao em
    questão consegue chegar e pegar a menor diferença que for achada.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = 1e5+5;

int n;
vector<ll> adj[MAXN];

ll ans = LLONG_MAX;
int consegue_chegar(int v, int pai){// dfs

    // calcular em quantos vétices v consegue chegar, excluindo o caminho por onde veio (pai).
    ll total = 1;
    for(auto p : adj[v])
        if(p != pai)
            total += consegue_chegar(p, v);
    
    if(abs(n-2*total)< ans) ans = abs(n-2*total);

    return total;
}
int main(){
    cin >> n;

    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;

        // Construiro o vetor de adjacência.
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    consegue_chegar(1, 0);
    cout << ans << '\n';
    return 0;
}