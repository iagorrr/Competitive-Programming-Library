// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

// list implementation of graphs.
class Graph{
    public:
    int n;
    vector<int> *adj;
    bool is_undirected;
    Graph(int n, bool is_undirected = true){
        this->n = n;
        this->adj = new vector<int>[n];
        this->is_undirected = is_undirected;
    }
    
    void add_edge(int u, int v){
        this->adj[u].push_back(v);
        if(this->is_undirected) this->adj[v].push_back(u);
    }

};

