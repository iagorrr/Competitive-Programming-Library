#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1'00'000;
int N;
vector<int> ADJ[MAXN];
ll CS[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
        cin >> N;

        for (int i = 0, a, b; i < N - 1; i++) {
                cin >> a >> b;
                a--, b--;
                ADJ[a].emplace_back(b);                 
                ADJ[b].emplace_back(a);                 
        }

        for (int i = 0; i < N; i++) {
                cin >> CS[i];
        }

        vector<int> order, dist(N), in(N), out(N);
        auto dfs = [&](auto &&self, int u, int p) -> void {
                if (p != -1) dist[u] = dist[p] + 1;

                in[u] = order.size();
                order.emplace_back(u);

                for (auto v : ADJ[u]) {
                        if (v == p) continue;
                        self(self, v, u);
                }

                out[u] = (int)order.size() - 1;
        };

        dfs(dfs, 0, -1);

        ll ans = 0;
        vector<ll> c2(N);
        for (int i = 0; i < N; i++) c2[i] = CS[order[i]];
        for (int i = 0; i < N; i++) ans += CS[i] * dist[i];

        for (int i = 1; i < N; i++) c2[i] += c2[i - 1];
        
        ll curr_ans = ans;

        auto dfs2 = [&](auto &&self, int u, int p) -> void {
                ll prev = curr_ans;

                cerr << "u: " << u << '\n';
                cerr << "       " << curr_ans << '\n';

                if (u) {
                        ll left = c2[in[u] - 1];
                        ll mid = c2[out[u]] - c2[in[u] - 1];
                        ll right = c2[N - 1] - c2[out[u]];
                        cerr << "       " << left << ' ' << mid << ' ' << right << '\n';
                        curr_ans = curr_ans + left + right - mid;
                        ans = min(curr_ans, ans);
                }

                for (auto v : ADJ[u]) {
                        if (v == p) continue;
                        self(self, v, u);
                }

                curr_ans = prev;
        };
        dfs2(dfs2, 0, -1);

        cout << ans << "\n";
}


// AC, trees
