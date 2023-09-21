#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(), x.end()


int main() {
    fastio
    int r, c, ans = -1;
    cin >> r >> c;

    vector<vector<int>> vs(r, vector<int>(c, 0));
    vector<pair<int, int>> pos(r*c+1, {0, 0});

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> vs[i][j];
            pos[vs[i][j]] = make_pair(i, j);
        }
    }

    unordered_set<int> vis;

    for(int i=1; i<=r*c; i++){
        if (!vis.count(i)){
            priority_queue<int, vector<int>, greater<int>> pq;
            unordered_set<int> vi;
            
            pq.push(i);
            int res = 0;

            while(!pq.empty()){
                res++;
                int val = pq.top();
                vi.insert(val);
                vis.insert(val);
                // cout << val << endl;
                pq.pop();

                auto [x, y] = pos[val];

                if (x > 0 and vs[x-1][y] > val and !vi.count(vs[x-1][y])){
                    pq.push(vs[x-1][y]);
                    vi.insert(vs[x-1][y]);
                    vis.insert(vs[x-1][y]);
                } 
                    
                if (x < r-1 and vs[x+1][y] > val and !vi.count(vs[x+1][y])) {
                    pq.push(vs[x+1][y]);
                    vi.insert(vs[x+1][y]);
                    vis.insert(vs[x+1][y]);
                }
                if (y > 0 and vs[x][y-1] > val and !vi.count(vs[x][y-1])) {
                    pq.push(vs[x][y-1]);
                    vi.insert(vs[x][y-1]);
                    vis.insert(vs[x][y-1]);
                }
                if (y < c-1 and vs[x][y+1] > val and !vi.count(vs[x][y+1])) {
                    pq.push(vs[x][y+1]);
                    vi.insert(vs[x][y+1]);
                    vis.insert(vs[x][y+1]);
                }

            }
            // cout << i << " " << res << endl;
            ans = max(ans, res);
        }
    }

    cout << ans << endl;
}

// AC, dfs, graph.

