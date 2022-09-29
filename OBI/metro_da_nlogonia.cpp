// iagorrr ;)
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
const int inf = 1e9+10; // valor infinito (muito grande)

int n;

int paiA[maxn];
int distA[2][maxn];

int paiB[maxn];
int distB[2][maxn];

vector<int> adjA[maxn];
vector<int> adjB[maxn];

// encontra as distâncias de uma ponta do diâmetro para todos os demais vértices
void dfs(int u, int p, int d, int q, vector<int> adj[], int pai[], int dist[2][maxn]){
	dist[q][u] = d;
	pai[u] = p;

	for (auto v: adj[u])
		if (v != p)
			dfs(v, u, d+1, q, adj, pai, dist);
}

// encontra o centro de uma árvore dados os dois vértices da extremidade dos diâmetros.
int find_center(int u, int v, vector<int> adj[], int pai[], int dist[2][maxn]){

	// inicalizar os pais com valores inválidos, e achar as distâncias solicitadas
	dfs(u, -1, 0, 0, adj, pai, dist);
	dfs(v, -1, 0, 1, adj, pai, dist);

	int at = u, mn = inf, c = u;

	// percorro o caminho de u para v.
	while (at){	
		
        // Atualizar o menor 'raio' e o respectivo vértice.
		if (max(dist[0][at], dist[1][at]) < mn){
			mn = max(dist[0][at], dist[1][at]);
            c = at != -1 ? at : c;
        }

		at = pai[at];
	}

	return c;
}

// acha o ponto mais distante de um dado nó.
int pega_extremidade(int s, vector<int> adj[]){

    queue<pair<int, int>> q;
    q.push({s, 0});

    map<int, bool> check;
    check[s] = true;

    int maxdis = 0;
    int maxv = s;

    while(!q.empty()){
        auto [v, d] = q.front(); q.pop();

        if(d > maxdis){
            maxdis = d;
            maxv = v;
        }

        for(auto u : adj[v]){
            if(!check[u]){
                check[u] = true;
                q.push({u, d+1});
            }
        }
    }

    return maxv;
}

int main(){
    int n, m;

    cin >> n >> m;

    int a, b;
    for(int i = 0; i < n-1; ++i){
        cin >> a >> b;
        adjA[a].push_back(b);
        adjA[b].push_back(a);
    }

    for(int i = 0; i < m-1; ++i){
        cin >> a >> b;
        adjB[a].push_back(b);
        adjB[b].push_back(a);
    }

    int ua = pega_extremidade(1, adjA);
    int va = pega_extremidade(ua, adjA);
    int ansa = find_center(ua, va, adjA, paiA, distA);

    int ub = pega_extremidade(1, adjB);
    int vb = pega_extremidade(ub, adjB);
    int ansb = find_center(ub, vb, adjB, paiB, distB);

    cout << ansa << ' ' << ansb << '\n';

    return 0;
}