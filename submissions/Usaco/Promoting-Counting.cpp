#include <bits/stdc++.h>
using namespace std;

const int MAXN(1'00'000);

int n;
vector<int> adj[MAXN];
int ps[MAXN];
int ans[MAXN];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

ordered_set<pair<int, int>> pss[MAXN];
int timer = 0;

void dfs(int u) {
  for (auto v : adj[u]) {
    dfs(v);

    if (pss[v].size() > pss[u].size()) {
      pss[u].swap(pss[v]);
    }

    for (auto &[v, t] : pss[v]) {
      pss[u].insert({v, t});
    }
  }

  ans[u] = (int)pss[u].size() -
           pss[u].order_of_key({ps[u], timer + 1});
  pss[u].insert({ps[u], timer++});
}

int main() {
  ifstream in("promote.in");
  ofstream out("promote.out");

  in >> n;

  for (int i = 0; i < n; i++) {
    in >> ps[i];
  }

  for (int i = 1, j; i < n; i++) {
    in >> j;
    j--;
    adj[j].emplace_back(i);
  }

  dfs(0);

  for (int i = 0; i < n; i++) {
    out << ans[i] << "\n";
  }
}

// AC, small to large
