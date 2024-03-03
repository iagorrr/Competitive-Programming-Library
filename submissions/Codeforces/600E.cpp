#include <bits/stdc++.h>
using namespace std;

const int maxn(1'00'000);

int n;
int cs[maxn];
long long ans[maxn];
vector<int> adj[maxn];

map<int, int> hist[maxn];
map<int, long long> sumfreq[maxn];

void dfs(int u, int p = -1) {
  sumfreq[u][1] += cs[u];
  hist[u][cs[u]] = 1;

  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);

    if (hist[v].size() > hist[u].size()) {
      hist[u].swap(hist[v]);
      sumfreq[u].swap(sumfreq[v]);
    }

    for (auto &[c, qtd] : hist[v]) {
      if (hist[u].count(c)) {
        sumfreq[u][hist[u][c]] -= c;
      }
      hist[u][c] += qtd;
      sumfreq[u][hist[u][c]] += c;
    }
  }

  ans[u] = sumfreq[u].rbegin()->second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> cs[i];
  }

  for (int i = 1, a, b; i < n; i++) {
    cin >> a >> b;
    a--, b--;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  dfs(0);

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}

// AC, small to large
