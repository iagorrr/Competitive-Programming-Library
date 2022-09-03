/*
    Dijkstra implementation for sparse graphs.
    Looks close to a BFS.
    O(M * logM)

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
            

            // initialize the distances with INF, so whatever path will be less, and not visited.
            bool marked[this->n];
            for(int v = 0; v < this->n; ++v){
                dist[v] = INT_MAX;
                marked[v] = false;
            }
            dist[s] = 0; // initial node.
            
            priority_queue<pii> pq;
            pq.push({0, s}); // weight, edge.
            for(int k  = 0; k < this->n; ++k){
                int current;
                while(true){
                    current = pq.top().second; pq.pop();
                    if(!marked[current]) break;
                }
                
                marked[current] = true;
                for(int i = 0; i  < (int) this->adj[current].size(); ++i){
                    int neighbor_id = this->adj[current][i].first;
                    int neighbor_weight = this->adj[current][i].second;

                    if(dist[neighbor_id] > dist[current]+neighbor_weight){
                        dist[neighbor_id] = dist[current]+neighbor_weight;
                        pq.push({-dist[neighbor_id], neighbor_id});
                    }
                }
            }

            return dist;
        }
};