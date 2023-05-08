// iagorrr ;) Dijkstra
#include <bits/stdc++.h>
using namespace std;
using iii = tuple<int, int, int>;
const int MAXN { 10'005 }, MAXV { 210 }, oo { 1'000'000'010 } ;

// Works just like a dp. [vertice][price], store the total time taken
int dist[MAXN][MAXV];
bool processed[MAXN][MAXV];

vector<iii> adj[MAXN];

int solve(int tIslands, int maxV, int start, int end){

    // Initialization.
    for (int u = 1; u <= tIslands; u++)
        for (int p = 0; p <= maxV; p++)
            dist[u][p] = oo;

    dist[start][0] = 0;

    // Time, price and vertice
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push(iii(0, 0, start));
    while (not pq.empty()){
        auto [d, c, u] = pq.top();
        pq.pop();

        if (processed[u][c])
            continue;
        processed[u][c] = true;

        // relaxation of edge.
        for (auto [v, t, p] : adj[u]){
            if (c + p <= maxV and d + t < dist[v][c + p]){
                dist[v][c + p] = d + t;
                pq.push(iii(d + t, c + p, v));
            }
        }
    }

    // check through every path which one is the shortest, or 'faster'
    int ans = oo;
    for (int p = 0; p <= maxV; ++p)
        ans = min(ans, dist[end][p]);
    return ans < oo ? ans : -1;
}
int main(){
    ios::sync_with_stdio(false);

    int maxV, tIslands, tConections;
    cin >> maxV >> tIslands >> tConections;
    while (tConections--){
        int start, end, time, price;
        cin >> start >> end >> time >> price;
        adj[start].emplace_back(end, time, price);
        adj[end].emplace_back(start, time, price);
    }

    int start, end;
    cin >> start >> end;
    cout << solve(tIslands, maxV, start, end) << '\n';
    return 0;
}

// Accepted 100/100