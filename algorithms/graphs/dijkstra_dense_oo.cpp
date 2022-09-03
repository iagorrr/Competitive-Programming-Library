/*
    Dijkstra implementation for dense graphs.
    O(N^2 +  M)

    iagorrr ;)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

class Graph{
    public :
        int n; // total vertices.
        vector <pii> *adj; // neighbor, and weightto get there.
        bool is_undirected;

        // initialization.
        Graph(int n, bool is_undirected = true){
            this->n = n;
            this->is_undirected = is_undirected;
            this->adj = new vector <pii>[n];
        }

        void add_edge(int u, int v, int w){
            this->adj[u].push_back({v, w}); // neighbor and weight.
            if(this->is_undirected) this->adj[v].push_back({u, w});
        }

        // returns the shortest path between s, and each edge.
        vector <int> dijkstra(int s){
            vector<int> dist; dist.resize(this->n);
            
            bool marked[this->n];

            // initialize the distances with INF, so whatever path will be less, and not visited.
            for(int v = 0; v < this->n; ++v){
                dist[v] = INT_MAX;
                marked[v] = false;
            }
            dist[s] = 0; // initial node.

            // dijkstra itself.
            for(int i = 0; i < this->n; ++i){
                int current = -1;
                
                // shortest distance not marked yet.
                for(int j = 0; j < this->n; ++j){
                    if(marked[j]) continue;
                    if(current == -1 || dist[j] < dist[current]) current = i;
                }   

                // desired shortest path.
                marked[current] = true;
                for(int t = 0; t < (int)this->adj[current].size(); ++t){
                    int neighbor_id = this->adj[current][t].first;
                    int neighbor_weight = this->adj[current][t].second;

                    // update if going from the current distance is better.
                    dist[neighbor_id] = min(dist[neighbor_id], dist[current]+neighbor_weight);
                }
            }

            return dist;
        }
};