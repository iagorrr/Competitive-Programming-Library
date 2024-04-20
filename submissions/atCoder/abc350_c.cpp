#include <bits/stdc++.h>
using namespace std;

auto run() {
        int n;
        cin >> n;

        vector<int> xs(n+1);
        for (int i = 1; i <= n; i++) {
                cin >> xs[i];
        }

        vector<char> vis(n+1);
        vector<vector<int>> cycles;

        for (int i = 1; i <= n; i++) {
                vector<int> cur;
                int p = i;
                while (!vis[p]) {
                        cur.emplace_back(p);
                        vis[p] = 1;
                        p = xs[p];
                }
                if (cur.size()) cycles.emplace_back(cur);
        }

        vector<pair<int,int>> ans;
        for (auto &cs : cycles) {
                if (cs.size() <= 1) continue;
                for (int i = (int)cs.size() - 1; i  >= 1; i--) {
                        ans.emplace_back(cs[i], cs[i-1]);
                }
        }

        cout << ans.size() << '\n';
        for (auto &[a, b] : ans) {

                cout << min(a,b) << ' ' << max(a,b) <<  '\n';
        }
}

int32_t main() {
        run();        
}

// AC, permutations
