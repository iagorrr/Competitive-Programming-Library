#include <bits/stdc++.h>

using namespace std;

const int MAXN(2 * 1'00'000);
using pii = pair<int, int>;
using node = pair<pii, pii>;
node seg[MAXN * 4];

int N, Q;
node merge(node &a, node &b) {
  map<int, int> hist;
  hist[a.first.first] += a.first.second;
  hist[a.second.first] += a.second.second;

  hist[b.first.first] += b.first.second;
  hist[b.second.first] += b.second.second;

  auto [m, qm] = *hist.rbegin();
  hist.erase(hist.find(m));
  auto [m2, qm2] = *hist.rbegin();
  return {{m, qm}, {m2, qm2}};
}

void assign(int p, node &k) {
  for (seg[p += N] = k; p >>= 1;) {
    seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
  }
}

node query(int l, int r) {
  node retl, retr;
  for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) retl = merge(retl, seg[l++]);
    if (r & 1) retr = merge(seg[--r], retr);
  }

  return merge(retl, retr);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;

  for (int i = 0, x; i < N; i++) {
    cin >> x;
    node cur;
    cur.first.first = x, cur.first.second = 1;
    assign(i, cur);
  }

  while (Q--) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 1) {
      b--;
      node cur;
      cur.first.first = c;
      cur.first.second = 1;
      assign(b, cur);
    } else {
      b--, c--;
      auto ans = query(b, c);
      cout << ans.second.second << '\n';
    }
  }
}
