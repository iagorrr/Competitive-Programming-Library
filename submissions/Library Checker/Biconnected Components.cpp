#include <bits/stdc++.h>
using namespace std;

const int maxn(5'00'000);
int tin[maxn], bcc_cnt, n, timer = 1;
vector<int> g[maxn], nodes[maxn], stck;

int tarjan(int u, int p = -1) {
        int lowu = tin[u] = timer++;
        int son_cnt = 0;
        stck.emplace_back(u);
        for (auto x : g[u]) {
                if (!tin[x]) {
                        son_cnt++;
                        int lowx = tarjan(x, u);
                        lowu = min(lowu, lowx);
                        if (lowx >= tin[u]) {
                                int cur;
                                nodes[bcc_cnt].emplace_back(u);
                                do {
                                        cur = stck.back();
                                        stck.pop_back();
                                        nodes[bcc_cnt].emplace_back(cur);
                                } while (cur != x);
                                bcc_cnt++;
                        }
                } else {
                        lowu = min(lowu, tin[x]);
                }
        }

        if (p == -1 && son_cnt == 0) {
                nodes[bcc_cnt++].emplace_back(u);
        }

        return lowu;
}

void build_bccs() {
        timer = 1;
        stck.clear();
        memset(tin, 0, sizeof(int) * n);
        for (int i = 0; i < n; i++) nodes[i] = {};
        bcc_cnt = 0;

        for (int u = 0; u < n; u++)
                if (!tin[u]) tarjan(u);
}

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int m;
        cin >> n >> m;
        for (int i = 1, u, v; i <= m; i++) {
                cin >> u >> v;
                g[u].emplace_back(v);
                g[v].emplace_back(u);
        }

        build_bccs();

        cout << bcc_cnt << '\n';
        for (int i = 0; i < bcc_cnt; i++) {
                int size = nodes[i].size();
                cout << size;
                for (int j = 0; j < size; j++) {
                        cout << ' ' << nodes[i][j];
                }
                cout << '\n';
        }
        return 0;
}

// AC, biconnected components
