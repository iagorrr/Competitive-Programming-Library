#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Graph{
    public:
    // total vertices.
    int n;
    
    vector<int> *adj;
    bool is_undirected;
    bool *visited = NULL;// if this node was already visited.

    Graph(int n, bool is_undirected = true){
        this->n = n;
        this->adj = new vector<int>[n];
        this->is_undirected = is_undirected;
    }
    
    void add_edge(int u, int v){
        this->adj[u].push_back(v);
        if (this->is_undirected) this->adj[v].push_back(u);
        
    }

    int count_components(){
        delete this->visited; // 'clear cache'
        this->visited = new bool[this->n]; // new vector of visited with size n.
        int qtd_components = 0; // store the total of components.

        for (int i = 0; i < n; ++i){

            if (!this->visited[i]){
                this->dfs(i); // looks for each vertice that isn't check yet.
                qtd_components++;
            }
        }
        return qtd_components;
    }

    void dfs(int current){
        this->visited[current] = true;
        for (int i = 0; i < this->adj[current].size(); i++){
            int neighbour = this->adj[current][i];

            if (!this->visited[neighbour]) this->dfs(neighbour);
     
        }
    }
};
